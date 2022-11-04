#include<bits/stdc++.h>
using namespace std;

const int MAXN=100005;
const int MAXM=500005;

int u[MAXM],v[MAXM];
vector<int> e[MAXN],r[MAXN];

int vis[MAXN],fa[MAXN];
int usd_node[MAXN],usd_edge[MAXM];
vector<int> cir_node;

void dfs1(int u)
{
    vis[u]=1;
    for(auto id:e[u])
    {
        int v=::v[id];
        if(usd_node[v]>=0 || vis[v]==2)continue;
        fa[v]=id;
        if(vis[v]==1)
        {
            int t=v;
            do
            {
                cir_node.push_back(t);
                usd_edge[fa[t]]=1;
                t=::u[fa[t]];
            }
            while(t!=v);
            reverse(cir_node.begin(),cir_node.end());
            throw 1;
        }
        else dfs1(v);
    }
    vis[u]=2;
}

int dp[MAXN];

void dfs2(int u)
{
    vis[u]=1;
    if(usd_node[u]>=0)
    {
        dp[u]=usd_node[u];
        return;
    }
    for(auto &id:e[u])
    {
        int v=::v[id];
        if(usd_edge[id])continue;
        if(!vis[v])dfs2(v);
        dp[u]=min(dp[u],dp[v]);
    }
}

void dfs3(int u)
{
    vis[u]=1;
    if(usd_node[u]>=0)
    {
        dp[u]=usd_node[u];
        return;
    }
    for(auto &id:r[u])
    {
        int v=::u[id];
        if(usd_edge[id])continue;
        if(!vis[v])dfs3(v);
        dp[u]=max(dp[u],dp[v]);
    }
}

void dfs4(int u)
{
    vis[u]=1;
    if(usd_node[u]>=0)
    {
        dp[u]=usd_node[u];
        return;
    }
    for(auto &id:e[u])
    {
        int v=::v[id];
        if(usd_edge[id])continue;
        if(!vis[v])dfs4(v);
        dp[u]=max(dp[u],dp[v]);
    }
}

int del[MAXN];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        e[u[i]].push_back(i);
        r[v[i]].push_back(i);
    }
    memset(usd_node,-1,sizeof(usd_node));
    try
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            if(!vis[i])dfs1(i);
    }
    catch(...)
    {
        for(int i=0;i<(int)cir_node.size();i++)
            usd_node[cir_node[i]]=i;
    };
    try
    {
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
            if(usd_node[i]<0 && !vis[i])dfs1(i);
    }
    catch(...)
    {
        return 0*printf("-1\n");
    };
    memset(vis,0,sizeof(vis));
    memset(dp,1,sizeof(dp));
    for(int i=0;i<(int)cir_node.size();i++)
    {
        int u=cir_node[i],res=n+1;
        for(auto &id:e[u])
        {
            if(usd_edge[id])continue;
            int v=::v[id];
            if(!vis[v])dfs2(v);
            res=min(res,dp[v]);
        }
        if(res<=i)del[i+1]++;
    }
    memset(vis,0,sizeof(vis));
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<(int)cir_node.size();i++)
    {
        int u=cir_node[i],res=-1;
        for(auto &id:r[u])
        {
            if(usd_edge[id])continue;
            int v=::u[id];
            if(!vis[v])dfs3(v);
            res=max(res,dp[v]);
        }
        if(res>=i)del[0]++,del[i]--;
    }
    memset(vis,0,sizeof(vis));
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<(int)cir_node.size();i++)
    {
        int u=cir_node[i],res=-1;
        for(auto &id:e[u])
        {
            if(usd_edge[id])continue;
            int v=::v[id];
            if(!vis[v])dfs4(v);
            res=max(res,dp[v]);
        }
        if(res>i)del[i+1]++,del[res]--;
    }
    for(int i=1;i<(int)cir_node.size();i++)
        del[i]+=del[i-1];
    int res=-1;
    for(int i=0;i<(int)cir_node.size();i++)
        if(!del[i])res=cir_node[i];
    return 0*printf("%d\n",res);
}