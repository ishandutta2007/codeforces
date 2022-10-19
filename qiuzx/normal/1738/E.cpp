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
ll fact[N],inv[N],inv_fac[N];
ll C(ll x,ll y){return (x<y||x<0||y<0)?0:(fact[x]*((inv_fac[y]*inv_fac[x-y])%mod))%mod;}
ll n,a[N],sum[N];
map<ll,vector<ll> > mp1,mp2;
int main(){
	ll T,i;
	fact[0]=inv_fac[0]=inv[1]=inv_fac[1]=fact[1]=1;
	for(i=2;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
		inv_fac[i]=(inv_fac[i-1]*inv[i])%mod;
	}
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		mp1.clear();
		mp2.clear();
		for(i=1;i<n;i++)
		{
			mp1[sum[i]].push_back(i);
			mp2[sum[n]-sum[i]].push_back(i);
		}
		ll ans=1;
		for(map<ll,vector<ll> >::iterator it=mp1.begin();it!=mp1.end();it++)
		{
			ll val=it->F,lo=it->S[0],hi=it->S[it->S.size()-1];
			if(mp2.count(val))
			{
				ll l=mp2[val][0],r=mp2[val][mp2[val].size()-1];
				if(lo>l)
				{
					continue;
				}
				if(hi<l)
				{
					ll coef=0;
					for(i=0;i<=r-l+1;i++)
					{
						coef=(coef+C(r-l+1,i)*C(hi-lo+1,i))%mod;
					}
					ans=(ans*coef)%mod;
				}
				else
				{
					ll coef=((lo+1==l&&hi+1==r)?mod-2:0);
					for(i=0;i<=r-lo+1;i++)
					{
						coef=(coef+C(r-lo+1,i))%mod;
					}
					ans=(ans*coef)%mod;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}