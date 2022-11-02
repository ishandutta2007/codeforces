#include<stdio.h>
long long in[30];
int main(){
    int n;
    long long a;
    scanf("%d",&n);
    while(n--){
	scanf("%I64d",&a);
	in[a+10]++;
    }
    a=0;
    for(n=0;n<10;n++)a+=in[n]*in[20-n];
    a+=in[10]*(in[10]-1)/2;
    printf("%I64d\n",a);
}