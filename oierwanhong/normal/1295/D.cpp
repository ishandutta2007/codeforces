//By Luogu send again.
//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
ll calc_phi(ll n)
{
	ll ans=n;
	for(ll i=2;i*i<=n;++i)
		if(n%i==0)
		{
			ans=ans/i*(i-1);
			while(n%i==0)n/=i;
		}
	if(n>1)ans=ans/n*(n-1);
	return ans;
}
ll gcd(ll a,ll b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
	ll task=read();
	while(task--)
	{
		ll a=read(),m=read();
		ll g=gcd(a,m);
		printf("%lld\n",calc_phi(m/g));
	}
	return 0;
}