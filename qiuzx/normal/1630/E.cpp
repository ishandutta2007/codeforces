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
#define N 1000010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
ll fact[N],inv[N],inv_fac[N];
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
ll GetC(ll x,ll y){return (x<y||x<0||y<0)?0:(fact[x]*((inv_fac[y]*inv_fac[x-y])%mod))%mod;}
ll n,a[N],f[N],g[N],fac[N],cnt,allv[N],sz;
int main(){
	ll T,i,j,x;
	fact[0]=inv_fac[0]=inv[1]=inv_fac[1]=fact[1]=1;
	for(i=2;i<N;++i)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
		inv_fac[i]=(inv_fac[i-1]*inv[i])%mod;
	}
	T=rint();
	while(T--)
	{
		n=rint();
		for(i=1;i<=n;++i)
		{
			a[i]=0;
		}
		bool spe=false;
		sz=0;
		for(i=0;i<n;++i)
		{
			x=rint();
			if(a[x]==0)
			{
				allv[sz++]=x;
			}
			++a[x];
			if(a[x]==n)
			{
				spe=true;
			}
		}
		if(spe)
		{
			puts("1");
			continue;
		}
		ll G=0,preg=0,pres=0;
		cnt=0;
		for(i=1;i<=n;++i)
		{
			G=__gcd(G,a[i]);
			preg=(preg+((a[i]*inv[n])%mod))%mod;
			pres=(pres+((((a[i]*inv[n])%mod)*((a[i]*inv[n])%mod))%mod))%mod;
			if(n%i==0)
			{
				fac[cnt++]=i;
			}
		}
		ll ans=0,res=0;
		for(i=0;i<cnt;++i)
		{
			f[i]=g[i]=0;
			if(G%(n/fac[i])!=0)
			{
				continue;
			}
			f[i]=fact[fac[i]];
			for(j=0;j<sz;++j)
			{
				f[i]=(f[i]*inv_fac[a[allv[j]]/(n/fac[i])])%mod;
			}
			g[i]=(preg*fac[i])%mod;
			g[i]=(g[i]*g[i]+mod-((pres*((fac[i]*fac[i])%mod))%mod))%mod;
			g[i]=(((((g[i]*f[i])%mod)*inv[fac[i]-1])%mod)*(n/fac[i]))%mod;
			for(j=0;j<i;++j)
			{
				if(fac[i]%fac[j]==0)
				{
					f[i]=(f[i]+mod-f[j])%mod;
					g[i]=(g[i]+mod-g[j])%mod;
				}
			}
			ans=(ans+g[i]*inv[fac[i]])%mod;
			res=(res+f[i]*inv[fac[i]])%mod;
		}
		rout((ans*ksm(res,mod-2))%mod),putchar('\n');
	}
	return 0;
}