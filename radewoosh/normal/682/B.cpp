#include <bits/stdc++.h>
using namespace std;

int n;

int tab[1000007];

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    scanf("%d", &tab[i]);
    sort(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    tab[i]=min(tab[i], tab[i-1]+1);
    printf("%d\n", tab[n]+1);
    return 0;
}