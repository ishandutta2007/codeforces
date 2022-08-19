#include <bits/stdc++.h>
using namespace std;

int n, m;

int p1, p2, p3;
vector < pair <int,int> > graf[1000007];

int l;
int pre[1000007];
int low[1000007];

int bic[1000007];

int b;

vector <int> sta;

int pocz, kon;

int bylo[1000007];
int ok[1000007];

void dfs(int v, int p)
{
    l++;
    pre[v]=l;
    low[v]=l;
    sta.push_back(v);
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i].second==p)
        continue;
        if (pre[graf[v][i].first])
        {
            low[v]=min(low[v], pre[graf[v][i].first]);
        }
        else
        {
            dfs(graf[v][i].first, graf[v][i].second);
            low[v]=min(low[v], low[graf[v][i].first]);
        }
    }
    if (pre[v]==low[v])
    {
        b++;
        while(sta.back()!=v)
        {
            bic[sta.back()]=b;
            sta.pop_back();
        }
        bic[sta.back()]=b;
        sta.pop_back();
    }
}

void dfs2(int v)
{
    bylo[v]=1;
    sta.push_back(bic[v]);
    if (v==kon)
    {
        for (int i=0; i<sta.size(); i++)
        {
            ok[sta[i]]=1;
        }
    }
    for (int i=0; i<graf[v].size(); i++)
    {
        if (bylo[graf[v][i].first])
        continue;
        dfs2(graf[v][i].first);
    }
    sta.pop_back();
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d", &p1, &p2, &p3);
        if (p3==1)
        {
            graf[p1].push_back(make_pair(p2, i));
            graf[p2].push_back(make_pair(p1, i));
        }
        else
        {
            graf[p1].push_back(make_pair(p2, -i));
            graf[p2].push_back(make_pair(p1, -i));
        }
    }
    scanf("%d%d", &pocz, &kon);
    dfs(1, 0);
    dfs2(pocz);
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<graf[i].size(); j++)
        {
            if (graf[i][j].second>0 && ok[bic[i]] && ok[bic[graf[i][j].first]])
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}