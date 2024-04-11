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
#define N 200010
using namespace std;
ll n,m,a[N],b[N],fact[N],sum[N];
vector<ll> d;
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
ll Getc(ll x,ll y)
{
	return (fact[x]*((ksm(fact[y],mod-2)*ksm(fact[x-y],mod-2))%mod))%mod;
}
int main(){
	ll i,x,coea,coeb;
	fact[0]=1;
	for(i=1;i<N;i++)
	{
		fact[i]=(fact[i-1]*i)%mod;
	}
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&x);
		d.push_back(x);
	}
	sort(d.begin(),d.end());
	sum[0]=0;
	for(i=0;i<d.size();i++)
	{
		sum[i+1]=(sum[i]+d[i])%mod;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&a[i],&b[i]);
	}
	for(i=0;i<m;i++)
	{
		x=lower_bound(d.begin(),d.end(),b[i])-d.begin();
		if(a[i]>n-x)
		{
			puts("0");
			continue;
		}
		coea=(ksm(n-x,mod-2)*(n-x-a[i]))%mod;
		coeb=(ksm(n-x+1,mod-2)*(n-x-a[i]+1))%mod;
		printf("%lld\n",(((coea*(mod+sum[n]-sum[x]))%mod)+((coeb*sum[x])%mod))%mod);
	}
	return 0;
}