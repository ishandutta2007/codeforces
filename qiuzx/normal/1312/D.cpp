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
#define N 200010
using namespace std;
/*
Before Submitting, check:(Delete them before submitting)
*int or long long
*the range of every array(will it get an RE and is it bg enough?)
*special cases(0,1...)
*/
ll n,m,fac[N],ans=0;
ll ksm(ll x,ll y)
{
	if(y==0)
	{
		return 1;
	}
	if(y==1)
	{
		return x;
	}
	ll ret=ksm(x,y/2);
	if(y%2==1)
	{
		return ((ret*ret)%mod*x)%mod;
	}
	return (ret*ret)%mod;
}
ll gc(ll x,ll y)
{
	ll a=fac[x],b=(fac[y]*fac[x-y])%mod;
	return (a*ksm(b,mod-2))%mod;
}
int main(){
	ll i;
	cin>>n>>m;
	fac[0]=1;
	for(i=1;i<N;i++)
	{
		fac[i]=(fac[i-1]*i)%mod;
	}
	for(i=m;i>=n-1;i--)
	{
		ans=(ans+(((gc(i-1,n-2)*ksm(2,n-2))%mod)*gc(n-2,1))%mod)%mod;
	}
	cout<<(ans*ksm(2,mod-2))%mod<<endl;
	return 0;
}