#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
vector<int> e[MAXN];
int dp[MAXN],dep[MAXN];
void dfs(int u,int fa)
{
    for(auto v : e[u])
    {
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        dp[u]+=dp[v];
    }
}
int solve()
{
    int n,k,x,y;
    scanf("%d%d%d%d",&n,&k,&x,&y);
    dp[x]++,dp[y]++;
    for(int i=1;i<=k;i++)
    {
       int a;
       scanf("%d",&a);
       dp[a]++;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(x,0);
    int cnt=0;
    for(int i=1;i<=n;i++)
        cnt+=(dp[i]>0 && dp[i]<k+2);
    printf("%d\n",2*cnt-dep[y]);
    for(int i=1;i<=n;i++)
        e[i].clear(),dp[i]=dep[i]=0;
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}