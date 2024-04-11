#include <bits/stdc++.h>
using namespace std;

int n;

long long tab[1000007];
long long ma[1000007];

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    for (int i=n; i; i--)
    {
        ma[i]=max(ma[i+1], tab[i]);
    }
    for (int i=1; i<=n; i++)
    {
        printf("%lld ", max((long long) 0, ma[i+1]-tab[i]+1));
    }
    return 0;
}