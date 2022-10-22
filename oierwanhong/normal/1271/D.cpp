//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
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
#define MAXN 5011
#define MAXM 300011
struct edge
{
    ll v,nxt;
}e[MAXM];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v;
    e[cnt].nxt=last[u],last[u]=cnt;
}
std::priority_queue<ll,std::vector<ll>,std::greater<ll> >q;
ll maxv[MAXN],a[MAXN],b[MAXN],c[MAXN];
int main()
{
    ll n=read(),m=read(),k=read();
    for(ll u=1;u<=n;++u)
    {
        a[u]=read(),b[u]=read(),c[u]=read();
        maxv[u]=u;
    }
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read();
        umax(maxv[v],u);
    }
    for(ll i=1;i<=n;++i)adde(maxv[i],i);
    for(ll u=1;u<=n;++u)
    {
        while(k<a[u]&&!q.empty())++k,q.pop();
        if(k<a[u]){puts("-1");return 0;}
        k+=b[u];
        for(ll i=last[u];i;i=e[i].nxt)q.push(c[e[i].v]),--k;
    }
    while(k<0&&!q.empty())++k,q.pop();
    if(k<0){puts("-1");return 0;}
    ll ans=0;
    while(!q.empty())ans+=q.top(),q.pop();
    printf("%lld",ans);
    return 0;
}