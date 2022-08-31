#include <bits/stdc++.h>
using namespace std;

int n, q;

int p1;

vector <int> graf[1000007];

int oj[1000007];
int roz[1000007];
int maxdz[1000007];

int wyn[1000007];

void dfs(int v)
{
    roz[v]=1;
    for (int i=0; i<graf[v].size(); i++)
    {
        dfs(graf[v][i]);
        roz[v]+=roz[graf[v][i]];
        maxdz[v]=max(maxdz[v], roz[graf[v][i]]);
    }
    wyn[v]=v;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (roz[graf[v][i]]*2>roz[v])
        wyn[v]=wyn[graf[v][i]];
    }
    while(maxdz[wyn[v]]*2>roz[v] || (roz[v]-roz[wyn[v]])*2>roz[v])
    wyn[v]=oj[wyn[v]];
}

int main()
{
    scanf("%d%d", &n, &q);
    for (int i=2; i<=n; i++)
    {
        scanf("%d", &oj[i]);
        graf[oj[i]].push_back(i);
    }
    dfs(1);
    while(q--)
    {
        scanf("%d", &p1);
        printf("%d\n", wyn[p1]);
    }
    return 0;
}