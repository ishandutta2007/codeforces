#include <bits/stdc++.h>
using namespace std;

int q;
int qw;

int n, m;
int typ;

char wcz[1000007];

vector <int> kto[1000007];

pair <int,int> zap[1000007];
long long wyn[1000007];

long long mod=1000000007;

long long sil[1000007];
long long osil[1000007];

long long dp[1000007];

long long p25[1000007];

void bierz()
{
    n=0;
    scanf("%s", wcz);
    for (int i=0; wcz[i]; i++)
    n++;
}

long long pot(long long a, long long b)
{
    long long ret=1;
    a%=mod;
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

long long dziel(long long a, long long b)
{
    a%=mod;
    b%=mod;
    return (a*pot(b, mod-2))%mod;
}

long long kom(long long a, long long b)
{
    if (a<0 || b<0 || b>a)
    return 0;
    return (sil[a]*((osil[b]*osil[a-b])%mod))%mod;
}

int main()
{
    sil[0]=1;
    osil[0]=1;
    p25[0]=1;
    for (int i=1; i<=100000; i++)
    {
        sil[i]=(sil[i-1]*i)%mod;
        p25[i]=(p25[i-1]*25)%mod;
    }
    osil[100000]=dziel(1, sil[100000]);
    for (int i=100000-1; i; i--)
    {
        osil[i]=(osil[i+1]*(i+1))%mod;
    }
    scanf("%d", &q);
    bierz();
    while(q--)
    {
        scanf("%d", &typ);
        if (typ==1)
        {
            bierz();
        }
        else
        {
            scanf("%d", &m);
            qw++;
            zap[qw]=make_pair(n, m);
            kto[n].push_back(qw);
        }
    }
    for (int i=1; i<=100000; i++)
    {
        if (kto[i].empty())
        continue;
        for (int j=0; j<=100000; j++)
        dp[j]=0;
        for (int j=i; j<=100000; j++)
        {
            dp[j]=kom(j, i)-kom(j-1, i)+mod;
            dp[j]%=mod;
            dp[j]*=p25[j-i];
            dp[j]%=mod;
            dp[j]+=dp[j-1]*26;
            dp[j]%=mod;
        }
        for (int j=0; j<kto[i].size(); j++)
        {
            wyn[kto[i][j]]=dp[zap[kto[i][j]].second];
        }
    }
    for (int i=1; i<=qw; i++)
    printf("%lld\n", wyn[i]);
    return 0;
}