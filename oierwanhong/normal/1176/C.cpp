//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
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
#define MAXN 500011
ll a[MAXN],c[6];
ll t[6]={4,8,15,16,23,42};
int main()
{
	ll n=read(),ans=0;
	for(ll i=1;i<=n;++i)
	{
		ll x=read();
		for(ll j=0;j<6;++j)
			if(x==t[j])a[i]=j;
	}
	for(ll i=1;i<=n;++i)
	{
		if(c[a[i]])
		{
			--c[a[i]];
			if(a[i]!=5)++c[a[i]+1];
		}
		else
		{
			if(a[i]==0)++c[1];
			else ++ans;
		}
	}
	for(ll i=0;i<6;++i)ans+=c[i]*i;
	std::cout<<ans;
	return 0;
}