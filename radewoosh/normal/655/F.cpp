#include <bits/stdc++.h>
using namespace std;

int n, k, q;

int sito[1000007];

long long ile[1000007];
long long mod=1000000007;

vector < pair <int,int> > roz;

vector <int> dzie[1000007];

long long sil[1000007];
long long odw[1000007];

int zwa[1000007];
int parz[1000007];
long long magia[1000007];

long long wyn;

int x, y;

int ilebiere[100007];

void rozl(int v)
{
    roz.clear();
    while(v>1)
    {
        if (roz.empty() || roz.back().first!=sito[v])
        roz.push_back(make_pair(sito[v], 0));
        roz.back().second++;
        v/=sito[v];
    }
}

long long dziel(long long a, long long b)
{
    long long wyk=mod-2;
    while(wyk)
    {
        if (wyk&1)
        {
            a*=b;
            a%=mod;
        }
        b*=b;
        b%=mod;
        wyk>>=1;
    }
    return a;
}

long long kom(long long a, long long b)
{
    if (b<0 || b>a)
    return 0;
    return (sil[a]*((odw[b]*odw[a-b])%mod))%mod;
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
        if (sito[i]==i && i<=1000)
        {
            for (int j=i*i; j<=1000000; j+=i*i)
            {
                zwa[j]=1;
            }
        }
    }
    for (int i=1; i<=1000000; i++)
    {
        rozl(i);
        parz[i]=(roz.size()&1);
    }
    for (int i=1; i<=1000000; i++)
    {
        for (int j=i; j<=1000000; j+=i)
        {
            dzie[j].push_back(i);
            if (!zwa[j/i])
            {
                if (!parz[j/i])
                {
                    magia[j]+=i;
                }
                else
                {
                    magia[j]-=i;
                }
            }
        }
        magia[i]%=mod;
        magia[i]+=mod;
        magia[i]%=mod;
    }
    sil[0]=1;
    odw[0]=1;
    for (int i=1; i<=1000000; i++)
    {
        sil[i]=(sil[i-1]*i)%mod;
    }
    odw[1000000]=dziel(1, sil[1000000]);
    for (int i=999999; i; i--)
    {
        odw[i]=(odw[i+1]*(i+1))%mod;
    }
    //printf("juz\n");
    scanf("%d%d%d", &n, &k, &q);
    for (int i=1; i<=n+q; i++)
    {
        scanf("%d", &x);
        for (int j=0; j<dzie[x].size(); j++)
        {
            y=dzie[x][j];
            //printf("mam %d\n", y);
            wyn+=magia[y]*kom(ile[y], k-1);
            wyn%=mod;
            //printf("wyn to %lld    mimo %lld %lld\n", wyn, magia[y], kom(ile[y], k-1));
            ile[y]++;
        }
        if (i>n)
        printf("%lld\n", wyn);
    }
    return 0;
}