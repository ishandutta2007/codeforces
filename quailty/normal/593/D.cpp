#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int u[MAXN],v[MAXN];
int fa[MAXN],dep[MAXN];
ll x[MAXN],val[MAXN];
vector<pair<int,ll> >e[MAXN];
void dfs(int u,int la)
{
    fa[u]=(u==1 ? 1 : la);
    dep[u]=dep[la]+1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].first;
        if(v==la)val[u]=e[u][i].second;
        else dfs(v,u);
    }
}
struct DSU
{
    int fa[MAXN];
    void Init(int n)
    {
        for(int i=1;i<=n;i++)fa[i]=i;
    }
    int Find(int x)
    {
        return x==fa[x] ? x : fa[x]=Find(fa[x]);
    }
    void Union(int x,int y)
    {
        x=Find(x),y=Find(y);
        if(x==y)return;
        if(dep[x]<dep[y])swap(x,y);
        fa[x]=y;
    }
}dsu;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%I64d",&u[i],&v[i],&x[i]);
        e[u[i]].push_back(make_pair(v[i],x[i]));
        e[v[i]].push_back(make_pair(u[i],x[i]));
    }
    dfs(1,0);
    dsu.Init(n);
    for(int i=1;i<n;i++)
        if(x[i]==1)dsu.Union(u[i],v[i]);
    for(int i=1;i<=m;i++)
    {
        int ty,a,b,p;
        ll y,c;
        scanf("%d",&ty);
        if(ty==1)
        {
            scanf("%d%d%I64d",&a,&b,&y);
            a=dsu.Find(a),b=dsu.Find(b);
            while(a!=b && y)
            {
                if(dep[a]<dep[b])swap(a,b);
                y/=val[a];
                a=dsu.Find(fa[a]);
            }
            printf("%I64d\n",y);
        }
        else
        {
            scanf("%d%I64d",&p,&c);
            if(dep[u[p]]<dep[v[p]])swap(u[p],v[p]);
            if((val[u[p]]=c)==1)dsu.Union(u[p],fa[u[p]]);
        }
    }
    return 0;
}