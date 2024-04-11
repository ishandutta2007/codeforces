#include "stdio.h"
int n;
char str[100005];
void print(char cur , int len){
	if(cur == 'a' || cur == 'i' || cur == 'u' || cur == 'y'){
		printf("%c" , cur);
	}
	else if(cur == 'e' || cur == 'o'){
		if(len == 2){
			printf("%c%c" , cur , cur);
		}
		else{
			printf("%c" , cur);
		}
	}
	else{
		while(len--){
			printf("%c" , cur);
		}
	}
}
int main(){
	scanf("%d" , &n);
	scanf("%s" , str);
	char cur = str[0];
	int len = 1;
	for(int i = 1 ; i < n ; ++i){
		if(str[i] == cur){
			++len;
		}
		else{
			print(cur , len);
			len = 1;
			cur = str[i];
		}
	}
	print(cur , len);
}