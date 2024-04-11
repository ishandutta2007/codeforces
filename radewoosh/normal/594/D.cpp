#include <bits/stdc++.h>
using namespace std;

int n;

int sito[1000007];
vector <int> roz[1000007];
vector < pair <int,int> > roz2[1000007];
long long odw[1000007];

long long sil[1000007];
long long osil[1000007];

long long tab[1000007];

long long mod=1000000007;

int q;
pair <int,int> zap[1000007];
vector <int> jak[1000007];
long long wyn[1000007];

int ost[1000007];

int n1;
long long drzewo[1000007];

long long x, y;

int potenga(int v)
{
    for (int i=1; 1; i<<=1)
    {
        if (i>=v)
        {
            return i;
        }
    }
}

long long dziel(long long a)
{
    long long ret=1;
    long long wyk=mod-2;
    while(wyk)
    {
        if (wyk&1)
        {
            ret*=a;
            ret%=mod;
        }
        a*=a;
        a%=mod;
        wyk>>=1;
    }
    return ret%mod;
}

void start(int v, int a, int b)
{
    drzewo[v]=1;
    if (a==b)
    return;
    start((v<<1), a, (a+b)>>1);
    start((v<<1)^1, (a+b+2)>>1, b);
}

void pisz(int v, long long war)
{
    v+=n1-1;
    while(v)
    {
        drzewo[v]*=war;
        drzewo[v]%=mod;
        v>>=1;
    }
}

long long czyt(int v, int a, int b, int graa, int grab)
{
    if (a>=graa && b<=grab)
    {
        return drzewo[v];
    }
    if (a>grab || b<graa)
    {
        return 1;
    }
    return ( czyt((v<<1), a, (a+b)>>1, graa, grab)*czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab) )%mod;
}

int main()
{
    for (int i=2; i<=1000000; i++)
    {
        if (!sito[i])
        {
            for (int j=i; j<=1000000; j+=i)
            {
                sito[j]=i;
            }
        }

        roz[i]=roz[i/sito[i]];
        roz[i].push_back(sito[i]);


        for (int j=0; j<roz[i].size(); j++)
        {
            if (!j || roz[i][j]!=roz[i][j-1])
            {
                roz2[i].push_back(make_pair(roz[i][j], roz[i][j]));
            }
            else
            {
                roz2[i].back().second*=roz[i][j];
            }
        }
    }
    sil[0]=1;
    for (int i=1; i<=1000000; i++)
    {
        sil[i]=(sil[i-1]*i)%mod;
    }
    osil[1000000]=dziel(sil[1000000]);
    for (int i=999999; i; i--)
    {
        osil[i]=(osil[i+1]*(i+1))%mod;
    }
    for (int i=1; i<=1000000; i++)
    {
        odw[i]=(osil[i]*sil[i-1])%mod;
    }

    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
    }
    scanf("%d", &q);
    for (int i=1; i<=q; i++)
    {
        scanf("%d%d", &zap[i].first, &zap[i].second);
        jak[zap[i].second].push_back(i);
    }
    n1=potenga(n+3);
    start(1, 1, n1);
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<roz2[tab[i]].size(); j++)
        {
            x=roz2[tab[i]][j].first;
            y=roz2[tab[i]][j].second;
            if (ost[x])
            {
                pisz(ost[x], (odw[x-1]*x)%mod);
            }
            pisz(i, ((x-1)*(y/x))%mod);
            ost[x]=i;
        }
        for (int j=0; j<jak[i].size(); j++)
        {
            x=jak[i][j];
            wyn[x]=czyt(1, 1, n1, zap[x].first, zap[x].second);
        }
    }
    for (int i=1; i<=q; i++)
    {
        printf("%lld\n", wyn[i]);
    }
    return 0;
}