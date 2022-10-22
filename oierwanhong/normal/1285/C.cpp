//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
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
#define MAXN 1000011
ll p[MAXN],cnt=0;
void split(ll x)
{
	for(ll i=2;i*i<=x;++i)
		if(x%i==0)
		{
			p[++cnt]=1;
			while(x%i==0)p[cnt]*=i,x/=i;
		}
	if(x>1)p[++cnt]=x;
}
bool vis[MAXN];
int main()
{
	ll x=read(),mid=sqrt(x);
	split(x);
	vis[1]=1;
	for(ll i=1;i<=cnt;++i)
	{
		for(ll j=mid/p[i]*p[i];j>=p[i];j-=p[i])vis[j]|=vis[j/p[i]];
	}
	for(ll i=mid;i;--i)
		if(x%i==0&&vis[i])
		{
			printf("%lld %lld",i,x/i);
			return 0;
		}
	printf("%lld %lld",1ll,x);
	return 0;
}