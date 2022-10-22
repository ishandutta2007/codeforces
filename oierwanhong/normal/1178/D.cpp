//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
typedef long long ll;
typedef std::string str;
typedef std::pair<ll,ll> pll;
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
std::vector<pll>ans;
bool check(ll n)
{
	if(n<2)return 0;
	for(ll i=2;i*i<=n;++i)
		if(n%i==0)return 0;
	return 1;
}
int main()
{
	ll n=read(),e=n;
	while(!check(e))++e;
	std::cout<<e<<std::endl;
	for(ll i=1;i<n;++i)
	{
		std::cout<<i<<" "<<i+1<<std::endl;
	}
	std::cout<<n<<" "<<1<<std::endl;
	e-=n;
	for(ll i=1;i<=n;++i)
	{
		if(!e)break;
		std::cout<<i<<" "<<i+n/2<<std::endl;
		--e;
		
	}
	return 0;
}