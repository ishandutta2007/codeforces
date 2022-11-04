#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
bool good[MAXN];
char s[MAXN],t[MAXN];
int main()
{
    scanf("%s",s);
    for(int i=0;s[i];i++)
        good[s[i]]=1;
    scanf("%s",s);
    int n=strlen(s),q,loc=-1;
    for(int i=0;i<n;i++)
        if(s[i]=='*')loc=i;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%s",t);
        int m=strlen(t);
        if(loc<0)
        {
            if(n!=m)
            {
                printf("NO\n");
                continue;
            }
            bool isok=1;
            for(int i=0;i<n;i++)
                isok&=(s[i]==t[i] || (s[i]=='?' && good[t[i]]));
            printf("%s\n",(isok ? "YES" : "NO"));
        }
        else
        {
            if(n-1>m)
            {
                printf("NO\n");
                continue;
            }
            bool isok=1;
            int pre=loc,suf=n-1-loc;
            for(int i=0;i<pre;i++)
                isok&=(s[i]==t[i] || (s[i]=='?' && good[t[i]]));
            for(int i=0;i<suf;i++)
                isok&=(s[n-1-i]==t[m-1-i] || (s[n-1-i]=='?' && good[t[m-1-i]]));
            for(int i=pre;i<=m-1-suf;i++)
                isok&=(!good[t[i]]);
            printf("%s\n",(isok ? "YES" : "NO"));
        }
    }
    return 0;
}