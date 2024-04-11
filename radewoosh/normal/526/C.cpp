#include <iostream>
#include <cstdio>
using namespace std;

long long n;
long long w1, w2, r1, r2;

long long iler;

long long wyn;

long long moz;

long long tmp;

int main()
{
    scanf("%lld%lld%lld%lld%lld", &n, &r1, &r2, &w1, &w2);
    if (w2>w1)
    {
        tmp=w2;
        w2=w1;
        w1=tmp;

        tmp=r2;
        r2=r1;
        r1=tmp;
    }
    if (w1*w2<=n)
    {
        iler=n/(w1*w2);
        iler--;
        n%=(w1*w2);
        n+=w1*w2;
        if (r1*w2>r2*w1)
        {
            wyn+=iler*w2*r1;
        }
        else
        {
            wyn+=iler*w1*r2;
        }
    }
    //printf("%lld %lld\n", n, wyn);
    for (long long i=0; i*w1<=n; i++)
    {
        iler=n;
        iler-=(i*w1);
        iler/=w2;
        iler*=r2;
        moz=max(moz, (i*r1)+iler);
    }
    wyn+=moz;
    printf("%lld", wyn);
    return 0;
}