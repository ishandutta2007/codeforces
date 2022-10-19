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
#define N 400010
using namespace std;
struct BIT{
	ll val[N];
	void upd(ll x,ll v)
	{
		++x;
		while(x<N)
		{
			val[x]=max(val[x],v);
			x+=x&(-x);
		}
		return;
	}
	ll qry(ll x)
	{
		ll ret=0;
		++x;
		while(x>0)
		{
			ret=max(ret,val[x]);
			x-=x&(-x);
		}
		return ret;
	}
}bit1,bit2,bit3;
ll n,a[N],f[N],g[N],p[N],ans=INF;
vector<ll> allv;
int main(){
	ll i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]-=i;
		allv.push_back(a[i]);
		allv.push_back(a[i]+1);
	}
	sort(allv.begin(),allv.end());
	allv.erase(unique(allv.begin(),allv.end()),allv.end());
	for(i=0;i<n;i++)
	{
		ll x=lower_bound(allv.begin(),allv.end(),a[i])-allv.begin(),y=lower_bound(allv.begin(),allv.end(),a[i]+1)-allv.begin();
		p[i]=x;
		f[i]=bit1.qry(x)+1;
		g[i]=max(bit2.qry(y),bit3.qry(x))+1;
		bit1.upd(x,f[i]);
		if(i)
		{
			bit2.upd(p[i-1],f[i-1]+1);
		}
		else
		{
			bit2.upd(0,1);
		}
		bit3.upd(x,g[i]);
	}
	f[n-1]--;
	for(i=0;i<n;i++)
	{
		ans=min(ans,n-max(f[i]+1,g[i]));
	}
	printf("%lld\n",ans);
	return 0;
}