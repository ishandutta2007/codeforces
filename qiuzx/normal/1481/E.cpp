#pragma GCC optimize(2)
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
#define N 500010
using namespace std;
ll n,a[N],val[N],dp[N],fst[N],app[N],lst[N];
int main(){
	ll i;
	memset(fst,-1,sizeof(fst));
	memset(app,0,sizeof(app));
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		lst[a[i]]=i;
		if(fst[a[i]]==-1)
		{
			fst[a[i]]=i;
		}
	}
	memset(val,63,sizeof(val));
	memset(dp,63,sizeof(dp));
	dp[n]=0;
	for(i=n-1;i>=0;i--)
	{
		app[a[i]]++;
		val[i]=min(val[i],val[i+1]+1);
		dp[i]=min(dp[i],val[i]);
		if(i==fst[a[i]])
		{
			dp[i]=min(dp[i],dp[lst[a[i]]+1]+(lst[a[i]]-i+1-app[a[i]]));
		}
		dp[i]=min(dp[i],n-i-app[a[i]]);
		val[fst[a[i]]]=min(val[fst[a[i]]],n-i-app[a[i]]+i-fst[a[i]]);
		val[i]=min(val[i],dp[i]);
	}
	/*for(i=0;i<n;i++)
	{
		cout<<dp[i]<<" ";
	}
	puts("");*/
	printf("%lld\n",dp[0]);
	return 0;
}