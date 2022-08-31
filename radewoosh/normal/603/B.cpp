#include <bits/stdc++.h>
using namespace std;

int p, k;

int bylo[1000007];
int ile[1000007];

int kied[1000007];

int dlu[1000007];

int tak[1000007];

long long wyn=1;
long long mod=1000000007;

int dfs(long long v, int d)
{
    bylo[v]=1;
    if (bylo[(v*k)%p])
    {
        dlu[d]+=d;
        return d;
    }
    return dfs((v*k)%p, d+1);
}

int main()
{
    scanf("%d%d", &p, &k);
    if (!k)
    {
        for (int i=1; i<p; i++)
        {
            wyn*=p;
            wyn%=mod;
        }
        printf("%lld\n", wyn);
        return 0;
    }
    for (int i=0; i<p; i++)
    {
        if (!bylo[i])
        {
            tak[i]=1;
            ile[i]=dfs(i, 1);
        }
    }
    for (int i=p-1; i; i--)
    {
        for (int j=2*i; j<p; j+=i)
        {
            dlu[j]+=dlu[i];
        }
    }
    for (int i=0; i<p; i++)
    {
        if (tak[i])
        {
            wyn*=dlu[ile[i]];
            wyn%=mod;
        }
    }
    printf("%lld\n", wyn);
    return 0;
}