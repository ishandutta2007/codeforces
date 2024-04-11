#include <bits/stdc++.h>
using namespace std;

long long n;

long long x, y;

long long bsa, bsb, bss;

long long m;

inline long long ile(long long v)
{
    return (v*(v+1)/2)*6;
}

int main()
{
    scanf("%lld", &n);
    if (n==0)
    {
        printf("0 0\n");
        return 0;
    }
    bsa=0;
    bsb=1000000000;
    while(bsa<bsb)
    {
        bss=(bsa+bsb+2)>>1;
        if (ile(bss)>=n)
        bsb=bss-1;
        else
        bsa=bss;
    }
    n-=ile(bsa);

    bsa++;
    x+=2*bsa;

    m=min(n, bsa);
    x-=m;
    y+=2*m;
    n-=m;

    m=min(n, bsa);
    x-=2*m;
    n-=m;

    m=min(n, bsa);
    x-=m;
    y-=2*m;
    n-=m;

    m=min(n, bsa);
    x+=m;
    y-=2*m;
    n-=m;

    m=min(n, bsa);
    x+=2*m;
    n-=m;

    m=min(n, bsa);
    x+=m;
    y+=2*m;
    n-=m;
    printf("%lld %lld\n", x, y);
    return 0;
}