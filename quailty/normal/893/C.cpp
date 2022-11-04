#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
struct DSU
{
    int fa[MAXN],w[MAXN];
    void init(int n)
    {
        for(int i=1;i<=n;i++)
            fa[i]=i;
    }
    int find(int x)
    {
        return fa[x]==x ? x : fa[x]=find(fa[x]);
    }
    void merge(int x,int y)
    {
        x=find(x),y=find(y);
        if(x==y)return;
        fa[y]=x;
        w[x]=min(w[x],w[y]);
    }
}dsu;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    dsu.init(n);
    for(int i=1;i<=n;i++)
        scanf("%d",&dsu.w[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        dsu.merge(u,v);
    }
    ll res=0;
    for(int i=1;i<=n;i++)
        if(dsu.find(i)==i)res+=dsu.w[i];
    printf("%lld\n",res);
    return 0;
}