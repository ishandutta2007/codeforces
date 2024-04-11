//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
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
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}

/**********/
#define MAXN 1000011
ll a[MAXN];
int main()
{
	ll n=read(),x=read(),y=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	for(ll i=1;i<=n;++i)
	{
		bool flag=1;
		for(ll j=max(1,i-x);j<i;++j)
			if(a[j]<=a[i])flag=0;
		for(ll j=i+1;j<=min(n,i+y);++j)
			if(a[j]<=a[i])flag=0;
		if(flag)
		{
			std::cout<<i;
			return 0;
		}
	}
	return 0;
}