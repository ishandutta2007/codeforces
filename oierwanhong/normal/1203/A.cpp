//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
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
#define MAXN 511
ll a[MAXN];
int main()
{
	ll q=read();
	while(q--)
	{
		ll n=read(),flag=1,k=0;
		for(ll i=1;i<=n;++i)a[i]=read();
		for(ll i=1;i<=n;++i)
		{
			if(k&&a[i]!=k)flag=0;
			if(a[i]==1)k=n;
			else k=a[i]-1;
		}
		if(flag)
		{
			puts("YES");
			continue;
		}
		k=0;flag=1;
		for(ll i=1;i<=n;++i)
		{
			if(k&&a[i]!=k)flag=0;
			if(a[i]==n)k=1;
			else k=a[i]+1;
		}
		if(flag)puts("YES");
		else puts("NO");
	}
	return 0;
}