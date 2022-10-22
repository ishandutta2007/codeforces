//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
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
#define MAXN 200011
std::map<ll,ll>f;
std::queue<ll>q;
ll ans[MAXN];
int main()
{
	ll n=read(),m=read(),len=0,sum=0;
	for(ll i=1;i<=n;++i)
	{
		ll x=read();
		f[x]=0;
		q.push(x);
	}
	while(!q.empty())
	{
		if(len==m)break;
		ll u=q.front();q.pop();
		if(f[u])
		{
			sum+=f[u];
			ans[++len]=u;
		}
		if(!f.count(u-1))
		{
			f[u-1]=f[u]+1;
			q.push(u-1);
		}
		if(!f.count(u+1))
		{
			f[u+1]=f[u]+1;
			q.push(u+1);
		}
	}
	printf("%lld\n",sum);
	for(ll i=1;i<=m;++i)printf("%lld ",ans[i]);
	return 0;
}