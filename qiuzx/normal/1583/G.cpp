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
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 400010
using namespace std;
ll n,dp[N],sum[N];
bool vis[N],qry[N];
vector<pair<ll,pair<ll,ll> > > vt;
struct BIT{
	ll val[N];
	void init()
	{
		memset(val,0,sizeof(val));
		return;
	}
	void upd(ll x,ll v)
	{
		x++;
		while(x<N)
		{
			val[x]=(val[x]+v)%mod;
			x+=x&(-x);
		}
		return;
	}
	ll qry(ll x)
	{
		x++;
		ll ret=0;
		while(x>0)
		{
			ret=(ret+val[x])%mod;
			x-=x&(-x);
		}
		return ret;
	}
}bit;
int main(){
	ll i,l,r;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld",&l,&r);
		vt.push_back(make_pair(r,make_pair(l,i)));
	}
	sort(vt.begin(),vt.end());
	scanf("%lld",&r);
	while(r--)
	{
		scanf("%lld",&l);
		vis[l-1]=true;
	}
	bit.init();
	for(i=0;i<vt.size();i++)
	{
		if(vis[vt[i].S.S])
		{
			qry[i]=true;
		}
	}
	for(i=0;i<vt.size();i++)
	{
		dp[i]=(bit.qry(2*n+1)+mod-bit.qry(vt[i].S.F)+1)%mod;
		bit.upd(vt[i].S.F,dp[i]);
	}
	bit.init();
	ll ans=0,cur=0;
	for(i=0;i<vt.size();i++)
	{
		bit.upd(vt[i].S.F,dp[i]);
	}
	for(i=vt.size()-1;i>=0;i--)
	{
		bit.upd(vt[i].S.F,mod-dp[i]);
		if(qry[i]&&vt[i].S.F>cur)
		{
			ans=(ans+bit.qry(2*n+1)+mod-bit.qry(cur)+1)%mod;
			cur=vt[i].S.F;
		}
	}
	printf("%lld\n",ans);
	return 0;
}