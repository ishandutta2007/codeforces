#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
int a[MAXN];
pair<int,ll> dp[MAXN][2];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        dp[0][0]=dp[0][1]={0,0};
        int n;
        scanf("%d",&n);
        for(int i=1,a;i<=n;i++)
        {
            scanf("%d",&a);
            dp[i][0]=dp[i-1][0],dp[i][1]=dp[i-1][1];
            if(a>0)dp[i][0]=max(dp[i][0],{dp[i-1][1].first+1,dp[i-1][1].second+a});
            else dp[i][1]=max(dp[i][1],{dp[i-1][0].first+1,dp[i-1][0].second+a});
        }
        pair<int,ll> res=max(dp[n][0],dp[n][1]);
        printf("%lld\n",res.second);
    }
    return 0;
}