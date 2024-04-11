#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2005;
const int Mod=1000000007;
vector<int>e[MAXN];
int a[MAXN],dp[MAXN];
void dfs(int u,int fa,int &rt,int &d)
{
    dp[u]=1;
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa || a[v]>a[rt]+d)continue;
        if(a[v]<a[rt] || (a[v]==a[rt] && v<rt))continue;
        dfs(v,u,rt,d);
        dp[u]=1LL*dp[u]*(dp[v]+1)%Mod;
    }
}
int main()
{
    int d,n;
    scanf("%d%d",&d,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int res=0;
    for(int i=1;i<=n;i++)
    {
        memset(dp,0,sizeof(dp));
        dfs(i,0,i,d);
        res=(res+dp[i])%Mod;
    }
    return 0*printf("%d",res);
}