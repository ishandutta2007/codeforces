#include<stdio.h>
char in[100];
int main(){
    scanf("%s",in);
    int i,a=0;
    for(i=0;in[i];i++)if(in[i]=='4'||in[i]=='7')a++;
    puts((a==4||a==7)?"YES":"NO");
}