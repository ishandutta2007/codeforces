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
#define N 200010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
ll n,a[N],dp[N],f[N],curv[N];
multiset<pair<ll,ll> > val[20];
int main(){
	ll T=rint(),i,j;
	f[0]=1;
	for(i=1;i<N;i++)
	{
		f[i]=f[i-1]-1;
		if(f[i]==-1)
		{
			f[i]=2*(i-1)-i;
		}
	}
	while(T--)
	{
		n=rint();
		for(i=0;i<n;i++)
		{
			a[i]=rint();
		}
		sort(a,a+n);
		for(i=0;i<20;i++)
		{
			val[i].clear();
		}
		for(i=0;i<n;i++)
		{
			if(i==0||(a[i]!=a[i-1]))
			{
				val[0].insert(make_pair(f[i]+i,i));
			}
			for(j=0;j<19;j++)
			{
				if(i>=(1<<j))
				{
					if(val[j].find(make_pair(f[i-(1<<j)]+(i-(1<<j)),i-(1<<j)))!=val[j].end())
					{
						val[j].erase(make_pair(f[i-(1<<j)]+(i-(1<<j)),i-(1<<j)));
						val[j+1].insert(make_pair(f[i-(1<<j)]+(i-(1<<j)),i-(1<<j)));
					}
				}
			}
			dp[i]=f[i+1]+1;
			for(j=0;j<20;j++)
			{
				if(!val[j].empty())
				{
					dp[i]=min(dp[i],(*val[j].begin()).F+(1<<j)-i-1);
				}
			}
		}
		ll ans=min(f[n]+2,1+dp[n-1]);
		for(i=1;i<n;i++)
		{
			if(a[i]!=a[i-1])
			{
				ans=min(ans,f[n-i]+dp[i-1]);
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}