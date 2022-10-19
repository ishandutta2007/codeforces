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
#define N 100010
#define B 320
using namespace std;
ll n,q,a[N],mnpas[N],mnful[N],f[20][N],val[20][N],pw[N],ipw[N],sum[N],inv2=500000004;
bool checkpas(ll l,ll r,ll x)
{
	ll i;
	for(i=r;i>=l&&x>=0;i--)
	{
		if(x*2+a[i]>INF)
		{
			return true;
		}
		x=x*2+a[i];
	}
	return (x>=0);
}
bool checkful(ll l,ll r,ll x)
{
	ll i;
	for(i=r;i>=l&&x>=0;i--)
	{
		if(x*2+a[i]>INF)
		{
			return true;
		}
		x=x*2+a[i];
	}
	return false;
}
ll getsum(ll l,ll r)
{
	return (((sum[r+1]+mod-sum[l])%mod)*ipw[l])%mod;
}
ll calc(ll l,ll r,ll x)
{
	return (getsum(l,r)+x*pw[r-l+1])%mod;
}
int main(){
	ll i,j;
	pw[0]=ipw[0]=1;
	for(i=1;i<N;i++)
	{
		pw[i]=(pw[i-1]*2)%mod;
		ipw[i]=(ipw[i-1]*inv2)%mod;
	}
	scanf("%lld%lld",&n,&q);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i+1]=(sum[i]+((a[i]+mod)%mod)*pw[i])%mod;
	}
	for(i=0;i<n;i+=B)
	{
		ll l=0,r=INF,mid;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(checkpas(i,min(i+B,n)-1,mid))
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		mnpas[i/B]=l;
		l=0,r=INF;
		while(l<r)
		{
			mid=(l+r)>>1;
			if(checkful(i,min(i+B,n)-1,mid))
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
		}
		mnful[i/B]=l;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]<0)
		{
			f[0][i]=i-1;
			continue;
		}
		ll x=a[i];
		bool isful=false;
		for(j=i-1;j>=(i/B)*B&&x>=0;j--)
		{
			if(x*2+a[j]>INF)
			{
				isful=true;
				break;
			}
			x=x*2+a[j];
		}
		if(x<0)
		{
			f[0][i]=j;
			continue;
		}
		if(isful)
		{
			f[0][i]=-1;
			continue;
		}
		for(j=i/B-1;j>=0;j--)
		{
			if(x>=mnful[j])
			{
				isful=true;
				break;
			}
			if(x<mnpas[j])
			{
				break;
			}
			x=calc(j*B,min(n,(j+1)*B)-1,x);
		}
		if(isful)
		{
			f[0][i]=-1;
			continue;
		}
		for(j=min(n,(j+1)*B)-1;j>=0&&x>=0;j--)
		{
			x=x*2+a[j];
		}
		f[0][i]=j;
	}
	for(i=0;i<n;i++)
	{
		val[0][i]=getsum(f[0][i]+1,i);
	}
	for(i=1;i<20;i++)
	{
		for(j=0;j<n;j++)
		{
			f[i][j]=(f[i-1][j]==-1)?-1:f[i-1][f[i-1][j]];
			val[i][j]=(val[i-1][j]+((f[i-1][j]==-1)?0:val[i-1][f[i-1][j]]))%mod;
		}
	}
	while(q--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		l--,r--;
		ll ans=0;
		for(i=19;i>=0;i--)
		{
			if(f[i][r]>=l)
			{
				ans=(ans+val[i][r])%mod;
				r=f[i][r];
			}
		}
		if(l<r)
		{
			ans=(ans+getsum(l+1,r))%mod;
		}
		ans=(ans*2+((a[l]+mod)%mod))%mod;
		printf("%lld\n",ans);
	}
	return 0;
}