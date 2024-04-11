#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[1000007];

long long odll[1000007];
long long odlp[1000007];

long long wyn;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    for (int i=1; i<=n; i++)
    {
        odll[i]=min(odll[i-1]+1, tab[i]);
    }
    for (int i=n; i; i--)
    {
        odlp[i]=min(odlp[i+1]+1, tab[i]);
    }
    for (int i=1; i<=n; i++)
    {
        wyn=max(wyn, min(odll[i], odlp[i]));
    }
    printf("%lld\n", wyn);
    return 0;
}