//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<cstring>
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

ll fa[MAXN],dep[MAXN],dfn[MAXN],size[MAXN],cur=0;
void dfs(ll u,ll now_dep=1)
{
    dep[u]=now_dep;
    dfn[u]=++cur,size[u]=1;
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa[u])continue;
        fa[v]=u;
        dfs(v,now_dep+1);
        size[u]+=size[v];
    }
}
ll a[MAXN];
bool cmp(ll x,ll y)
{
    return dep[x]<dep[y];
}
int main()
{
    ll n=read(),m=read();
    for(ll i=1;i<n;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    fa[1]=1;
    dfs(1);
    while(m--)
    {
        ll p=read();
        for(ll i=1;i<=p;++i)a[i]=fa[read()];
        std::sort(a+1,a+p+1,cmp);
        //for(ll i=1;i<=p;++i)printf("%lld",a[i]);
        //putchar('\n');
        bool flag=0;
        for(ll i=1;i<p;++i)
            if(!(dfn[a[i]]<=dfn[a[i+1]]&&dfn[a[i+1]]<=dfn[a[i]]+size[a[i]]-1))flag=1;
        puts(flag?"NO":"YES");
    }
    return 0;
}