#include <bits/stdc++.h>
using namespace std;

int n;

int tab[1000007];

int x;

int wyn=1000000000;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        tab[x]=tab[x-1]+1;
    }
    for (int i=1; i<=n; i++)
    {
        wyn=min(wyn, n-tab[i]);
    }
    printf("%d\n", wyn);
    return 0;
}