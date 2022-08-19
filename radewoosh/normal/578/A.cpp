#include <bits/stdc++.h>
using namespace std;

long long n, m;

int przez;

double wyn;

double eps;

double wyp;

long long bsa, bsb, bss;

double wyn1=100000000000.0;
double wyn2=100000000000.0;

int zer(double a)
{
    return (a<eps && -a<eps);
}

int main()
{
    eps=0.000001;
    eps*=eps;
    scanf("%lld%lld", &n, &m);
    if (m>n)
    {
        printf("-1\n");
        return 0;
    }
    if (n==m)
    {
        printf("%lld.00000000000\n", n);
        return 0;
    }
    bsa=1;
    bsb=1000000000;
    wyn=(n+m)/2.0;
    while(bsa<bsb)
    {
        bss=(bsa+bsb+2)>>1;
        if (wyn/bss>=m || zer(wyn/bss-m))
        {
            bsa=bss;
        }
        else
        {
            bsb=bss-1;
        }
    }
    wyn1=wyn/bsa;
    if (((n-m)/2)>=m)
    {
        wyn=(n-m)/2.0;
        bsa=1;
        bsb=1000000000;
        while(bsa<bsb)
        {
            bss=(bsa+bsb+2)>>1;
            if (wyn/bss>=m || zer(wyn/bss-m))
            {
                bsa=bss;
            }
            else
            {
                bsb=bss-1;
            }
        }
        wyn2=wyn/bsa;
        printf("%.11lf\n", min(wyn1, wyn2));
    }
    else
    printf("%.11lf\n", wyn1);
    return 0;
}