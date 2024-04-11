//By luogu send again.
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
str a,b;
void print()
{
	std::cout<<a<<std::endl;
}
void work()
{
	std::cin>>a>>b;
	for(ll s=0;s<a.size();++s)
	{
		ll pos=s;
		for(ll i=s+1;i<a.size();++i)
			if(a[i]<=a[pos])pos=i;
		std::swap(a[s],a[pos]);
		if(a<b)
		{
			std::cout<<a<<std::endl;
			return;
		}
		std::swap(a[s],a[pos]);
	}
	std::cout<<"---"<<std::endl;
}
int main()
{
	ll task=read();
	while(task--)work();
	return 0;
}