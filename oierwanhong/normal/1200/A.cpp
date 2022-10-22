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
#define MAXN 21
bool a[MAXN];
str s;
int main()
{
	ll n=read();
	std::cin>>s;
	for(ll i=0;i<n;++i)
	{
		if(s[i]=='L')
		{
			for(ll j=0;j<10;++j)
				if(!a[j])
				{
					a[j]=1;
					break;
				}
		}
		else if(s[i]=='R')
		{
			for(ll j=9;j>=0;--j)
				if(!a[j])
				{
					a[j]=1;
					break;
				}
		}
		else a[s[i]-'0']=0;
	}
	for(ll i=0;i<10;++i)putchar(a[i]+'0');
	return 0;
}