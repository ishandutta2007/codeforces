#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[1000007];

long long m;

int main()
{
    scanf("%d%lld", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    sort(tab+1, tab+1+n);
    reverse(tab+1, tab+1+n);
    for (int i=1; i<=n; i++)
    {
        m-=tab[i];
        if (m<=0)
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}