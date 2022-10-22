//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
typedef long long ll;
typedef unsigned un;
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
#define MAXN 51
int main()
{
	ll task=read();
	while(task--)
	{
		ll n=read(),mod=read(),ans=1,i;
		if(n==1){printf("%lld\n",1%mod);continue;}
		++n;
		for(i=1;(1ll<<i)<n;++i)
			ans=(ans*((1ll<<(i-1))+1))%mod;
		ans=(ans*(n-(1ll<<(i-1))+1))%mod;
		printf("%lld\n",(ans-1+mod)%mod);
	}
	return 0;
}