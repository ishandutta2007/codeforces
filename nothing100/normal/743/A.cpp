#include<string>
#include<cstring>
#include<cstdio>
#include<iostream>
int n,a,b;
char s[100010];
int main(){
    scanf("%d%d%d\n",&n,&a,&b);
    scanf("%s\n",s);
    if (s[a-1]!=s[b-1]) printf("1\n");
    else printf("0\n");
}