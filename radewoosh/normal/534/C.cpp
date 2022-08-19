#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long m;
long long sum;
long long tab[1000007];

long long pom;

long long gor1, dol1;
long long gor2, dol2;

int main()
{
    scanf("%d%lld", &n, &m);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
        sum+=tab[i];
    }
    for (int i=1; i<=n; i++)
    {
        pom=sum-tab[i];
        gor1=pom;
        dol1=n-1;
        gor2=m-1;
        dol2=m-tab[i];
        printf("%lld ", tab[i]-(min(gor1, gor2)-max(dol1, dol2))-1);
    }
    return 0;
}