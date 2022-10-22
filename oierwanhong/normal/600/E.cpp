//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
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
#define MAXN 100011
struct edge
{
    ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN],a[MAXN],ans[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v;
    e[cnt].nxt=last[u],last[u]=cnt;
}

ll fa[MAXN],size[MAXN],mson[MAXN];
void dfs1(ll u)
{
    size[u]=1;
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa[u])continue;
        fa[v]=u;
        dfs1(v);
        size[u]+=size[v];
        if(size[v]>size[mson[u]])mson[u]=v;
    }
}
ll c[MAXN],maxv=0,sum=0;
ll s[MAXN],top=0;
void clear()
{
    while(top)c[s[top--]]=0;
    maxv=sum=0;
}
void calc(ll u)
{
    s[++top]=a[u];
    ++c[a[u]];
    if(c[a[u]]>maxv)maxv=c[a[u]],sum=0;
    if(c[a[u]]==maxv)sum+=a[u];
    for(ll i=last[u];i;i=e[i].nxt)
        if(e[i].v!=fa[u])calc(e[i].v);
}
void dfs2(ll u)
{
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v!=mson[u]&&v!=fa[u])dfs2(v),clear();
    }
    if(mson[u])dfs2(mson[u]);
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v!=mson[u]&&v!=fa[u])calc(v);
    }
    s[++top]=a[u];
    ++c[a[u]];
    if(c[a[u]]>maxv)maxv=c[a[u]],sum=0;
    if(c[a[u]]==maxv)sum+=a[u];
    ans[u]=sum;
}
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)a[i]=read();
    for(ll i=1;i<n;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    dfs1(1),dfs2(1);
    for(ll i=1;i<=n;++i)printf("%lld ",ans[i]);
    return 0;
}