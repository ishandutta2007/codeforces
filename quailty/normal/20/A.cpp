#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[105];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    while(n>1 && s[n-1]=='/')n--;
    for(int i=0;i<n;i++)
        if(i==0 || s[i]!=s[i-1] || s[i-1]!='/')
           printf("%c",s[i]);
    return 0;
}