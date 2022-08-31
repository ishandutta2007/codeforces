#include <bits/stdc++.h>
using namespace std;

int n, k;

int tab[1000007];

int p1, p2;
vector <int> graf[1000007];

int ile[1000007];

long long wyn;

int cen;

void dfs(int v, int oj)
{
    ile[v]=tab[v];
    int ok=1;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i]==oj)
        continue;
        dfs(graf[v][i], v);
        ile[v]+=ile[graf[v][i]];
        if (ile[graf[v][i]]*2>2*k)
        ok=0;
    }
    if ((2*k-ile[v])*2>2*k)
    ok=0;
    if (ok)
    cen=v;
}

void dfs2(int v, int oj, int odl)
{
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i]==oj)
        continue;
        dfs2(graf[v][i], v, odl+1);
    }
    wyn+=tab[v]*odl;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i=1; i<=2*k; i++)
    {
        int x;
        scanf("%d", &x);
        tab[x]++;
    }
    for (int i=1; i<n; i++)
    {
        scanf("%d%d", &p1, &p2);
        graf[p1].push_back(p2);
        graf[p2].push_back(p1);
    }
    dfs(1, 0);
    dfs2(cen, 0, 0);
    printf("%lld\n", wyn);
    return 0;
}