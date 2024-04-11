#include<stdio.h>
char in[1000];
int main(){
    scanf("%s",in);
    int i,c=1,f=0;
    for(i=1;in[i];i++){
    if(in[i]==in[i-1])c++;
    else c=1;
    if(c>=7)f=1;
    }
    puts(f?"YES":"NO");
}