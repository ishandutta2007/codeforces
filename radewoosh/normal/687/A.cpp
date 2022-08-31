#include <bits/stdc++.h>
using namespace std;

int n, m;

int p1, p2;
vector <int> graf[1000007];

int kol[1000007];

void nope()
{
    printf("-1\n");
    exit(0);
}

vector <int> zbi[2];

void dfs(int v, int ko)
{
    if (kol[v])
    {
        if (kol[v]!=ko)
        {
            nope();
        }
        return;
    }
    kol[v]=ko;
    for (int i=0; i<graf[v].size(); i++)
    {
        dfs(graf[v][i], ko^1);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d", &p1, &p2);
        graf[p1].push_back(p2);
        graf[p2].push_back(p1);
    }
    for (int i=1; i<=n; i++)
    {
        if (!kol[i])
        {
            dfs(i, 2);
        }
    }
    for (int i=1; i<=n; i++)
    zbi[kol[i]-2].push_back(i);
    for (int h=0; h<2; h++)
    {
        printf("%d\n", zbi[h].size());
        for (int i=0; i<zbi[h].size(); i++)
        printf("%d ", zbi[h][i]);
        printf("\n");
    }
    return 0;
}