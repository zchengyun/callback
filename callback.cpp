#include <cstdio>
#include <cstring>
#include <iostream>

typedef int (callBack)(const void* buffer, size_t size, char* p_out);

//根据函数实现决定什么时候执行consume_bytes
void callFunc1(callBack* consume_bytes, char* p_out) {
	std::cout<<"world1\n";
	const void* buffer = NULL;
	consume_bytes(buffer, 0, p_out); 
}

void callFunc2(callBack* consume_bytes, char* p_out) {
	const void* buffer = NULL;
	consume_bytes(buffer, 0, p_out);
	std::cout << "world2\n";
}

int callBackFunc(const void* buffer, size_t size, char* p_out) {
	std::cout<<"callBackFunc\n";
	memset(p_out, 0x00, sizeof(char) * 100); //复制0x00到p_out 所指向的字符串的前 sizeof(char) * 100个字符。将所有的东西都扔进指定的数组
	return 1;
}

int main(int argc, char* args[]) {
	char p_out[100];
	callFunc1(callBackFunc, p_out);
	callFunc2(callBackFunc, p_out);
	std::cout<<p_out<<"\n";
	return 0;
}
