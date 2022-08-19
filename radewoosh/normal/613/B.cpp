#include <bits/stdc++.h>
using namespace std;

int n;

long long d;

long long c1, c2;

long long m;

long long tab[1000007];

long long orr[1000007];

long long wyn;

int it;

long long r;

long long x;

int bsa, bsb, bss;

long long pai, pax;

int dos[1000007];

inline long long sum(int a, int b)
{
    return tab[b]-tab[a-1];
}

bool mniej(int a, int b)
{
    return orr[a]>orr[b];
}

int main()
{
    scanf("%d%lld%lld%lld%lld", &n, &d, &c1, &c2, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        orr[i]=tab[i];
        dos[i]=i;
    }
    sort(dos+1, dos+1+n, mniej);
    sort(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        if (tab[i]==d)
        wyn+=c1;
        tab[i]+=tab[i-1];
    }
    tab[n+1]=tab[n];
    wyn+=c2*tab[1];
    if (m>=(n*d-tab[n]))
    {
        printf("%lld\n", n*c1+d*c2);
        for (int i=1; i<=n; i++)
        {
            printf("%lld ", d);
        }
        printf("\n");
        return 0;
    }
    for (int i=n+1; i; i--)
    {
        r=m-((n-i+1)*d-sum(i, n));
        if (r<0)
        break;
        bsa=1;
        bsb=i-1;
        while(bsa<bsb)
        {
            bss=(bsa+bsb+2)>>1;
            if (r>=bss*(tab[bss]-tab[bss-1])-sum(1, bss))
            {
                bsa=bss;
            }
            else
            {
                bsb=bss-1;
            }
        }
        x=(r+sum(1, bsa))/bsa;
        if ((n-i+1)*c1+x*c2>wyn)
        {
            wyn=(n-i+1)*c1+x*c2;
            pax=x;
            pai=n-i+1;
        }
    }
    for (int i=1; i<=pai; i++)
    {
        orr[dos[i]]=d;
    }
    printf("%lld\n", wyn);
    for (int i=1; i<=n; i++)
    {
        if (orr[i]<=pax)
        {
            orr[i]=pax;
        }
        printf("%lld ", orr[i]);
    }
    printf("\n");
    return 0;
}