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
#define N 500010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,mxv=0,a[N],otv[N],dp[N][2],ans=0;
void solve()
{
	ll i,id,l1=0,l2=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==mxv)
		{
			id=i;
			break;
		}
	}
	for(i=0;i<=id;i++)
	{
		if(a[i]<l2)
		{
			return;
		}
		if(a[i]>l1)
		{
			l1=a[i];
		}
		else
		{
			l2=a[i];
		}
	}
	ll prev=l2,mxt;
	l1=l2=0;
	for(i=n-1;i>=id;i--)
	{
		mxt=i+1;
		if(a[i]<l2)
		{
			break;
		}
		if(a[i]>l1)
		{
			l1=a[i];
			otv[i]=l2;
		}
		else
		{
			l2=a[i];
			otv[i]=l1;
		}
	}
	dp[id][1]=prev;
	dp[id][0]=-LINF;
	for(i=id+1;i<n;i++)
	{
		dp[i][0]=-LINF,dp[i][1]=LINF;
		if(a[i]>a[i-1])
		{
			dp[i][0]=max(dp[i][0],dp[i-1][0]);
		}
		if(a[i]<a[i-1])
		{
			dp[i][1]=min(dp[i][1],dp[i-1][1]);
		}
		if(a[i]>dp[i-1][1])
		{
			dp[i][0]=max(dp[i][0],a[i-1]);
		}
		if(a[i]<dp[i-1][0])
		{
			dp[i][1]=min(dp[i][1],a[i-1]);
		}
	}
	for(i=mxt;i<n;i++)
	{
		if(dp[i][0]>otv[i])
		{
			ans++;
		}
	}
	return;
}
int main(){
	ll i;
	n=rint();
	for(i=0;i<n;i++)
	{
		a[i]=rint();
		mxv=max(mxv,a[i]);
	}
	solve();
	reverse(a,a+n);
	solve();
	printf("%lld\n",ans);
	return 0;
}