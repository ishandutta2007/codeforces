#include<iostream>
#include<cstdio>
#include<queue>
typedef long long ll;
typedef std::pair<ll,ll> pll;
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
ll abs(ll x)
{
    return x>0?x:-x;
}
 
/**********/
#define MAXN 200011
struct Edge
{
	ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
	e[++cnt].v=v;
	e[cnt].nxt=last[u],last[u]=cnt;
}
ll a[MAXN],f1[MAXN],f2[MAXN];
std::queue<ll>q;
int main()
{
	ll n=read();
	for(ll i=1;i<=n;++i)
	{
		a[i]=read(),f1[i]=f2[i]=-1;
		if(i-a[i]>=1)adde(i-a[i],i);
		if(i+a[i]<=n)adde(i+a[i],i);
	}
	for(ll i=1;i<=n;++i)
		if(a[i]&1)
		{
			q.push(i);
			f1[i]=0;
		}
	while(!q.empty())
	{
		ll u=q.front();q.pop();
		for(ll i=last[u];i;i=e[i].nxt)
		{
			ll v=e[i].v;
			if(f1[v]==-1)
			{
				f1[v]=f1[u]+1;
				q.push(v);
			}
		}
	}
	for(ll i=1;i<=n;++i)
		if(!(a[i]&1))
		{
			q.push(i);
			f2[i]=0;
		}
	while(!q.empty())
	{
		ll u=q.front();q.pop();
		for(ll i=last[u];i;i=e[i].nxt)
		{
			ll v=e[i].v;
			if(f2[v]==-1)
			{
				f2[v]=f2[u]+1;
				q.push(v);
			}
		}
	}
	for(ll i=1;i<=n;++i)
	{
		if(a[i]&1)printf("%lld ",f2[i]?f2[i]:-1);
		else printf("%lld ",f1[i]?f1[i]:-1);
	}
	return 0;
}