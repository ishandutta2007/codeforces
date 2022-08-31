#include <bits/stdc++.h>
using namespace std;

int n;
long long k;

long long tab[1000007];

pair <long long,long long> mini, maxi;

long long suma;
long long prz[1000007];

long long s;

long long bsa, bsb, bss;

long long l, p;

int main()
{
    scanf("%d%lld", &n, &k);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        suma+=tab[i];
    }
    if (n==1)
    {
        printf("0\n");
        return 0;
    }
    sort(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        prz[i]=suma/n+((suma%n)>=i);
    }
    reverse(prz+1, prz+1+n);
    for (int i=1; i<=n; i++)
    {
        s+=max((long long)0, tab[i]-prz[i]);
    }
    if (s<=k)
    {
        if (!(suma%n))
        {
            printf("0\n");
        }
        else
        {
            printf("1\n");
        }
        return 0;
    }
    bsa=0;
    bsb=1000000000;
    while(bsa<bsb)
    {
        bss=(bsa+bsb+2)>>1;
        s=0;
        for (int i=1; i<=n; i++)
        {
            s+=max((long long)0, bss-tab[i]);
        }
        if (s<=k)
        {
            bsa=bss;
        }
        else
        {
            bsb=bss-1;
        }
    }
    l=bsa;

    bsa=0;
    bsb=1000000000;
    while(bsa<bsb)
    {
        bss=(bsa+bsb)>>1;
        s=0;
        for (int i=1; i<=n; i++)
        {
            s+=max((long long)0, tab[i]-bss);
        }
        if (s<=k)
        {
            bsb=bss;
        }
        else
        {
            bsa=bss+1;
        }
    }
    p=bsa;

    printf("%lld\n", p-l);
    return 0;
}