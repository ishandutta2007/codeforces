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

ll a[11];
int main()
{
	ll t=0;
	for(ll i=1;i<=4;++i)
	{
		a[i]=read();
		if(a[i]>a[t])t=i;
	}
	for(ll i=1;i<=4;++i)
		if(i!=t)std::cout<<a[t]-a[i]<<" ";
	return 0;
}