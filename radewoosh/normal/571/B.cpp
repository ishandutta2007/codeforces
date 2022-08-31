#include <bits/stdc++.h>
using namespace std;

int n, k;

long long tab[300007];

long long dpn[5007];
long long dps[5007];

long long inf;

int dol;

int main()
{
    inf=1000000000;
    inf*=inf;
    scanf("%d%d", &n, &k);
    dol=n/k;
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    sort(tab+1, tab+1+n);
    for (int i=1; i<=k; i++)
    {
        dpn[i]=inf;
    }
    for (int i=1; i<=k; i++)
    {
        for (int j=0; j<=k; j++)
        {
            dps[j]=dpn[j];
            dpn[j]=inf;
        }
        for (int j=0; j<=k; j++)
        {
            dpn[j]=min(dpn[j], dps[j]+tab[i*dol+j]-tab[(i-1)*dol+j+1]);
            if (j)
            dpn[j]=min(dpn[j], dps[j-1]+tab[i*dol+j]-tab[(i-1)*dol+j]);
            //printf("%d %d %lld\n", i, j, dpn[j]);
        }
    }
    printf("%lld", dpn[n%k]);
    return 0;
}