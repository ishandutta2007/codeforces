#include <bits/stdc++.h>
using namespace std;

int n, m;

int p1, p2;
vector < pair < int,int> > graf[200007];

long long kosz[200007];

int wgu[200007];
int numw[200007];

int gdzie[200007];

int odl[200007];

int co;
long long p3;

int oj[200007];

int fin(int v)
{
    if (v!=oj[v])
    oj[v]=fin(oj[v]);
    return oj[v];
}

void uni(int v)
{
    oj[v]=wgu[v];
}

void dfs(int v)
{
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i].first==wgu[v])
        continue;
        numw[graf[v][i].first]=graf[v][i].second;
        gdzie[graf[v][i].second]=graf[v][i].first;
        wgu[graf[v][i].first]=v;
        if (kosz[graf[v][i].second]==1)
        uni(graf[v][i].first);
        odl[graf[v][i].first]=odl[v]+1;
        dfs(graf[v][i].first);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        oj[i]=i;
    }
    for (int i=1; i<n; i++)
    {
        scanf("%d%d%lld", &p1, &p2, &kosz[i]);
        graf[p1].push_back(make_pair(p2, i));
        graf[p2].push_back(make_pair(p1, i));
    }
    dfs(1);
    while(m--)
    {
        scanf("%d", &co);
        if (co==1)
        {
            scanf("%d%d%lld", &p1, &p2, &p3);
            p1=fin(p1);
            p2=fin(p2);
            while(p1!=p2 && p3)
            {
                if (odl[p1]>=odl[p2])
                {
                    p3/=kosz[numw[p1]];
                    p1=fin(wgu[p1]);
                }
                else
                {
                    p3/=kosz[numw[p2]];
                    p2=fin(wgu[p2]);
                }
            }
            printf("%lld\n", p3);
        }
        else
        {
            scanf("%d%lld", &p1, &p3);
            kosz[p1]=p3;
            if (kosz[p1]==1)
            uni(gdzie[p1]);
        }
    }
    return 0;
}