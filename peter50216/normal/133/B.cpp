#include<stdio.h>
char in[110];
char c[]="><+-.,[]";
int main(){
    scanf("%s",in);
    int i,j,a=0;
    for(i=0;in[i];i++){
	for(j=0;c[j]!=in[i];j++);
	a=(a*16+8+j)%1000003;
    }
    printf("%d\n",a);
}