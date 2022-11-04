#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    char s[105],t[105];
    scanf("%s%s",s,t);
    int n=strlen(s);
    bool flag=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]!=t[n-1-i])flag=0;
    }
    if(flag)printf("YES\n");
    else printf("NO\n");
    return 0;
}