#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
char s[1000005];
char t[1000005];
int main()
{
    scanf("%s",s);
    int n=strlen(s),d=n;
    for(int i=0;i<n;i++)
        if(s[i]=='.')d=i;
    for(int i=n-1;i>=d;i--)
    {
        if(s[i]=='0')n--;
        else break;
    }
    int tot=0,pre=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]!='0')pre=1;
        if(pre)s[tot++]=s[i];
    }
    n=tot,d=n;
    for(int i=0;i<n;i++)
        if(s[i]=='.')d=i;
    int m=(pre=0);
    for(int i=0;i<n;i++)
    {
        if(s[i]!='0' && s[i]!='.')pre=1;
        if(pre && s[i]!='.')t[m++]=s[i];
        if(!pre && s[i]!='.')d--;
    }
    for(int i=m-1;i>=0;i--)
    {
        if(t[i]=='0')m--;
        else break;
    }
    printf("%c",t[0]);
    if(m>1)
    {
        printf(".");
        for(int i=1;i<m;i++)
            printf("%c",t[i]);
    }
    if(d!=1)printf("E%d",d-1);
    return 0;
}