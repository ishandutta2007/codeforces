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
#define N 800010
using namespace std;
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
struct NTT{
	ll n,m,rev[N],lim,mxbit,a1[N],a2[N];
	void ntt(ll *a,ll flag)
	{
		ll i,j,k,l;
		for(i=0;i<lim;i++)
		{
			if(rev[i]<i)
			{
				swap(a[i],a[rev[i]]);
			}
		}
		for(l=2;l<=lim;l<<=1)
		{
			i=l>>1;
			ll gn=ksm(3,(mod-1)/l);
			for(j=0;j<lim;j+=l)
			{
				ll g=1;
				for(k=0;k<i;++k)
				{
					ll x=(a[i+j+k]*g)%mod;
					a[i+j+k]=(a[j+k]+mod-x)%mod;
					a[j+k]=(a[j+k]+x)%mod;
					g=(g*gn)%mod;
				}
			}
		}
		if(flag==-1)
		{
			reverse(a+1,a+lim);
			ll inv=ksm(lim,mod-2);
			for(i=0;i<lim;i++)
			{
				a[i]=(a[i]*inv)%mod;
			}
		}
		return;
	}
	vector<ll> do_ntt(vector<ll> v1,vector<ll> v2)
	{
		ll i;
		n=v1.size(),m=v2.size();
		for(lim=1,mxbit=0;lim<n+m;lim<<=1,mxbit++);
		--mxbit;
		for(i=0;i<v1.size();++i)
		{
			a1[i]=v1[i];
		}
		for(i=0;i<v2.size();++i)
		{
			a2[i]=v2[i];
		}
		rev[0]=0;
		for(i=1;i<lim;++i)
		{
			rev[i]=(rev[i>>1]>>1)|((i&1)<<mxbit);
		}
		ntt(a1,1);
		ntt(a2,1);
		for(i=0;i<lim;++i)
		{
			a1[i]=(a1[i]*a2[i])%mod;
		}
		ntt(a1,-1);
		v1.resize(n+m-1);
		for(i=0;i<n+m-1;++i)
		{
			v1[i]=a1[i];
		}
		return v1;
	}
}ntt;
ll fact[N],inv[N],inv_fac[N],sinv[N];
ll n,f[N],a[N],b[N];
int main(){
	ll i;
	fact[0]=inv_fac[0]=inv[1]=inv_fac[1]=fact[1]=1;
	sinv[1]=1;
	for(i=2;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
		inv_fac[i]=(inv_fac[i-1]*inv[i])%mod;
		sinv[i]=(sinv[i-1]+inv[i])%mod;
	}
	scanf("%lld",&n);
	for(i=(n+1)>>1;i<=n;i++)
	{
		f[i]=(fact[i-1]+mod-((fact[i-1]*(sinv[i-1]+mod-sinv[(n-1)>>1]))%mod))%mod;
	}
	vector<ll> a(n+1),b(n+1);
	for(i=1;i<=n;i++)
	{
		a[i-1]=(((f[i]*inv_fac[i-1])%mod)*fact[max((ll)0,n-i-1)])%mod;
	}
	for(i=0;i<=n;i++)
	{
		b[i]=inv_fac[i];
	}
	vector<ll> v=ntt.do_ntt(a,b);
	printf("%lld ",f[n]);
	for(i=2;i<=n;i++)
	{
		printf("%lld ",(((fact[n-i]*(i-1))%mod)*v[n-i])%mod);
	}
	return 0;
}