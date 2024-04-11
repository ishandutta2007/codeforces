#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int MAXD=31;
const ll INF=(1LL<<60)-1;
int solve()
{
    int n,k;
    scanf("%d%d",&n,&k);
    ll dp[2][MAXD];
    int now=0,la=1;
    for(int j=0;j<MAXD;j++)
        dp[now][j]=-INF*(j>0);
    for(int i=1;i<=n;i++)
    {
        swap(now,la);
        for(int j=0;j<MAXD;j++)
            dp[now][j]=-INF;
        int a;
        scanf("%d",&a);
        for(int j=0;j<MAXD;j++)
        {
            dp[now][j]=max(dp[now][j],dp[la][j]+(a>>j)-k*(j+1<MAXD));
            if(j)dp[now][j]=max(dp[now][j],dp[la][j-1]+(a>>j));
        }
    }
    ll res=-INF;
    for(int j=0;j<MAXD;j++)
        res=max(res,dp[now][j]);
    return 0*printf("%lld\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}