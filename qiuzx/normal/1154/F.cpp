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
#define N 200010
using namespace std;
ll n,m,k,sum[N],a[N],get_free[N],dp[N];
int main(){
	ll i,j,x,y;
	scanf("%lld%lld%lld",&n,&m,&k);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(i=0;i<n;i++)
	{
		sum[i+1]=sum[i]+a[i];
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&x,&y);
		if(x<=k)
		{
			get_free[x]=max(get_free[x],y);
		}
	}
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(i=0;i<=k;i++)
	{
		for(j=1;j+i<=k;j++)
		{
			dp[i+j]=min(dp[i+j],dp[i]+sum[i+j]-sum[i+get_free[j]]);
		}
	}
	printf("%lld\n",dp[k]);
	return 0;
}