#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=100005;
vector<int>tree[MAXN];
int col[MAXN],dp[MAXN],mx[MAXN];
void dfs1(int u,int fa)
{
    dp[u]=1;
    for(int i=0;i<(int)tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v==fa || col[v])continue;
        dfs1(v,u);
        dp[u]+=dp[v];
    }
}
void dfs2(int u,int fa,int rt,int &res)
{
    mx[u]=dp[rt]-dp[u];
    for(int i=0;i<(int)tree[u].size();i++)
    {
        int v=tree[u][i];
        if(v==fa || col[v])continue;
        dfs2(v,u,rt,res);
        mx[u]=max(mx[u],dp[v]);
    }
    if(2*mx[u]<=dp[rt])res=u;
}
int get_root(int u)
{
    dfs1(u,0);
    int rt=u;
    dfs2(u,0,u,rt);
    return rt;
}
void solve(int u,int dep)
{
    u=get_root(u);
    col[u]=dep;
    for(int i=0;i<(int)tree[u].size();i++)
    {
        int v=tree[u][i];
        if(!col[v])solve(v,dep+1);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    solve(1,1);
    for(int i=1;i<=n;i++)
        printf("%c ",col[i]-1+'A');
    return 0;
}