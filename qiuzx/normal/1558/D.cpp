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
			val[x]+=v;
			x+=x&(-x);
		}
		return;
	}
	ll qry(ll x)
	{
		ll ret=0;
		++x;
		while(x)
		{
			ret+=val[x];
			x-=x&(-x);
		}
		return ret;
	}
}bit;
ll fact[N],inv[N],inv_fac[N];
ll C(ll x,ll y){return (x<y||x<0||y<0)?0:(fact[x]*((inv_fac[y]*inv_fac[x-y])%mod))%mod;}
ll n,m;
ll calc(ll x)
{
	ll l=0,r=n,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(bit.qry(mid)<x)
		{
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	return (bit.qry(l)==x)?l:0;
}
int main(){
	ll i,T,x,y;
	fact[0]=inv_fac[0]=inv[1]=inv_fac[1]=fact[1]=1;
	for(i=2;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
		inv_fac[i]=(inv_fac[i-1]*inv[i])%mod;
	}
	scanf("%lld",&T);
	for(i=0;i<N;i++)
	{
		bit.upd(i,1);
	}
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		vector<pair<ll,ll> > seq;
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&x,&y);
			seq.push_back(make_pair(x,y));
		}
		reverse(seq.begin(),seq.end());
		ll tot=0;
		vector<ll> upd;
		for(i=0;i<seq.size();i++)
		{
			y=seq[i].S;
			ll p=calc(y),q=calc(y+1);
			if(p+1==q)
			{
				tot++;
			}
			bit.upd(p,-1);
			upd.push_back(p);
		}
		printf("%lld\n",C(n+n-tot-1,n));
		for(i=0;i<upd.size();i++)
		{
			bit.upd(upd[i],1);
		}
	}
	return 0;
}