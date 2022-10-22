//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
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

int main()
{
	ll n=read();
	if((n&1)==0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	n<<=1;
	ll pos=1;
	std::cout<<pos<<" ";
	for(ll i=2;i<n;i+=2,++pos)
		if(pos+4<=n)
		{
			pos+=3;
			std::cout<<pos<<" "<<(pos+1)<<" ";
			
		}
		else
		{
			pos=2;
			std::cout<<pos<<" "<<(pos+1)<<" ";
		}
	std::cout<<n;
	return 0;
}