#include <bits/stdc++.h>
using namespace std;

int n, m;

int p1, p2;

vector < pair <int,int> > graf[1000007];

int bylo[1000007];
int l;
int topo[1000007];

int dp[1000007];

int u;

int bsa, bsb, bss;

void dfs(int v)
{
    if (bylo[v])
    return;
    bylo[v]=1;
    for (int i=0; i<graf[v].size(); i++)
    dfs(graf[v][i].first);
    l++;
    topo[l]=v;
}

int check(int v)
{
    for (int i=1; i<=n; i++)
    {
        u=topo[i];
        dp[u]=1;
        for (int j=0; j<graf[u].size(); j++)
        {
            if (graf[u][j].second>v)
            continue;
            dp[u]=max(dp[u], dp[graf[u][j].first]+1);
        }
        if (dp[u]==n)
        return 1;
    }
    return 0;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d", &p1, &p2);
        graf[p1].push_back(make_pair(p2, i));
    }
    for (int i=1; i<=n; i++)
    {
        dfs(i);
    }
    bsa=1;
    bsb=m+1;
    while(bsa<bsb)
    {
        bss=(bsa+bsb)>>1;
        if (check(bss))
        bsb=bss;
        else
        bsa=bss+1;
    }
    if (bsa<=m)
    printf("%d\n", bsa);
    else
    printf("-1\n");
    return 0;
}