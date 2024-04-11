#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<map>
#define LL long long
using namespace std;
int n,a[300010];
LL dp[300010][42],ans;
int main() {
    //freopen("c.in","r",stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i <n; i++)scanf("%d", &a[i]);
    for (int i=0;i<=n;i++)
	for (int j=0;j<=30;j++) dp[i][j]=300000000000LL;
	dp[0][0]=0;
    for (int i=0;i<n;i++)
    for (int j=0;j<=30;j++){
		if (j+a[i]/1000<=30) dp[i+1][j+a[i]/1000]=min(dp[i+1][j+a[i]/1000],dp[i][j]+a[i]);
		if (j*100>=a[i]) dp[i+1][j-a[i]/100]=min(dp[i+1][j-a[i]/100],dp[i][j]);
		else dp[i+1][0]=min(dp[i+1][0],dp[i][j]+a[i]-j*100);
    }
    ans=dp[n][0];
    for (int i=1;i<=30;i++) ans=min(ans,dp[n][i]);
	printf("%lld\n",ans);
}