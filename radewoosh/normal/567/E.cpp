#include <bits/stdc++.h>
using namespace std;

int n, m;
int s, t;

long long kosz[1000007];
int lew[1000007];
int pra[1000007];
vector < pair <int,int> > graf[1000007];
vector < pair <int,int> > farg[1000007];

vector < pair <int,int> > graf2[1000007];

int p1, p2;

priority_queue < pair <long long,int> > kol;

long long odl1[1000007];
long long odl2[1000007];
long long inf;

int u;

int bylo[1000007];

int l;
int pre[1000007];
int low[1000007];

int pew[1000007];

long long naj;
long long ter;

void dfs(int v)
{
    bylo[v]=-1;
    if (v==t)
    {
        bylo[v]=1;
        return;
    }
    for (int i=0; i<graf[v].size(); i++)
    {
        if (odl1[v]+kosz[graf[v][i].second]==odl1[graf[v][i].first])
        {
            if (!bylo[graf[v][i].first])
            {
                dfs(graf[v][i].first);
            }
            if (bylo[graf[v][i].first]==1)
            {
                bylo[v]=1;
                graf2[v].push_back(graf[v][i]);
                graf2[graf[v][i].first].push_back(make_pair(v, graf[v][i].second));
            }
        }
    }
}

void dfs2(int v, int oj)
{
    l++;
    pre[v]=l;
    low[v]=l;
    for (int i=0; i<graf2[v].size(); i++)
    {
        if (graf2[v][i].second==oj)
        continue;
        if (pre[graf2[v][i].first])
        {
            low[v]=min(low[v], pre[graf2[v][i].first]);
        }
        else
        {
            dfs2(graf2[v][i].first, graf2[v][i].second);
            low[v]=min(low[v], low[graf2[v][i].first]);
        }
        if (low[graf2[v][i].first]>pre[v])
        {
            pew[graf2[v][i].second]=1;
        }
    }
}



int main()
{
    inf=1000000000;
    inf*=inf;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%lld", &p1, &p2, &kosz[i]);
        lew[i]=p1;
        pra[i]=p2;
        graf[p1].push_back(make_pair(p2, i));
        farg[p2].push_back(make_pair(p1, i));
    }
    for (int i=1; i<=n; i++)
    {
        odl1[i]=inf;
    }
    kol.push(make_pair(0, s));
    while(!kol.empty())
    {
        u=kol.top().second;
        if (odl1[u]!=inf)
        {
            kol.pop();
            continue;
        }
        odl1[u]=-kol.top().first;
        kol.pop();
        for (int i=0; i<graf[u].size(); i++)
        {
            kol.push(make_pair(-odl1[u]-kosz[graf[u][i].second], graf[u][i].first));
        }
    }
    for (int i=1; i<=n; i++)
    {
        odl2[i]=inf;
    }
    kol.push(make_pair(0, t));
    while(!kol.empty())
    {
        u=kol.top().second;
        if (odl2[u]!=inf)
        {
            kol.pop();
            continue;
        }
        odl2[u]=-kol.top().first;
        kol.pop();
        for (int i=0; i<farg[u].size(); i++)
        {
            kol.push(make_pair(-odl2[u]-kosz[farg[u][i].second], farg[u][i].first));
        }
    }
    dfs(s);
    dfs2(s, 0);
    naj=odl1[t];
    for (int i=1; i<=m; i++)
    {
        if (pew[i])
        {
            printf("YES\n");
            continue;
        }
        ter=naj-odl2[pra[i]]-odl1[lew[i]]-1;
        if (ter>0)
        printf("CAN %lld\n", kosz[i]-ter);
        else
        printf("NO\n");
    }
    return 0;
}