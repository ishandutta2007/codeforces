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
#define MAXN 200011
ll a[MAXN],b[MAXN],p[MAXN],cnt=0;
bool vis[MAXN];
int main()
{
	ll n=read();
	for(ll i=1;i<=n;++i)
	{
		a[i]=read();
		vis[a[i]]=1;
	}
	ll it=1;
	for(ll i=1;i<=n;++i)
		if(!a[i])
		{
			while(vis[it])++it;
			b[i]=it++;
			if(b[i]==i)p[++cnt]=i;
		}
	//printf("cnt=%lld\n",cnt);
	for(ll i=1;i<=cnt/2;++i)
		std::swap(b[p[(i*2)-1]],b[p[(i*2)]]);
	if(cnt&1)
	{
		ll cur=b[p[cnt]],nxt=1;
		for(nxt=1;nxt<=n;++nxt)
			if(nxt!=cur&&b[nxt])break;
		b[cur]=b[nxt],b[nxt]=cur;
	} 
	for(ll i=1;i<=n;++i)printf("%lld ",max(a[i],b[i]));
	return 0;
}