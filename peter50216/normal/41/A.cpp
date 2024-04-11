#include<stdio.h>
#include<string.h>
char a[10000],b[10000];
int main(){
    scanf("%s%s",a,b);
    bool f=1;
    int i;
    if(strlen(a)!=strlen(b))f=0;
    else{
    for(i=0;i<strlen(a);i++)if(a[strlen(a)-i-1]!=b[i])break;
    if(i<strlen(a))f=0;
    }
    puts(f?"YES":"NO");
}