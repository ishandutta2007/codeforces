//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
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
#define MAXN 200011
ll ans[MAXN],len;
std::set<ll>s,ts;
int main()
{
	ll n=read();
	len=1;
	for(ll i=1;i<=n;++i)
	{
		ll x=read();
		if(x>0)
		{
			if(ts.count(x))
			{
				puts("-1");return 0;
			}
			s.insert(x);ts.insert(x);
		}
		else
		{
			x=-x;
			if(!s.count(x))
			{
				puts("-1");return 0;
			}
			s.erase(x);
		}
		++ans[len];
		if(s.empty())
		{
			ts.clear();
			++len;
		}
	}
	if(!s.empty())
	{
		puts("-1");
		return 0;
	}
	while(ans[len]==0)--len;
	printf("%lld\n",len);
	for(ll i=1;i<=len;++i)printf("%lld ",ans[i]);
	return 0;
}