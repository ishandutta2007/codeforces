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
ll abs(ll x)
{
	return x>0?x:-x;
}
int main()
{
	ll n=read(),ans=0,flag=0,cnt=0;
	for(ll i=1;i<=n;++i)
	{
		ll x=read();
		if(abs(x-1)<abs(x+1))ans+=abs(x-1);
		else if(abs(x-1)==abs(x+1))ans+=abs(x-1),flag=1;
		else ans+=abs(x+1),++cnt;
	}
	if((cnt&1)&&!flag)ans+=2;
	std::cout<<ans;
	return 0;
}