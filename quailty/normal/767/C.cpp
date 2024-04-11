#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1000005;
vector<int>e[MAXN];
int rt,tot,t[MAXN],dp[MAXN],sum[MAXN];
void dfs(int u)
{
    sum[u]=t[u];
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        dfs(v);
        sum[u]+=sum[v];
        if(dp[u] && dp[v])
        {
            printf("%d %d\n",dp[u],dp[v]);
            exit(0);
        }
        dp[u]=max(dp[u],dp[v]);
    }
    if(u!=rt && sum[u]*3==tot*2)
        for(int i=0;i<(int)e[u].size();i++)
        {
            int v=e[u][i];
            if(dp[v])
            {
                printf("%d %d\n",u,dp[v]);
                exit(0);
            }
        }
    if(sum[u]*3==tot)dp[u]=u;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int fa;
        scanf("%d%d",&fa,&t[i]);
        if(fa)e[fa].push_back(i);
        else rt=i;
        tot+=t[i];
    }
    if(tot%3)return 0*printf("-1");
    dfs(rt);
    return 0*printf("-1");
}