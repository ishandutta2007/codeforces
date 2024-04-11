#include <bits/stdc++.h>
using namespace std;

int n, m;

int x;

long long tab[1000007];

long long mno;

long long wyn;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &x);
        tab[x]++;
    }
    for (int i=1; i<=m; i++)
    {
        wyn+=tab[i]*mno;
        mno+=tab[i];
    }
    printf("%lld\n", wyn);
    return 0;
}