//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<set>
typedef long long ll;
typedef unsigned un;
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
struct edge
{
    ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN],deg[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v,++deg[v];
    e[cnt].nxt=last[u],last[u]=cnt;
}

ll dep[MAXN];
void dfs1(ll u,ll fa=0)
{
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa)continue;
        dep[v]=dep[u]+1;
        dfs1(v,u);
    }
}
ll ans;
void dfs2(ll u,ll fa=0)
{
    bool flag=0;
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa)continue;
        if(deg[v]==1)
        {
            if(flag)--ans;
            flag=1;
        }
        dfs2(v,u);
    }
}
int main()
{
    ll n=read();ans=n-1;
    for(ll i=1;i<n;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    ll root=0;
    for(ll i=1;i<=n;++i)
        if(deg[i]>1)root=i;
    dfs1(root);
    bool f1=0,f2=0;
    for(ll i=1;i<=n;++i)
    {
    	if(deg[i]==1)
    	{
    		if(dep[i]&1)f1=1;
        	else f2=1;
		}
	}
        
    if(f1&&f2)printf("3 ");
    else printf("1 ");
    dfs2(root);
    printf("%lld",ans);
    return 0;
}