//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
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
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
ll f(ll x)
{
	return x*(x-1)/2+x;
}
int main()
{
	ll task=read();
	while(task--)
	{
		ll n=read(),m=read(),all=f(n);
		if(!m)
		{
			printf("%lld\n",0ll);
			continue;
		}
		ll n1=(n-m)%(m+1),n2=m+1-n1;
		printf("%lld\n",all-n1*f((n-m)/(m+1)+1)-n2*f((n-m)/(m+1)));
	}
	return 0;
}