#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 500010
using namespace std;
ll n,ans=0,fact[N];
ll ksm(ll x,ll y)
{
	if(y==0)
	{
		return 1;
	}
	ll ret=ksm(x,y>>1);
	ret=(ret*ret)%mod;
	if(y&1)
	{
		ret=(ret*x)%mod;
	}
	return ret;
}
ll GetC(ll x,ll y)
{
	return (fact[x]*((ksm(fact[y],mod-2)*ksm(fact[x-y],mod-2))%mod))%mod;
}
int main(){
	ll i,t;
	fact[0]=1;
	for(i=1;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
	}
	cin>>n;
	for(i=1;i<=n;i++)
	{
		if((n+i)%2==0)
		{
			t=(n+i)/2;
			ans=(ans+GetC(t-1,i-1))%mod;
		}
	}
	printf("%lld\n",(ans*ksm(ksm(2,n),mod-2))%mod);
	return 0;
}