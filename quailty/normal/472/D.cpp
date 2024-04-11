#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2005;
ll d[MAXN][MAXN],f[MAXN][MAXN];
bool check(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if((i==j)^(d[i][j]==0))return 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(d[i][j]!=d[j][i])return 0;
    return 1;
}
struct Edge
{
    int u,v;
    ll w;
    Edge(int _u=0,int _v=0,ll _w=0):u(_u),v(_v),w(_w){}
    bool operator < (const Edge &t)const
    {
        return w<t.w;
    }
}p[MAXN*MAXN];
#define ft first
#define sd second
vector<pair<int,ll> >e[MAXN];
struct DSU
{
    int n,fa[MAXN];
    void Init(int _n)
    {
        n=_n;
        for(int i=0;i<n;i++)
            fa[i]=i;
    }
    int Find(int x)
    {
        return x==fa[x] ? x : fa[x]=Find(fa[x]);
    }
    bool Union(int x,int y)
    {
        x=Find(x),y=Find(y);
        if(x==y)return 0;
        return fa[x]=y,1;
    }
}dsu;
void dfs(int u,int fa,ll dis[])
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].ft;
        if(v==fa)continue;
        dis[v]=dis[u]+e[u][i].sd;
        dfs(v,u,dis);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%I64d",&d[i][j]);
    if(!check(n))return 0*printf("NO");
    int tot=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            p[tot++]=Edge(i,j,d[i][j]);
    sort(p,p+tot);
    dsu.Init(n);
    for(int i=0;i<tot;i++)
        if(dsu.Union(p[i].u,p[i].v))
        {
            e[p[i].u].push_back(make_pair(p[i].v,p[i].w));
            e[p[i].v].push_back(make_pair(p[i].u,p[i].w));
        }
    for(int i=0;i<n;i++)
        dfs(i,-1,f[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(d[i][j]!=f[i][j])return 0*printf("NO");
    return 0*printf("YES");
}