//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 3000010
using namespace std;
ll fact[N],inv[N],inv2[N];
ll GetC(ll x,ll y)
{
	if(x<y||x<0||y<0)
	{
		return 0;
	}
	return (fact[x]*((inv2[y]*inv2[x-y])%mod))%mod;
}
ll n,q,f[N];
int main(){
	ll i;
	fact[0]=inv2[0]=1;
	inv[1]=1;
	for(i=1;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
		if(i>1)
		{
			inv[i]=((mod-mod/i)*inv[mod%i])%mod;
		}
		inv2[i]=(inv2[i-1]*inv[i])%mod;
	}
	scanf("%lld%lld",&n,&q);
	ll inv3=inv[3];
	f[0]=n+1;
	f[1]=((n*(n+1)/2)*3)%mod;
	for(i=2;i<=3*n;i++)
	{
		f[i]=GetC(3*n,i+1);//All choices
		f[i]=(f[i]+3*(-f[i-1]+GetC(3*n,i-1)+mod))%mod;//in the same triplet with the last one
		f[i]=(f[i]+(-f[i-2]+GetC(3*n,i-2)+mod))%mod;//in ... with the last 2
		f[i]=(f[i]*inv3)%mod;// multiple places in a triplet
		f[i]=(f[i]+GetC(3*n,i))%mod;//the last one
	}
	while(q--)
	{
		scanf("%lld",&i);
		printf("%lld\n",f[i]);
	}
	return 0;
}