#include <bits/stdc++.h>
using namespace std;

int n, m;

pair <int,int> kra[1000007];
int waga[1000007];

int dos[1000007];

vector <int> graf[1000007];

long long wyn;

int oj[1000007];

int p;

map < pair <int,int> , int > mapa;

vector < pair < int, int> > jump[1000007];

int odl[1000007];

int p1, p2;

int p3;

bool mniej(int a, int b)
{
    return (waga[a]<waga[b]);
}

int fin(int v)
{
    if (v!=oj[v])
    oj[v]=fin(oj[v]);
    return oj[v];
}

void uni(int a, int b)
{
    a=fin(a);
    b=fin(b);
    if (a==b)
    return;
    oj[a]=b;
}

void dfs(int v, int o)
{
    jump[v].push_back(make_pair(o, mapa[make_pair(v, o)]));
    while(jump[v].back().first)
    {
        int x=jump[v].back().first;
        int y=jump[v].size()-1;
        int pcha=jump[v][y].second;
        int cel=0;
        if (jump[x].size()>y)
        {
            pcha=max(pcha, jump[x][y].second);
            cel=jump[x][y].first;
        }
        jump[v].push_back(make_pair(cel, pcha));
    }
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i]!=o)
        {
            odl[graf[v][i]]=odl[v]+1;
            dfs(graf[v][i], v);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        oj[i]=i;
    }
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d", &kra[i].first, &kra[i].second, &waga[i]);
        mapa[kra[i]]=waga[i];
        swap(kra[i].first, kra[i].second);
        mapa[kra[i]]=waga[i];
        dos[i]=i;
    }
    sort(dos+1, dos+1+m, mniej);
    for (int i=1; i<=m; i++)
    {
        p=dos[i];
        if (fin(kra[p].first)!=fin(kra[p].second))
        {
            wyn+=waga[p];
            uni(kra[p].first, kra[p].second);
            graf[kra[p].first].push_back(kra[p].second);
            graf[kra[p].second].push_back(kra[p].first);
        }
    }
    dfs(1, 0);
    for (int h=1; h<=m; h++)
    {
        p1=kra[h].first;
        p2=kra[h].second;
        p3=0;
        for (int i=20; i>=0; i--)
        {
            if (jump[p1].size()>i+1 && odl[jump[p1][i].first]>=odl[p2])
            {
                p3=max(p3, jump[p1][i].second);
                p1=jump[p1][i].first;
            }
        }
        for (int i=20; i>=0; i--)
        {
            if (jump[p2].size()>i+1 && odl[jump[p2][i].first]>=odl[p1])
            {
                p3=max(p3, jump[p2][i].second);
                p2=jump[p2][i].first;
            }
        }
        for (int i=20; i>=0; i--)
        {
            if (jump[p1].size()>i+1 && jump[p2].size()>i+1 && jump[p1][i].first!=jump[p2][i].first)
            {
                p3=max(p3, jump[p1][i].second);
                p3=max(p3, jump[p2][i].second);
                p1=jump[p1][i].first;
                p2=jump[p2][i].first;
            }
        }
        if (p1!=p2)
        {
            p3=max(p3, jump[p1][0].second);
            p3=max(p3, jump[p2][0].second);
        }
        printf("%lld\n", wyn-p3+waga[h]);
    }
    return 0;
}