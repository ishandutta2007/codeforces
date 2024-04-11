#include <bits/stdc++.h>
using namespace std;

void nope()
{
    printf("-1");
    exit(0);
}

int n, m;

int p1, p2;
long long p3;
vector <int> graf[1000007];

int wcho[1000007];

int oj[1000007];
vector < pair <long long, int> > wek[1100007];
int rep[1000007];

vector <int> lis;

int wsk[1000007];

long long wyn;

int n1;
pair <long long,int> drzewo[2100007];
long long narz[2100007];

int l;
int pre[1000007];
int post[1000007];

long long inf=(long long)100000000*100000000;

int potenga(int v)
{
    for (int i=1; 1; i<<=1)
    {
        if (i>=v)
        {
            return i;
        }
    }
}

pair <long long,int> kana, kanb;

void pisz(int v, int a, int b, int graa, int grab, long long w)
{
    if (a>=graa && b<=grab)
    {
        narz[v]+=w;
        return;
    }
    if (a>grab || b<graa)
    {
        return;
    }
    pisz((v<<1), a, (a+b)>>1, graa, grab, w);
    pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
    kana=drzewo[(v<<1)];
    kana.first+=narz[(v<<1)];
    kanb=drzewo[(v<<1)^1];
    kanb.first+=narz[(v<<1)^1];
    drzewo[v]=min(kana, kanb);
}

pair <long long,int> czyt(int v, int a, int b, int graa, int grab)
{
    if (a>=graa && b<=grab)
    {
        kana=drzewo[v];
        kana.first+=narz[v];
        return kana;
    }
    if (a>grab || b<graa)
    {
        return make_pair(inf, 0);
    }
    pair <long long,int> ra=czyt((v<<1), a, (a+b)>>1, graa, grab);
    pair <long long,int> rb=czyt((v<<1)^1,(a+b+2)>>1, b, graa, grab);
    ra=min(ra, rb);
    ra.first+=narz[v];
    return ra;
}

int fin(int v)
{
    if (v!=oj[v])
    oj[v]=fin(oj[v]);
    return oj[v];
}

int dajr(int v)
{
    return rep[fin(v)];
}

void uni(int v, int u)
{
    v=fin(v);
    u=fin(u);
    if (v==u)
    return;
    rep[v]=u;
    oj[v]=u;
}

void zje(int u)
{
    u>>=1;
    while(u)
    {
        kana=drzewo[(u<<1)];
        kana.first+=narz[(u<<1)];
        kanb=drzewo[(u<<1)^1];
        kanb.first+=narz[(u<<1)^1];
        drzewo[u]=min(kana, kanb);
        //printf("%d   ma %lld+%lld %d\n", u, narz[u], drzewo[u].first, drzewo[u].second);
        u>>=1;
    }
}

void aktu(int v)
{
    int u=pre[v]+n1-1;
    if (wek[v].empty())
    {
        drzewo[u]=make_pair(inf, 0);
        //printf("%d   ma %lld+%lld %d\n", u, narz[u], drzewo[u].first, drzewo[u].second);
    }
    else
    {
        drzewo[u]=wek[v].back();
        drzewo[u].second=v;
        //printf("%d   ma %lld+%lld %d\n", u, narz[u], drzewo[u].first, drzewo[u].second);
    }
    zje(u);
}

void oddo(int v, int u)
{
    u=dajr(u);
    while(1)
    {
        v=dajr(v);
        if (v==u)
        break;
        uni(v, wsk[v]);
    }
}

void dfs(int v, int w)
{
    l++;
    pre[v]=l;
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i]==w)
        continue;
        wsk[graf[v][i]]=v;
        dfs(graf[v][i], v);
    }
    l++;
    post[v]=l;
}

void zmni(int v, long long w)
{
    pisz(1, 1, n1, pre[v], post[v], -w);
}

void dfs2(int v)
{
    for (int i=0; i<graf[v].size(); i++)
    {
        if (graf[v][i]==wsk[v])
        continue;
        dfs2(graf[v][i]);
    }
    if (v==1 || dajr(v)!=v)
    return;
    pair <long long,int> x;
    int cel;
    int u=fin(v);
    while(1)
    {
        x=czyt(1, 1, n1, pre[v], post[v]);
        //printf("w %d     %lld %d\n", v, x.first, x.second);
        if (!x.second)
        break;
        cel=wek[x.second].back().second;
        wek[x.second].pop_back();
        aktu(x.second);
        x.second=cel;
        x.second=fin(x.second);
        if (x.second==fin(v))
        continue;
        //printf("w %d chcemy do %d\n", v, x.second);
        zmni(v, x.first);
        wyn+=x.first;
        oddo(v, x.second);
        return;
    }
    nope();
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<n; i++)
    {
        scanf("%d%d", &p1, &p2);
        graf[p1].push_back(p2);
        graf[p2].push_back(p1);
        wcho[p1]++;
        wcho[p2]++;
    }
    for (int i=1; i<=n; i++)
    {
        oj[i]=i;
        rep[i]=i;
        wcho[i]--;
    }
    wcho[1]++;
    dfs(1, 0);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%lld", &p1, &p2, &p3);
        wek[p1].push_back(make_pair(p3, p2));
    }
    for (int i=1; i<=n; i++)
    {
        sort(wek[i].begin(), wek[i].end());
        reverse(wek[i].begin(), wek[i].end());
    }
    n1=potenga(2*n+5);
    for (int i=1; i<=n1; i++)
    {
        drzewo[i+n1-1]=make_pair(inf, 0);
        zje(i+n1-1);
    }
    for (int i=1; i<=n; i++)
    {
        aktu(i);
    }
    /*for (int i=1; i<2*n1; i++)
    {
        printf("%lld   %lld %d\n", narz[i], drzewo[i].first, drzewo[i].second);
    }*/
    dfs2(1);
    printf("%lld\n", wyn);
    return 0;
}