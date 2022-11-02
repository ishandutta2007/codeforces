#include<stdio.h>
#include<string.h>
char in[1000];
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
	scanf("%s",in);
	if(strlen(in)<=10)puts(in);
	else printf("%c%d%c\n",in[0],strlen(in)-2,in[strlen(in)-1]);
    }
}