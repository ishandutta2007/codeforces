#include <bits/stdc++.h>
using namespace std;

int n, k, x;

long long tab[1000007];
long long pre[1000007];
long long suf[1000007];
long long wyn;

long long co;

int main()
{
    scanf("%d%d%d", &n, &k, &x);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    sort(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        pre[i]=pre[i-1]|tab[i];
    }
    for (int i=n; i; i--)
    {
        suf[i]=suf[i+1]|tab[i];
    }
    for (int i=1; i<=n; i++)
    {
        co=tab[i];
        for (int j=1; j<=k; j++)
        {
            co*=x;
        }
        wyn=max(wyn, pre[i-1]|suf[i+1]|co);
    }
    printf("%lld", wyn);
    return 0;
}