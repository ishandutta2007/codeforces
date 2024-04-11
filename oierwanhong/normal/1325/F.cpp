//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
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

ll s[MAXN],top=0,dep[MAXN],lim,tag[MAXN];
void dfs(ll u,ll now_dep=1,ll fa=0)
{
    s[++top]=u;dep[u]=now_dep;
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa)continue;
        if(!dep[v])dfs(v,now_dep+1,u);
        else if(dep[u]-dep[v]+1>=lim)
        {
            printf("2\n%lld\n",dep[u]-dep[v]+1);
            for(ll p=dep[u]-dep[v]+1;p;--p)printf("%lld ",s[top--]);
            exit(0);
        }
    }
    if(!tag[u])
    {
        for (ll i = last[u]; i ; i=e[i].nxt)
            tag[e[i].v]=1;
    }
    --top;
}
int main()
{
    ll n=read(),m=read();
    lim=sqrt(n);
    if(lim*lim<n)++lim;
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    dfs(1);
    puts("1");
    ll u=1;
    while(lim)
    {
        while(tag[u])++u;
        printf("%lld ",u);
        ++u;
        --lim;
    }
    return 0;
}