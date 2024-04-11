#include <bits/stdc++.h>
using namespace std;

int n;

int tab[1000007];
char wcz[1000007];

int p1, p2;
vector <int> graf[1000007];

long long h=263;
long long mod1=1000000007;
long long mod2=1000000009;

long long hasz1[1000007];
long long hasz2[1000007];

int oj[1000007];
int lew[1000007];
int pra[1000007];

int l;
int kt[1000007];

int nal[1000007];
int nap[1000007];

map <pair <long long, long long> , int> mapa;

int u;
pair <long long,long long> pomh;

int roz[1000007];

int pam[1000007];

int mak=-1;
int ile=0;

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
    if (pra[a]-lew[a]<pra[b]-lew[b])
    {
        for (int i=lew[a]; i<=pra[a]; i++)
        {
            if (nap[i]>pra[b] || !nap[i])
            {
                roz[b]++;
            }
        }
        lew[b]=lew[a];
        oj[a]=b;
    }
    else
    {
        for (int i=lew[b]; i<=pra[b]; i++)
        {
            if (nal[i]<lew[a] || !nal[i])
            {
                roz[a]++;
            }
        }
        pra[a]=pra[b];
        oj[b]=a;
    }
}

void dfs(int v, int zko)
{
    hasz1[v]=(hasz1[zko]*h+wcz[v])%mod1;
    hasz2[v]=(hasz2[zko]*h+wcz[v])%mod2;
    l++;
    lew[v]=l;
    pra[v]=l;
    kt[l]=v;
    roz[v]=1;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i]!=zko)
        {
            dfs(graf[v][i], v);
        }
    }
}

void dfs2(int v, int zko)
{
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i]!=zko)
        {
            dfs2(graf[v][i], v);
            uni(v, graf[v][i]);
        }
    }
    pam[v]=roz[fin(v)];
}

int main()
{
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &tab[i]);
        oj[i]=i;
    }
    scanf("%s", wcz+1);
    for (int i=1; i<n; i++)
    {
        scanf("%d%d", &p1, &p2);
        graf[p1].push_back(p2);
        graf[p2].push_back(p1);
    }
    dfs(1, 0);
    for (int i=1; i<=n; i++)
    {
        u=kt[i];
        pomh=make_pair(hasz1[u], hasz2[u]);
        nal[i]=mapa[pomh];
        nap[mapa[pomh]]=i;
        mapa[pomh]=i;
    }
    dfs2(1, 0);
    for (int i=1; i<=n; i++)
    {
        if (pam[i]+tab[i]>mak)
        {
            mak=pam[i]+tab[i];
            ile=0;
        }
        if (pam[i]+tab[i]==mak)
        {
            ile++;
        }
    }
    printf("%d\n%d\n", mak, ile);
    return 0;
}