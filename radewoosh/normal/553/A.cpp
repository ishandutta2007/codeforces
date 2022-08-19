#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int tab[1007];

long long mod=1000000007;
long long dyn[1007][1007];

int sum;

long long sil[1007];

long long wyn;

long long dziel(long long a, long long b)
{
    long long x=1;
    long long roz=mod-2;

    while(roz)
    {
        if (roz&1)
        {
            x*=b;
            x%=mod;
        }
        b*=b;
        b%=mod;
        roz>>=1;
    }

    return (x*a)%mod;
}

int main()
{
    sil[0]=1;
    for (int i=1; i<=1000; i++)
    {
        sil[i]=sil[i-1]*i;
        sil[i]%=mod;
    }
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
    }
    reverse(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        tab[i]+=tab[i-1];
    }
    sum=tab[n];
    dyn[0][0]=1;
    for (int i=0; i<=sum; i++)
    {
        for (int j=0; j<=n; j++)
        {
            dyn[i+1][j+1]+=dyn[i][j]*(tab[j+1]-tab[j]);
            dyn[i+1][j+1]%=mod;


            dyn[i+1][j]+=dyn[i][j]*max(0,tab[j]-i);
            dyn[i+1][j]%=mod;
            //printf("%lld ", dyn[i][j]);
        }
        //printf("\n");
    }
    wyn=dyn[sum][n];
    for (int i=1; i<=n; i++)
    {
        wyn=dziel(wyn, sil[tab[i]-tab[i-1]]);
        //printf("%lld\n", wyn);
    }

    printf("%lld\n", wyn%mod);
    return 0;
}