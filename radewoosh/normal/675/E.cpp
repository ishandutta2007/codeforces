#include <bits/stdc++.h>
using namespace std;

int n;

int tab[1000007];

long long dp[1000007];

int drzewo[1000007];

long long wyn;

void pisz(int v)
{
    for (int i=v; i<=n; i+=(i&-i))
    {
        if (tab[v]>tab[drzewo[i]])
        {
            drzewo[i]=v;
        }
    }
}

int czyt(int v)
{
    int ret=v;
    for (int i=v; i>0; i-=(i&-i))
    {
        if (tab[drzewo[i]]>tab[ret])
        {
            ret=drzewo[i];
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<n; i++)
    {
        scanf("%d", &tab[i]);
    }
    for (int i=n-1; i>0; i--)
    {
        int p=czyt(tab[i]);
        dp[i]=n-i+dp[p]-(tab[i]-p);
        wyn+=dp[i];
        pisz(i);
    }
    printf("%lld\n", wyn);
    return 0;
}