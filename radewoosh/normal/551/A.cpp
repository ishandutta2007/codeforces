#include <cstdio>
#include <algorithm>
using namespace std;

int n;

pair <int,int> tab[2007];

int wyn[2007];

int l;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i].first);
        tab[i].second=i;
    }
    sort(tab+1, tab+1+n);
    reverse(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        if (tab[i].first!=tab[i-1].first)
        {
            l=i;
        }
        wyn[tab[i].second]=l;
    }
    for (int i=1; i<=n; i++)
    {
        printf("%d ", wyn[i]);
    }
    return 0;
}