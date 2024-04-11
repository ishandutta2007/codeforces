#include<stdio.h>
char in[10000];
int main(){
    int c4=0,c7=0,i;
    scanf("%s",in);
    for(i=0;in[i];i++){
    if(in[i]=='4')c4++;
    else if(in[i]=='7')c7++;
    }
    if(c4==0&&c7==0)puts("-1");
    else if(c4>=c7)puts("4");
    else puts("7");
}