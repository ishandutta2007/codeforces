#include <bits/stdc++.h>
using namespace std;

int n;

int x;

long long tab[1000007];

long long mod=1000000007;

long long pre[1000007];
long long suf[1000007];

long long wyn=1;

long long v;

long long pot(long long a, long long b)
{
    long long ret=1;
    while(b)
    {
        if (b&1)
        {
            ret*=a;
            ret%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &x);
        tab[x]++;
    }
    n=200000;
    pre[0]=1;
    suf[n+1]=1;
    for (int i=1; i<=n; i++)
    {
        pre[i]=(pre[i-1]*(tab[i]+1))%(mod-1);
    }
    for (int i=n; i; i--)
    {
        suf[i]=(suf[i+1]*(tab[i]+1))%(mod-1);
    }
    for (int i=1; i<=n; i++)
    {
        v=1;
        for (int j=1; j<=tab[i]; j++)
        {
            v*=i;
            v%=mod;
            wyn*=pot(v, pre[i-1]*suf[i+1]);
            wyn%=mod;
        }
    }
    printf("%lld\n", wyn);
    return 0;
}