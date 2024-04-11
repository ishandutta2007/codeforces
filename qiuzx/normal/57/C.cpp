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
#define N 200010
using namespace std;
ll fact[N],inv[N],inv_fac[N],n;
ll GetC(ll x,ll y)
{
	if(x<y||x<0||y<0)
	{
		return 0;
	}
	return (fact[x]*((inv_fac[y]*inv_fac[x-y])%mod))%mod;
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
	cin>>n;
	cout<<(GetC(n+n,n)+mod-n)%mod<<endl;
	return 0;
}