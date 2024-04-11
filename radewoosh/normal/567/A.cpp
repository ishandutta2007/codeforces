#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[1000007];

long long w;

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    for (int i=1; i<=n; i++)
    {
        w=1000000;
        w*=w;
        if (i>1)
        w=min(w, tab[i]-tab[i-1]);
        if (i<n)
        w=min(w, tab[i+1]-tab[i]);
        printf("%lld %lld\n", w, max(tab[n]-tab[i], tab[i]-tab[1]));
    }
    return 0;
}