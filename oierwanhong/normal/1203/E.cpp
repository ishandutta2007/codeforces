//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
#define MAXN 150011
ll c[MAXN];
bool p[MAXN];
int main()
{
	ll n=read();
	for(ll i=1;i<=n;++i)++c[read()];
	for(ll i=1;i<=150000;++i)
	{
		while(c[i])
		{
			if(i>1&&!p[i-1])p[i-1]=1;
			else if(!p[i])p[i]=1;
			else if(!p[i+1])p[i+1]=1;
			--c[i];
		}
	}
	ll ans=0;
	for(ll i=1;i<MAXN;++i)
		ans+=p[i];
	printf("%lld",ans);
	return 0;
}