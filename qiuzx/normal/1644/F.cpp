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
#define N 2000010
#define MXSZ 2000020
using namespace std;
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
ll n,k,prm[MXSZ],mu[MXSZ],vis[MXSZ],sum[N],ans=0;
bool no_prm[MXSZ];
void get_mu()
{
	ll i,j,cnt=0;
	mu[1]=1;
	for(i=2;i<MXSZ;i++)
	{
		if(!no_prm[i])
		{
			prm[cnt++]=i;
			mu[i]=-1;
		}
		for(j=0;j<cnt;j++)
		{
			if(i*prm[j]>=MXSZ)
			{
				break;
			}
			no_prm[i*prm[j]]=true;
			if(i%prm[j]==0)
			{
				mu[i*prm[j]]=0;
				break;
			}
			mu[i*prm[j]]=-mu[i];
		}
	}
	return;
}
ll calc(ll x)
{
	if(vis[x]!=-1)
	{
		return vis[x];
	}
	ll y=min(k,x),i,ret=mod-1;
	for(i=0;i<=y;i++)
	{
		ret=(ret+((ksm(i,x)*inv_fac[i])%mod)*sum[y-i])%mod;
	}
	return vis[x]=ret;
}
int main(){
	ll i;
	fact[0]=inv_fac[0]=inv[1]=inv_fac[1]=fact[1]=1;
	for(i=2;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
		inv_fac[i]=(inv_fac[i-1]*inv[i])%mod;
	}
	cin>>n>>k;
	if(n==1||k==1)
	{
		puts("1");
		return 0;
	}
	get_mu();
	sum[0]=1;
	for(i=1;i<N;i++)
	{
		if(i&1)
		{
			sum[i]=(sum[i-1]+mod-inv_fac[i])%mod;
		}
		else
		{
			sum[i]=(sum[i-1]+inv_fac[i])%mod;
		}
	}
	memset(vis,-1,sizeof(vis));
	for(i=1;i<=n;i++)
	{
		ans=(ans+calc((n+i-1)/i)*(mod+mu[i]))%mod;
	}
	cout<<ans<<endl;
	return 0;
}