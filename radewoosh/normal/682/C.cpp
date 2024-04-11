#include <bits/stdc++.h>
using namespace std;

int n;

int tab[1000007];

int p1, p2;
vector < pair <int,long long> > graf[1000007];

int wyn;

void dfs(int v, int oj, long long d, int na)
{
    d=max(d, (long long)0);
    if (d>tab[v])
    na=1;
    wyn+=na;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i].first==oj)
        continue;
        dfs(graf[v][i].first, v, d+graf[v][i].second, na);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    scanf("%d", &tab[i]);
    for (int i=2; i<=n; i++)
    {
        scanf("%d%d", &p1, &p2);
        graf[i].push_back(make_pair(p1, p2));
        graf[p1].push_back(make_pair(i, p2));
    }
    dfs(1, 0, 0, 0);
    printf("%d\n", wyn);
    return 0;
}