#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=(1LL<<62)-1;
ll a[100005][3],dp[100005][3];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<3;i++)
        for(int j=1;j<=n;j++)
            scanf("%lld",&a[j][i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<3;j++)
            dp[i][j]=-INF;
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
            {
                ll tmp=0;
                for(int t=min(j,k);t<=max(j,k);t++)
                    tmp+=a[i][t];
                dp[i][j]=max(dp[i][j],dp[i-1][k]+tmp);
            }
        if(i>=2)
        {
            ll tmp=0;
            for(int j=0;j<3;j++)
                tmp+=a[i][j]+a[i-1][j];
            dp[i][0]=max(dp[i][0],dp[i-2][2]+tmp);
            dp[i][2]=max(dp[i][2],dp[i-2][0]+tmp);
        }
    }
    printf("%lld",dp[n][2]);
    return 0;
}