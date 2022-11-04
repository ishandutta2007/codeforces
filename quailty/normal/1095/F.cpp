#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll INF=(1LL<<60)-1;
ll a[MAXN];
struct Edge
{
    int u,v;
    ll w;
    bool operator < (const Edge &t)const
    {
        return w<t.w;
    }
}e[MAXN<<1];
struct DSU
{
    int fa[MAXN];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            fa[i]=i;
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    bool merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)return 0;
        return fa[x]=y,1;
    }
}dsu;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    ll mi=INF;
    int loc=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]<mi)mi=a[i],loc=i;
    }
    for(int i=1;i<=m;i++)
        scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
    for(int i=1;i<=n;i++)
        e[i+m].u=loc,e[i+m].v=i,e[i+m].w=mi+a[i];
    dsu.init(n);
    sort(e+1,e+n+m+1);
    ll res=0;
    for(int i=1;i<=n+m;i++)
        if(dsu.merge(e[i].u,e[i].v))
            res+=e[i].w;
    printf("%lld\n",res);
    return 0;
}