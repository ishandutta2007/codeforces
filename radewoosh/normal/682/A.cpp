#include <bits/stdc++.h>
using namespace std;

int n, m;

long long wyn;

long long il1[10];
long long il2[10];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    il1[i%5]++;
    for (int i=1; i<=m; i++)
    il2[i%5]++;
    for (int i=0; i<5; i++)
    wyn+=il1[i]*il2[(5-i)%5];
    printf("%lld\n", wyn);
    return 0;
}