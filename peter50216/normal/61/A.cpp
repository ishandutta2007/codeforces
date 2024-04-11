#include<stdio.h>
char a[110],b[110];
int main(){
    int i;
    scanf("%s%s",a,b);
    for(i=0;a[i];i++)printf("%c",((a[i]-'0')^(b[i]-'0'))+'0');puts("");
}