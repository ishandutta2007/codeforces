//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
typedef long long ll;
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

/**********/
std::map<ll,ll>p;
ll a[100011];
int main()
{
	ll n=read();
	bool flag=0,x=0;
	for(ll i=1;i<=n;++i)
	{
		ll x=read();
		++p[x];a[i]=x;
	}
	if(p[0]>=2)flag=1;
	for(std::map<ll,ll>::iterator it=p.begin();it!=p.end();++it)
	{
		if(it->first==0)continue;
		if(it->second>=3)flag=1;
		if(it->second>=2)
		{
			if(p[it->first-1]>=1)flag=1;
			if(x)flag=1;
			else x=1;
		}
	}
	if(flag)puts("cslnb");
	else
	{
		//puts("pass 62");
		ll s=0;
		std::sort(a+1,a+n+1);
		for(ll i=1;i<=n;++i)s+=a[i]-(i-1);
		if(s&1)puts("sjfnb");
		else puts("cslnb");
	}
	return 0;
}