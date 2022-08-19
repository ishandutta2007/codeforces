#include <bits/stdc++.h>
using namespace std;

unsigned long long t;
unsigned long long n, m;

unsigned long long nwd, nww;

unsigned long long resz;

void odp(unsigned long long x)
{
    unsigned long long y=t;
    unsigned long long v=__gcd(x, y);
    printf("%llu/%llu\n", x/v, y/v);
}

int main()
{
    scanf("%llu%llu%llu", &t, &n, &m);
    if (n>m)
    swap(n, m);
    if (n>t)
    {
        printf("1/1\n");
        return 0;
    }
    nwd=__gcd(n, m);
    if (n/nwd>t/m)
    {
        odp(n-1);
        return 0;
    }
    nww=(n/nwd)*m;
    resz=t%nww;
    odp(n*(t/nww)+min(resz, n-1));
    return 0;
}