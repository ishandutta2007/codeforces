//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC target("f16c,xop,fma,fma4,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 110
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,m,a[N][N],dp[N][N];
ll calc(ll x)
{
	ll i,j;
	if(a[0][0]>=x)
	{
		dp[0][0]=a[0][0]-x;
	}
	else
	{
		dp[0][0]=LINF;
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if(i==0&&j==0)
			{
				continue;
			}
			dp[i][j]=LINF;
			if(a[i][j]<x)
			{
				continue;
			}
			if(i>0)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j]+a[i][j]-x);
			}
			if(j>0)
			{
				dp[i][j]=min(dp[i][j],dp[i][j-1]+a[i][j]-x);
			}
		}
	}
	return dp[n-1][m-1];
}
int main(){
	ll T=rint(),i,j;
	while(T--)
	{
		n=rint(),m=rint();
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				a[i][j]=rint();
				a[i][j]-=(i+j);
			}
		}
		ll ans=LINF;
		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
			{
				ans=min(ans,calc(a[i][j]));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}