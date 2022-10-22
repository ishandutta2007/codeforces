//by LG send again
//Wan Hong 2.1
//notebook
#include<iostream>
#include<cstdio>
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

int main()
{
	ll n=read(),a=read(),ta=a,b=read(),tb=b,i=1;
	for(;i<=n;++i)
	{
		ll op=read();
		if(tb==b)
		{
			--tb;continue;
		}
		if(op==1)
		{
			if(ta>0)--ta,++tb;
			else if(tb>0)--tb;
			else break;
		}
		else
		{
			if(tb>0)--tb;
			else if(ta>0)--ta;
			else break;
		}
	}
	std::cout<<i-1;
	return 0;
}