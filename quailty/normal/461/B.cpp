#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
int x[MAXN],dp[MAXN][2];
vector<int>e[MAXN];
void dfs(int u,int fa)
{
    dp[u][x[u]]=1,dp[u][x[u]^1]=0;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs(v,u);
        int t[2];
        t[0]=1LL*dp[u][0]*(dp[v][0]+dp[v][1])%Mod;
        t[1]=(1LL*dp[u][0]*dp[v][1]+1LL*dp[u][1]*(dp[v][0]+dp[v][1]))%Mod;
        dp[u][0]=t[0];
        dp[u][1]=t[1];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int p;
        scanf("%d",&p);
        e[p].push_back(i+1);
        e[i+1].push_back(p);
    }
    for(int i=0;i<=n-1;i++)
        scanf("%d",&x[i]);
    dfs(0,-1);
    printf("%d\n",dp[0][1]);
    return 0;
}