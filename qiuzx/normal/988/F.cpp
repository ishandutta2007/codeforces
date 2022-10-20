//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 2010
using namespace std;
ll a,m,n,mn_umb[N],dp[N][N];
bool in_rain[N];
int main(){
	ll i,l,r,j;
	scanf("%lld%lld%lld",&a,&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&l,&r);
		for(j=l+1;j<=r;j++)
		{
			in_rain[j]=true;
		}
	}
	a++;
	for(i=0;i<=a;i++)
	{
		mn_umb[i]=INF;
		for(j=0;j<=a;j++)
		{
			dp[i][j]=INF*2;
		}
	}
	mn_umb[0]=0;
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&l,&r);
		mn_umb[l+1]=min(mn_umb[l+1],r);
	}
	dp[0][0]=0;
	for(i=1;i<=a;i++)
	{
		for(j=0;j<=i;j++)
		{
			dp[i][i]=min(dp[i][i],dp[i-1][j]+mn_umb[j]);
			if(!in_rain[i])
			{
				dp[i][0]=min(dp[i][0],dp[i-1][j]+mn_umb[j]);
			}
		}
		for(j=1;j<i;j++)
		{
			dp[i][j]=min(dp[i][j],dp[i-1][j]+mn_umb[j]);
		}
	}
	ll ans=INF;
	for(i=0;i<=a;i++)
	{
		ans=min(ans,dp[a][i]);
	}
	if(ans>=INF)
	{
		ans=-1;
	}
	printf("%lld\n",ans);
	return 0;
}