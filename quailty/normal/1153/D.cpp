#include<bits/stdc++.h>
using namespace std;
const int MAXN=300005;
vector<int> e[MAXN];
int c[MAXN],dp[MAXN],sz[MAXN];
void dfs(int u)
{
    if(e[u].empty())
    {
        sz[u]=1;
        dp[u]=-1;
        return;
    }
    if(c[u])dp[u]=-MAXN;
    for(auto &v:e[u])
    {
        dfs(v);
        sz[u]+=sz[v];
        if(c[u])dp[u]=max(dp[u],dp[v]);
        else dp[u]+=dp[v];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=2;i<=n;i++)
    {
        int f;
        scanf("%d",&f);
        e[f].push_back(i);
    }
    dfs(1);
    printf("%d\n",dp[1]+sz[1]+1);
    return 0;
}