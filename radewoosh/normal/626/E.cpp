#include <bits/stdc++.h>
using namespace std;

struct licz
{
    long long li;
    long long mi;
    licz()
    {
        li=mi=0;
    }
    licz(long long lili, long long mimi)
    {
        li=lili;
        mi=mimi;
    }
};

bool operator < (licz a, licz b)
{
    return a.li*b.mi<b.li*a.mi;
}

int n;

long long tab[1000007];
long long sum[1000007];

int tsa, tsb, tss;

licz wyn=licz(0, 1);

int s=1;
int il;

licz k1, k2;

long long daj(int a, int b)
{
    return sum[b]-sum[a-1];
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    scanf("%lld", &tab[i]);
    sort(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    sum[i]=sum[i-1]+tab[i];
    for (int i=2; i<n; i++)
    {
        tsa=1;
        tsb=min(i-1, n-i);
        while(tsa<tsb)
        {
            tss=(tsa+tsb)/2;
            k1=licz(tab[i]+daj(i-tss, i-1)+daj(n+1-tss, n), 2*tss+1);
            tss++;
            k2=licz(tab[i]+daj(i-tss, i-1)+daj(n+1-tss, n), 2*tss+1);
            tss--;
            if (k1<k2)
            {
                tsa=tss+1;
            }
            else
            {
                tsb=tss;
            }
        }
        tss=tsa;
        k1=licz(tab[i]+daj(i-tss, i-1)+daj(n+1-tss, n), 2*tss+1);
        k1.li-=tab[i]*(2*tss+1);
        if (wyn<k1)
        {
            wyn=k1;
            s=i;
            il=tsa;
        }
    }
    printf("%d\n", 2*il+1);
    for (int i=1; i<=il; i++)
    printf("%lld ", tab[s-i]);
    for (int i=1; i<=il; i++)
    printf("%lld ", tab[n+1-i]);
    printf("%lld\n", tab[s]);
    return 0;
}