#include<bits/stdc++.h>
using namespace std;
const int MAXN=300005;
vector<int> e[MAXN];
char str[MAXN];
int vis[MAXN],cir;
void dfs1(int u)
{
    cir|=(vis[u]==1);
    if(vis[u])return;
    vis[u]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dfs1(v);
    }
    vis[u]=2;
}
int dp[MAXN];
void dfs2(int u,int sp)
{
    if(vis[u])return;
    vis[u]=1;
    int mx=0;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dfs2(v,sp);
        mx=max(mx,dp[v]);
    }
    dp[u]=mx+(str[u]-'a'==sp);
}
int main()
{
    int n,m;
    scanf("%d%d%s",&n,&m,str+1);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs1(i);
    if(cir)return 0*printf("-1\n");
    int res=0;
    for(int _=0;_<26;_++)
    {
        for(int i=1;i<=n;i++)
            dp[i]=vis[i]=0;
        for(int i=1;i<=n;i++)
            if(!vis[i])dfs2(i,_);
        for(int i=1;i<=n;i++)
            res=max(res,dp[i]);
    }
    return 0*printf("%d\n",res);
}