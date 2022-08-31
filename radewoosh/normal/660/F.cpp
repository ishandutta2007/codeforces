#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[1000007];

long long s[1000007];
long long p[1000007];

long long wyn;

long long odp(int a, int b)
{
    a--;
    return p[b]-p[a]-(s[b]-s[a])*a;
}

void rek(int a, int b, int graa, int grab)
{
    if (a>b)
    return;
    int s=(a+b)>>1;
    int c=-1;
    for (int i=grab; i>=graa && i>=s; i--)
    {
        if (c==-1 || odp(s, i)>odp(s, c))
        {
            c=i;
        }
    }
    wyn=max(wyn, odp(s, c));
    rek(a, s-1, graa, c);
    rek(s+1, b, c, grab);
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        s[i]=s[i-1]+tab[i];
        p[i]=p[i-1]+tab[i]*i;
    }
    rek(1, n, 1, n);
    printf("%lld\n", wyn);
    return 0;
}