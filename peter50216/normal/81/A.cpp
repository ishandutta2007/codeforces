#include<stdio.h>
char stk[200010];
int sc=0;
char in[200010];
int main(){
    scanf("%s",in);
    for(int i=0;in[i];i++){
	if(sc&&stk[sc-1]==in[i])sc--;
	else stk[sc++]=in[i];
    }
    stk[sc]=0;
    puts(stk);
}