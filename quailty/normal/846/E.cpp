#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const ll INF=(1LL<<60)-1;
vector<pair<int,int> > e[MAXN];
ll a[MAXN],b[MAXN],dp[MAXN];
void dfs(int u)
{
    dp[u]=b[u]-a[u];
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].first,r=e[u][i].second;
        dfs(v);
        if(dp[v]<0)
        {
            if(-dp[v]<INF/r)
                dp[u]+=dp[v]*r;
            else
                dp[u]=-INF;
            if(dp[u]<-INF)
                dp[u]=-INF;
        }
        else dp[u]+=dp[v];
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&b[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=2;i<=n;i++)
    {
        int x,k;
        scanf("%d%d",&x,&k);
        e[x].push_back(make_pair(i,k));
    }
    dfs(1);
    return 0*printf("%s\n",(dp[1]>=0 ? "YES" : "NO"));
}