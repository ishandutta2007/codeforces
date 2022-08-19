#include <bits/stdc++.h>
using namespace std;

int n;
long long k;

long long tab[1000007];

long long wyn;

map <long long,long long> mapa1;
map <long long,long long> mapa2;

int main()
{
    scanf("%d%lld", &n, &k);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        if (!(tab[i]%(k*k)))
        wyn+=mapa2[tab[i]/k];
        if (!(tab[i]%k))
        mapa2[tab[i]]+=mapa1[tab[i]/k];
        mapa1[tab[i]]++;
    }
    printf("%lld\n", wyn);
    return 0;
}