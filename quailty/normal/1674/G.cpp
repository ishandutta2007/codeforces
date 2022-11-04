#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN],r[MAXN];
int dp[MAXN];
int dfs(int u)
{
    if(dp[u])return dp[u];
    dp[u]=1;
    if(e[u].size()!=1u)for(auto v:e[u])
    {
        if(r[v].size()==1u)continue;
        dp[u]=max(dp[u],dfs(v)+1);
    }
    return dp[u];
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        r[v].push_back(u);
    }
    int res=0;
    for(int i=1;i<=n;i++)
        res=max(res,dfs(i));
    return 0*printf("%d\n",res);
}