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
ll n,q,a[N],f[20][20][N],g[20][20][N],lg[N];
ll qf(ll l,ll r,ll id)
{
	if(l==0&&r==n-1)
	{
		return 0;
	}
	if(l>r)
	{
		return INF;
	}
	return min(f[id][lg[r-l+1]][l],f[id][lg[r-l+1]][r-(1<<lg[r-l+1])+1]);
}
ll qg(ll l,ll r,ll id)
{
	if(l==0&&r==n-1)
	{
		return n-1;
	}
	if(l>r)
	{
		return -INF;
	}
	return max(g[id][lg[r-l+1]][l],g[id][lg[r-l+1]][r-(1<<lg[r-l+1])+1]);
}
int main(){
	ll i,j,k;
	lg[1]=0;
	for(i=2;i<N;i++)
	{
		lg[i]=lg[i>>1]+1;
	}
	memset(f,63,sizeof(f));
	memset(g,-63,sizeof(g));
	scanf("%lld%lld",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		f[0][0][i]=g[0][0][i]=a[i]-1;
	}
	for(i=1;i<20;i++)
	{
		for(j=0;j+(1<<i)<=n;j++)
		{
			f[0][i][j]=min(f[0][i-1][j],f[0][i-1][j+(1<<(i-1))]);
			g[0][i][j]=max(g[0][i-1][j],g[0][i-1][j+(1<<(i-1))]);
		}
	}
	for(i=1;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			for(k=0;k+(1<<j)<=n;k++)
			{
				f[i][j][k]=qf(f[i-1][j][k],g[i-1][j][k],i-1);
				g[i][j][k]=qg(f[i-1][j][k],g[i-1][j][k],i-1);
			}
		}
	}
	while(q--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		l--,r--;
		if(l==0&&r==n-1)
		{
			puts("0");
			continue;
		}
		if(qf(l,r,19)!=0||qg(l,r,19)!=n-1)
		{
			puts("-1");
			continue;
		}
		ll ans=1;
		for(i=19;i>=0;i--)
		{
			ll nl=qf(l,r,i),nr=qg(l,r,i);
			if(nl!=0||nr!=n-1)
			{
				ans+=(1<<i);
				l=nl,r=nr;
			}
		}
		ans-=(l==0&&r==n-1);
		printf("%lld\n",ans);
	}
	return 0;
}