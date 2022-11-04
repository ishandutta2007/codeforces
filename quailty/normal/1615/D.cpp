#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<pair<int,int>> e[MAXN];
int vis[MAXN];
void dfs(int u)
{
    for(auto& [v,w]:e[u])
    {
        if(vis[v]<0)
        {
            vis[v]=vis[u]^w;
            dfs(v);
        }
        else if(vis[v]!=(vis[u]^w))
            throw -1;
    }
}
int u[MAXN],v[MAXN],w[MAXN];
int solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        e[i].clear();
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&u[i],&v[i],&w[i]);
        if(w[i]>=0)
        {
            e[u[i]].emplace_back(v[i],__builtin_parity(w[i]));
            e[v[i]].emplace_back(u[i],__builtin_parity(w[i]));
        }
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e[u].emplace_back(v,w);
        e[v].emplace_back(u,w);
    }
    for(int i=1;i<=n;i++)vis[i]=-1;
    try
    {
        for(int i=1;i<=n;i++)
        {
            if(vis[i]>=0)continue;
            vis[i]=0,dfs(i);
        }
        printf("YES\n");
        for(int i=1;i<n;i++)
            printf("%d %d %d\n",u[i],v[i],(w[i]<0 ? vis[u[i]]^vis[v[i]] : w[i]));
    }
    catch(...) { printf("NO\n"); }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}