//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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

/**********/
#define MAXN 1000011
char a[MAXN];
ll ps[MAXN],ss[MAXN];
int main()
{
	std::cin>>(a+1);
	ll l=strlen(a+1);
	ps[0]=0;
	for(ll i=1;i<=l;++i)
	{
		ps[i]=ps[i-1];
		if(a[i]=='v'&&a[i-1]=='v')++ps[i];
	}
	ss[l+1]=0;
	for(ll i=l;i;--i)
	{
		ss[i]=ss[i+1];
		if(a[i]=='v'&&a[i+1]=='v')++ss[i];
	}
	ll ans=0;
	for(ll i=2;i<l;++i)
		if(a[i]=='o')
			ans+=ps[i-1]*ss[i+1];
	std::cout<<ans;
	return 0;
}