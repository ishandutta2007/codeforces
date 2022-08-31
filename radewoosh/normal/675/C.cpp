#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[1000007];

long long s;

int it=1;

int wyn=1000000000;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        s+=tab[i];
        tab[i]=s;
    }
    sort(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        while(tab[it]!=tab[i])
        it++;
        wyn=min(wyn, n-(i-it+1));
    }
    printf("%d\n", wyn);
    return 0;
}