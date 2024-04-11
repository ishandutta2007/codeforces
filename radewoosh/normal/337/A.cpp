#include <bits/stdc++.h>
using namespace std;

int n, m;
int tab[1007];
int wyn=2000;

int main()
{
    scanf("%d%d", &m, &n);
    for (int i=1; i<=n; i++)
    scanf("%d", &tab[i]);
    sort(tab+1, tab+1+n);
    for (int i=m; i<=n; i++)
    wyn=min(wyn, tab[i]-tab[i-m+1]);
    printf("%d\n", wyn);
    return 0;
}