#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
ll n,r1,r2,r3,d,a[N],dp[N][2],mn1[N],mn2[N],sum[N],mn=LINF;
int main(){
	ll i;
	scanf("%lld%lld%lld%lld%lld",&n,&r1,&r2,&r3,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		mn1[i]=min(r2+r1,r1*a[i]+r1*2);
		mn2[i]=r1*a[i]+r3;
	}
	sum[n-1]=min(mn1[n-1]+2*d,mn2[n-1]);
	for(i=n-2;i>=0;i--)
	{
		sum[i]=sum[i+1]+min(mn1[i],mn2[i]);
	}
	memset(dp,127,sizeof(dp));//dp[i][0]: not extending it to the next one. dp[i][1]: extending it to the next one.
	dp[0][0]=mn2[0];
	dp[0][1]=mn1[0]+2*d;
	for(i=1;i<n;i++)
	{
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+mn2[i];
		dp[i][0]=min(dp[i][0],dp[i-1][1]+mn1[i]);
		dp[i][0]=min(dp[i][0],dp[i-1][0]+mn1[i]+2*d);
		dp[i][1]=min(dp[i-1][0],dp[i-1][1])+mn1[i]+2*d;
		mn=min(mn,min(dp[i-1][0],dp[i-1][1])+sum[i]+d*(n-i-1));
	}
	printf("%lld\n",min(dp[n-1][0],mn)+d*(n-1));
	return 0;
}