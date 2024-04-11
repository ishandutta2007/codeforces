#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
int a[MAXN];
int main()
{
    int n,k,cnt=0;
    scanf("%d%d",&n,&k);
    n++;
    char s[15];
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        if(*s=='?')a[i]=INF;
        else
        {
            int p=0;
            if(*s=='-')p=1;
            for(int j=p;s[j];j++)
                a[i]=a[i]*10+s[j]-'0';
            if(p)a[i]=-a[i];
            cnt++;
        }
    }
    if(k==0)
    {
        if(a[0]<INF)printf("%s\n",(a[0] ? "No" : "Yes"));
        else printf("%s\n",(cnt&1 ? "Yes" : "No"));
    }
    else
    {
        if(cnt<n)printf("%s\n",(n&1 ? "No" : "Yes"));
        else
        {
            long long now=0;
            for(int i=n-1;i>=0 && abs(now)<1e14;i--)
                now=1LL*now*k+a[i];
            printf("%s\n",(now ? "No" : "Yes"));
        }
    }
    return 0;
}