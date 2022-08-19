#include <bits/stdc++.h>
using namespace std;

long long n;
long long a, b, x;

long long mod=1000000007;

long long wyn;

long long pot(long long v, long long u)
{
    v%=mod;
    long long ret=1;
    while(u)
    {
        if (u&1)
        {
            ret*=v;
            ret%=mod;
        }
        v*=v;
        v%=mod;
        u>>=1;
    }
    return ret;
}

long long dziel(long long v, long long u)
{
    v%=mod;
    v+=mod;
    v%=mod;

    u%=mod;
    u+=mod;
    u%=mod;

    return (v*pot(u, mod-2))%mod;
}

int main()
{
    scanf("%lld", &a);
    scanf("%lld", &b);
    scanf("%lld", &n);
    scanf("%lld", &x);

    if (a==1)
    wyn=x+((n%mod)*b);
    else
    wyn=x*pot(a, n)+b*dziel(pot(a, n)-1, a-1);

    wyn%=mod;
    wyn+=mod;
    wyn%=mod;

    printf("%lld\n", wyn);
    return 0;
}