#include <bits/stdc++.h>
using namespace std;

long long n, m;

int il1, il2;

int wyn;

int tab[10];

int sil=5040;

long long a, b;
long long r;

int licz(long long v)
{
    int ret=0;
    v--;
    while(v)
    {
        ret++;
        v/=7;
    }
    return max(ret, 1);
}

int main()
{
    scanf("%lld%lld", &n, &m);
    il1=licz(n);
    il2=licz(m);
    if (il1+il2>7)
    {
        printf("0\n");
        return 0;
    }
    for (int i=0; i<7; i++)
    tab[i]=i;
    while(sil--)
    {
        next_permutation(tab, tab+7);
        a=0;
        r=1;
        for (int i=0; i<il1; i++)
        {
            a+=tab[i]*r;
            r*=7;
        }
        b=0;
        r=1;
        for (int i=0; i<il2; i++)
        {
            b+=tab[il1+i]*r;
            r*=7;
        }
        if (a<n && b<m)
        {
            wyn++;
        }
    }
    for (int i=1; i<=7-il1-il2; i++)
    wyn/=i;
    printf("%d\n", wyn);
    return 0;
}