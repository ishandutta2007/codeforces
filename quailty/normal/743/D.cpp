#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=200005;
const ll INF=(1LL<<60)-1;
vector<int>e[MAXN];
ll a[MAXN],dp[MAXN],fp[MAXN];
void dfs(int u,int fa,ll &res)
{
    ll mx=-INF;
    dp[u]=a[u];
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i];
        if(v==fa)continue;
        dfs(v,u,res);
        res=max(res,mx+fp[v]);
        mx=max(mx,fp[v]);
        dp[u]+=dp[v];
    }
    fp[u]=max(mx,dp[u]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        dp[i]=fp[i]=-INF;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ll res=-INF;
    dfs(1,0,res);
    if(res<-3e15)printf("Impossible");
    else printf("%lld",res);
    return 0;
}