//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
typedef int ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<28)
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
#define MAXN 1000011
ll deg[MAXN],to[MAXN],q[MAXN];
char a[MAXN];
std::vector<ll>g[MAXN];
bool good[MAXN];
struct edge
{
    ll v,nxt;
}e[MAXN];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v;
    e[cnt].nxt=last[u],last[u]=cnt;
}
ll rt[MAXN];
void dfs1(ll u,ll cur,ll now_dis,ll len)
{
    rt[u]=cur;
    if(good[u])g[cur].push_back(now_dis%len);
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(!rt[v])dfs1(v,cur,now_dis+1,len);
    }
}
int main()
{
    ll t=read();
    while(t--)
    {
        cnt=0;
        ll n=read(),m=read(),ans1=n*m,ans2=0;
        for(ll i=1;i<=n*m;++i)last[i]=deg[i]=rt[i]=0,g[i].clear();
        for(ll i=1;i<=n;++i)
        {
            scanf("%s",a+1);
            for(ll j=1;j<=m;++j)good[(i-1)*m+j]=(a[j]=='0');
        }
        for(ll i=1;i<=n;++i)
        {
            scanf("%s",a+1);
            for(ll j=1;j<=m;++j)
            {
                ll u=(i-1)*m+j,v=u;
                if(a[j]=='U')v-=m;
                if(a[j]=='L')--v;
                if(a[j]=='D')v+=m;
                if(a[j]=='R')++v;
                to[u]=v;adde(v,u);++deg[v];
            }
        }
        ll h=1,t=1;
        for(ll i=1;i<=n*m;++i)
            if(!deg[i])q[t++]=i;
        while(h<t)
        {
            ll u=q[h++];--ans1;
            if(!--deg[to[u]])q[t++]=to[u];
        }
        for(ll i=1;i<=n*m;++i)
            if(deg[i]&&!rt[i])
            {
            	ll p=i,len=1;
            	while(to[p]!=i)p=to[p],++len;
                dfs1(i,i,0,len);
                std::sort(g[i].begin(),g[i].end());
                ans2+=std::unique(g[i].begin(),g[i].end())-g[i].begin();
            }
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}