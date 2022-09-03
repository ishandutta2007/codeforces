#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
const int N=100005;
vector<int> g[N];
const int mod=1e9+7;
ll dp[N][2];
int color[N];
int n;
void dfs(int x)
{
    dp[x][0]=1;
    dp[x][1]=0;
    for(int i=0;i<g[x].size();i++)
    {
        dfs(g[x][i]);
        dp[x][1]=(dp[x][1]*dp[g[x][i]][0]+dp[x][0]*dp[g[x][i]][1])%mod;
        dp[x][0]=dp[x][0]*dp[g[x][i]][0]%mod;
    }
    if(color[x]==1) dp[x][1]=dp[x][0];
    else dp[x][0]=(dp[x][0]+dp[x][1])%mod;
}
int main()
{
    scanf("%d",&n);
    for(int i=1,p;i<n;i++)
    {
        scanf("%d",&p);
        g[p].push_back(i);
    }
    for(int i=0;i<n;i++) scanf("%d",color+i);
    dfs(0);
    printf("%I64d\n",dp[0][1]);
    return 0;
}