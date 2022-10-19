//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll rint(){
	ll ret=0,uu=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-') uu=-1,c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret*uu;
}
ll n,a[N],dp[N];
int main(){
	n=rint();
	for(int i=0;i<n;++i)
	{
		a[i]=rint();
		dp[i+1]=-LINF;
	}
	dp[0]=0;
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j>0;--j)
		{
			dp[j]=max(dp[j],dp[j-1]+j*a[i]);
		}
	}
	ll ans=0;
	for(int i=0;i<=n;++i)
	{
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}