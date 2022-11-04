#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=755;
const ll INF=(1LL<<62)-1;
ll a[MAXN],dp[MAXN][MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);
    for(int i=1;i<=n+1;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=INF;
    dp[n+1][0]=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<=n;j++)
            dp[i][j]=min(dp[i][j],max(0LL,dp[i+1][j]-a[i]));
        for(int j=1;j<=n;j++)
            dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
    }
    while(m--)
    {
        ll b;
        scanf("%I64d",&b);
        printf("%d\n",lower_bound(dp[1],dp[1]+n+1,b,greater<ll>())-dp[1]);
    }
    return 0;
}