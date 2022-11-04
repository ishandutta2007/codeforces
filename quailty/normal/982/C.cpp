#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
vector<int> e[MAXN];
int dp[MAXN];
void dfs(int u,int f)
{
    dp[u]=1;
    for(auto &v:e[u])
    {
        if(v==f)continue;
        dfs(v,u);
        dp[u]+=dp[v];
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
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(n&1)return 0*printf("-1\n");
    dfs(1,0);
    int res=0;
    for(int i=2;i<=n;i++)
        res+=(dp[i]%2==0);
    printf("%d\n",res);
    return 0;
}