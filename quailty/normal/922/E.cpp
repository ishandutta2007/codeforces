#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=1005;
const int MAXC=10005;
const ll INF=(1LL<<60)-1;
int c[MAXN];
ll cost[MAXN],dp[MAXN][MAXC];
int main()
{
    int n;
    ll W,B,X;
    scanf("%d%lld%lld%lld",&n,&W,&B,&X);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        scanf("%lld",&cost[i]);
    for(int j=0;j<MAXC;j++)
        dp[0][j]=(j==0 ? W : -INF);
    for(int i=1;i<=n;i++)
    {
        deque<pair<ll,int> > dq;
        for(int j=0;j<MAXC;j++)
        {
            ll t=dp[i-1][j]+j*cost[i];
            while(!dq.empty() && dq.back().first<=t)dq.pop_back();
            dq.push_back({t,j});
            while(!dq.empty() && dq.front().second<j-c[i])dq.pop_front();
            dp[i][j]=(dq.empty() ? -INF : dq.front().first)-j*cost[i];
            if(dp[i][j]<0)dp[i][j]=-INF;
            else dp[i][j]=min(W+B*j,dp[i][j]+X);
        }
    }
    int res=0;
    for(int j=0;j<MAXC;j++)
        if(dp[n][j]>=0)res=j;
    return 0*printf("%d\n",res);
}