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
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll int
#define N 4010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,k,a[N][N],sum[N][N],f[N],lst[N];
void solve(ll l,ll r,ll cl,ll cr)
{
	if(l>r)
	{
		return;
	}
	ll i,mid=(l+r)>>1,c;
	f[mid]=INF;
	for(i=cl;i<=cr;i++)
	{
		if(f[mid]>lst[i]+sum[mid][mid]-sum[mid][i]-sum[i][mid]+sum[i][i])
		{
			f[mid]=lst[i]+sum[mid][mid]-sum[mid][i]-sum[i][mid]+sum[i][i];
			c=i;
		}
	}
	solve(l,mid-1,cl,c);
	solve(mid+1,r,c,cr);
	return;
}
int main(){
	ll i,j;
	n=rint(),k=rint();
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			a[i][j]=rint();
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
		for(j=1;j<=n;j++)
		{
			sum[i][j]+=sum[i-1][j];
		}
	}
	lst[0]=0;
	for(i=1;i<=n;i++)
	{
		lst[i]=INF;
	}
	for(i=1;i<=k;i++)
	{
		solve(1,n,0,n);
		for(j=0;j<=n;j++)
		{
			lst[j]=f[j];
		}
	}
	printf("%d\n",lst[n]/2);
	return 0;
}