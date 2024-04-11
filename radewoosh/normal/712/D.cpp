#include <bits/stdc++.h>
using namespace std;

int a, b, k, t;

long long d=300000;

long long dps[1000007];
long long dpn[1000007];

long long mod=1000000007;

long long wyn;

int main()
{
    scanf("%d%d%d%d", &a, &b, &k, &t);
    dpn[a-b+d]=1;
    t*=2;
    while(t--)
    {
        for (int i=0; i<=2*d; i++)
        {
            dps[i]=dpn[i];
            dpn[i]=0;
        }
        for (int i=-d; i<=d; i++)
        {
            if (!dps[i+d])
                continue;
            dpn[i-k+d]+=dps[i+d];
            if (dpn[i-k+d]>=mod)
                dpn[i-k+d]-=mod;

            dpn[i+k+1+d]+=mod-dps[i+d];
            if (dpn[i+k+1+d]>=mod)
                dpn[i+k+1+d]-=mod;
        }
        for (int i=-d+1; i<=d; i++)
        {
            dpn[i+d]+=dpn[i-1+d];
            if (dpn[i+d]>=mod)
                dpn[i+d]-=mod;
        }
    }
    for (int i=1; i<=d; i++)
        wyn+=dpn[i+d];
    printf("%lld\n", wyn%mod);
    return 0;
}