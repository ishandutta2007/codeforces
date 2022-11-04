#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
struct DSU
{
    ll fa[MAXN],sz[MAXN],tot;
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            fa[i]=i,sz[i]=1;
        tot=0;
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)return;
        tot+=sz[x]*sz[y];
        fa[x]=y,sz[y]+=sz[x];
    }
}dsu;
int a[MAXN],x[MAXN],y[MAXN];
vector<int> e[MAXN];
ll f[MAXN],g[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),f[a[i]]++;
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        e[__gcd(a[x[i]],a[y[i]])].push_back(i);
    }
    for(int i=1;i<MAXN;i++)
        for(int j=i+i;j<MAXN;j+=i)
        {
            f[i]+=f[j];
            for(auto &t:e[j])
                e[i].push_back(t);
        }
    dsu.init(n);
    for(int i=1;i<MAXN;i++)
    {
        for(auto &t:e[i])
            dsu.merge(x[t],y[t]);
        g[i]=dsu.tot+f[i];
        for(auto &t:e[i])
        {
            dsu.fa[x[t]]=x[t];
            dsu.sz[x[t]]=1;
            dsu.fa[y[t]]=y[t];
            dsu.sz[y[t]]=1;
        }
        dsu.tot=0;
    }
    for(int i=MAXN-1;i>=1;i--)
        for(int j=i+i;j<MAXN;j+=i)
            g[i]-=g[j];
    for(int i=1;i<MAXN;i++)
        if(g[i])printf("%d %lld\n",i,g[i]);
    return 0;
}