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
#define N (1<<17)+10
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
const ll inv2=499122177;
const ll inv4=748683265;
struct FWT{
	ll n;
	void fwt(ll *v)
	{
		ll i,j,k;
		for(i=1;i<n;i<<=1)
		{
			for(j=0;j<n;j+=(i<<1))
			{
				for(k=j;k<j+i;k++)
				{
					ll x=v[k],y=v[k+i];
					v[k]=(x+y)%mod;
					v[k+i]=(x+mod-y)%mod;
				}
			}
		}
		return;
	}
	void ifwt(ll *v)
	{
		ll i,j,k;
		for(i=1;i<n;i<<=1)
		{
			for(j=0;j<n;j+=(i<<1))
			{
				for(k=j;k<j+i;k++)
				{
					ll x=v[k],y=v[k+i];
					v[k]=(((x+y)%mod)*inv2)%mod;
					v[k+i]=(((x+mod-y)%mod)*inv2)%mod;
				}
			}
		}
		return;
	}
}fwt;
ll n,k,u,v,w,a[N],b[N],c[N],cur[N],p0[N],p1[N],p2[N];
int main(){
	ll i,pre=0;
	scanf("%lld%lld",&n,&k);
	fwt.n=(1<<k);
	scanf("%lld%lld%lld",&u,&v,&w);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		pre^=a[i];
		b[i]^=a[i];
		c[i]^=a[i];
		a[i]=0;
	}
	for(i=0;i<n;i++)
	{
		cur[b[i]]++;
	}
	fwt.fwt(cur);
	for(i=0;i<(1<<k);i++)
	{
		p0[i]=cur[i];
	}
	memset(cur,0,sizeof(cur));
	for(i=0;i<n;i++)
	{
		cur[c[i]]++;
	}
	fwt.fwt(cur);
	for(i=0;i<(1<<k);i++)
	{
		p1[i]=cur[i];
	}
	memset(cur,0,sizeof(cur));
	for(i=0;i<n;i++)
	{
		cur[b[i]^c[i]]++;
	}
	fwt.fwt(cur);
	for(i=0;i<(1<<k);i++)
	{
		p2[i]=cur[i];
	}
	for(i=0;i<(1<<k);i++)
	{
		ll c1=((n+p0[i]+p1[i]+p2[i])*inv4)%mod;
		ll c2=(((n+p0[i]-p1[i]-p2[i])%mod+mod)*inv4)%mod;
		ll c3=(((n+p1[i]-p0[i]-p2[i])%mod+mod)*inv4)%mod;
		ll c4=(((n+p2[i]-p0[i]-p1[i])%mod+mod)*inv4)%mod;
		c1=ksm((u+v+w)%mod,c1);
		c2=ksm((((u+v-w)%mod)+mod)%mod,c2);
		c3=ksm((((u-v+w)%mod)+mod)%mod,c3);
		c4=ksm((((u-v-w)%mod)+mod)%mod,c4);
		cur[i]=(((c1*c2)%mod)*((c3*c4)%mod))%mod;
	}
	fwt.ifwt(cur);
	for(i=0;i<(1<<k);i++)
	{
		printf("%lld ",cur[i^pre]);
	}
	return 0;
}