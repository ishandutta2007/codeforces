#include <bits/stdc++.h>
using namespace std;

int n;

pair <int,int> tab[100007];
pair <int,int> dos[100007];

int gdzie[100007];

int najw;

int wyn;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i].first);
        tab[i].second=i;
        dos[i]=tab[i];
    }
    sort(dos+1, dos+1+n);
    for (int i=1; i<=n; i++)
    {
        gdzie[dos[i].second]=i;
    }
    for (int i=1; i<=n; i++)
    {
        najw=max(najw, gdzie[tab[i].second]);
        if (najw==i)
        wyn++;
    }
    printf("%d\n", wyn);
    return 0;
}