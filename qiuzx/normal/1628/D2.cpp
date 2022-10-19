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
#define N 1000010
using namespace std;
ll n,m,k,f[N],inv2[N],fact[N],inv[N],inv_fac[N];
ll GetC(ll x,ll y)
{
	if(x<y||x<0||y<0)
	{
		return 0;
	}
	return (fact[x]*((inv_fac[y]*inv_fac[x-y])%mod))%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll T,i,j,pw=1;
	cin>>T;
	fact[0]=inv_fac[0]=inv[1]=inv_fac[1]=fact[1]=1;
	for(i=2;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
		inv_fac[i]=(inv_fac[i-1]*inv[i])%mod;
	}
	inv2[0]=1;
	for(i=1;i<N;i++)
	{
		f[i]=(pw*i)%mod;
		inv2[i]=(inv2[i-1]*(mod+1)/2)%mod;
		pw=(pw*2)%mod;
	}
	while(T--)
	{
		cin>>n>>m>>k;
		m=n-m;
		ll ans=0;
		if(m==0)
		{
			ans=f[n];
		}
		else
		{
			for(i=1;n-i-1>=m-1;i++)
			{
				ans=(ans+GetC(n-i-1,m-1)*f[i])%mod;
			}
		}
		cout<<(((ans*inv2[n-1])%mod)*k)%mod<<endl;
	}
	return 0;
}