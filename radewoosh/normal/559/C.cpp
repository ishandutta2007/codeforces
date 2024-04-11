#include <cstdio>
#include <algorithm>
using namespace std;

int h, w, n;

pair <int,int> tab[2007];
long long dp[2007];

long long mod=1000000007;

long long sil[500007];
long long odw[500007];

long long dziel(long long a, long long b)
{
    long long x=mod-2;
    while (x)
    {
        if (x&1)
        {
            a*=b;
            a%=mod;
        }
        b*=b;
        b%=mod;
        x>>=1;
    }
    return a%mod;
}

long long kom(int a, int b)
{
    if (a<0 || b<0)
    return 0;
    return (sil[a+b]*((odw[a]*odw[b])%mod))%mod;
}

int main()
{
    sil[0]=1;
    odw[0]=1;
    for (int i=1; i<=500000; i++)
    {
        sil[i]=(sil[i-1]*i)%mod;
        odw[i]=dziel(1, sil[i]);
    }
    scanf("%d%d%d", &h, &w, &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d%d", &tab[i].first, &tab[i].second);
    }
    n++;
    tab[n]=make_pair(1, 1);
    n++;
    tab[n]=make_pair(h, w);
    sort(tab+1, tab+1+n);
    dp[1]=1;
    for (int i=2; i<=n; i++)
    {
        dp[i]=kom(tab[i].first-1, tab[i].second-1);
        for (int j=2; j<i; j++)
        {
            dp[i]+=mod-(dp[j]*kom(tab[i].first-tab[j].first, tab[i].second-tab[j].second))%mod;
            dp[i]%=mod;
        }
    }
    printf("%lld", dp[n]);
    return 0;
}