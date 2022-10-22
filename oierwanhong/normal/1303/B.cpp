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
int main()
{
	ll task=read();
	while(task--)
	{
		ll n=read(),a=read(),b=read();
		ll l=0,r=ll(2e18);
		while(l<r)
		{
			ll mid=(l+r)>>1;
			ll x=a*(mid/(a+b))+min(a,mid%(a+b)),y=min(b*(mid/(a+b))+max(0,mid%(a+b)-a),n/2);
			if(x+y>=n)r=mid;
			else l=mid+1;
		}
		printf("%lld\n",l);
	}
	return 0;
}