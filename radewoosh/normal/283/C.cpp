#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int q;
long long t;

long long tab[307];
int tyl[307];
int prz[307];
int p1, p2;

int ozn[100007];
long long mod=1000000007;

long long ple[100007];

void dfs(int v, int ile)
{
    ozn[v]=1;
    t-=tab[v]*ile;
    if (prz[v])
    {
        dfs(prz[v], ile+1);
        tab[v]+=tab[prz[v]];
    }
}

int main()
{
    scanf("%d%d%lld", &n, &q, &t);
    for (int i=1; i<=n; i++)
    {
        scanf("%lld", &tab[i]);
    }
    for (int i=1; i<=q; i++)
    {
        scanf("%d%d", &p1, &p2);
        prz[p2]=p1;
        tyl[p1]=p2;
    }
    for (int i=1; i<=n; i++)
    {
        if (!tyl[i])
        {
            dfs(i, 0);
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (!ozn[i])
        {
            printf("0");
            return 0;
        }
    }
    if (t<0)
    {
        printf("0");
        return 0;
    }
    ple[0]=1;
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j+tab[i]<=100000; j++)
        {
            ple[j+tab[i]]+=ple[j];
            ple[j+tab[i]]%=mod;
        }
    }
    printf("%lld", ple[t]);
    return 0;
}