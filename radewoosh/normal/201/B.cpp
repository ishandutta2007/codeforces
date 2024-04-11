#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;

long long tab[1007][1007];

long long sumh[1007];
long long sumv[1007];

int ox, oy;

long long prze;

long long aktu;

long long wyn;

long long kwa(long long a)
{
    return a*a;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            scanf("%lld", &tab[i][j]);
            sumh[i]+=tab[i][j];
            sumv[j]+=tab[i][j];
        }
    }
    prze=1000000000;
    prze*=prze;
    for (int i=0; i<=n; i++)
    {
        aktu=0;
        for (int j=1; j<=n; j++)
        {
            aktu+=sumh[j]*kwa(4*max(i-j, j-i-1)+2);
        }
        if (aktu<prze)
        {
            ox=i;
            prze=aktu;
        }
    }
    wyn+=prze;

    prze=1000000000;
    prze*=prze;
    for (int i=0; i<=m; i++)
    {
        aktu=0;
        for (int j=1; j<=m; j++)
        {
            aktu+=sumv[j]*kwa(4*max(i-j, j-i-1)+2);
        }
        if (aktu<prze)
        {
            oy=i;
            prze=aktu;
        }
    }
    wyn+=prze;
    printf("%lld\n%d %d", wyn, ox, oy);
    return 0;
}