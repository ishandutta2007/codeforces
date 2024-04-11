//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
#define MAXN 200011
ll s[MAXN];
ll calc(ll l,ll r)
{
	return s[r]-s[l-1];
}
int main()
{
	ll n=read();
	s[0]=0;
	for(ll i=1;i<=n;++i)s[i]=s[i-1]+read();
	ll q=read();
	while(q--)
	{
		ll l=read(),r=read();
		std::cout<<calc(l,r)/10<<std::endl;
	}
	return 0;
}