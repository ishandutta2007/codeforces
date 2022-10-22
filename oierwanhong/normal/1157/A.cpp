//Wan Hong 2.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
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
	ll n=read();
	if(n<10)std::cout<<9;
	else
	{
		ll ans=9;
		while(n>=10)
		{
			++n;
			while(!(n%10))n/=10;
			++ans;
		}
		std::cout<<ans;
	}
	return 0;
}