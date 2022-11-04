#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int up[MAXN],dis[MAXN],val[MAXN];
vector<int> e[MAXN],idx[MAXN];
void dfs1(int u,int f)
{
    up[u]=f,dis[u]=dis[f]+1;
    for(auto &v:e[u])
        if(v!=f)dfs1(v,u);
}
int vis[MAXN];
vector<int> g[MAXN],tmp;
void dfs2(int u,int f)
{
    tmp.push_back(u);
    vis[u]=1,dis[u]=dis[f]+1;
    for(auto &v:g[u])
        if(!vis[v])dfs2(v,u);
}
int get_max(int d)
{
    for(auto &t:idx[d])
        val[t]=1;
    for(auto &t:idx[d])
        if(val[t] && val[up[t]])
        {
            g[t].push_back(up[t]);
            g[up[t]].push_back(t);
        }
    for(auto &t:idx[d])
        vis[t]=0;
    int res=0;
    for(auto &t:idx[d])
    {
        if(vis[t])continue;
        dfs2(t,0);
        int u=t;
        for(auto &r:tmp)
            if(dis[r]>dis[u])
                u=r;
        for(auto &r:tmp)
            vis[r]=0;
        tmp.clear();
        dfs2(u,0);
        int v=u;
        for(auto &r:tmp)
            if(dis[r]>dis[v])
                v=r;
        tmp.clear();
        res=max(res,dis[v]);
    }
    for(auto &t:idx[d])
        g[t].clear();
    for(auto &t:idx[d])
        val[t]=0;
    return res;
}
int np[MAXN];
void build()
{
    for(int i=2;i<MAXN;i++)if(!np[i])
        for(int j=i+i;j<MAXN;j+=i)np[j]=1;
}
int main()
{
    build();
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        idx[a].push_back(i);
    }
    for(int i=2;i<MAXN;i++)
        if(!np[i])for(int j=i+i;j<MAXN;j+=i)
            for(auto &t:idx[j])
                idx[i].push_back(t);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(1,0);
    int res=0;
    for(int i=2;i<MAXN;i++)
        if(!np[i] && !idx[i].empty())
            res=max(res,get_max(i));
    printf("%d\n",res);
    return 0;
}