#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
vector<int>e[MAXN];
int dp[MAXN];
int dfs(int u,int fa)
{
    int res=0,mx=0;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        res=max(res,dfs(v,u));
        res=max(res,dp[v]+mx);
        mx=max(mx,dp[v]);
    }
    dp[u]=mx+1;
    return res;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    return 0*printf("%d",dfs(1,0));
}