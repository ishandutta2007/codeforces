//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
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
#define MAXN 1000011
struct Edge
{
    ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN],pre[MAXN],dis[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v;
    e[cnt].nxt=last[u],last[u]=cnt;
}
ll ans=INF;
void bfs(ll s)
{
    static std::queue<ll>q;
    memset(dis,0,sizeof dis);
    //printf("work %lld:\n",s);
    dis[s]=1,pre[s]=0;
    q.push(s);
    while(!q.empty())
    {
        ll u=q.front();q.pop();
        //printf("dis[%lld]=%lld,pre=%lld\n",u,dis[u],pre[u]);
        for(ll i=last[u];i;i=e[i].nxt)
        {
            ll v=e[i].v;
            if(v==pre[u])continue;
            if(!dis[v])
            {
                dis[v]=dis[u]+1,pre[v]=u;
                q.push(v);
            }
            else umin(ans,dis[u]+dis[v]-1);
        }
    }
}
bool is_prime(ll n)
{
    for(ll i=2;i*i<=n;++i)
        if(n%i==0)return 0;
    return 1;
}
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)
    {
        ll x=read(),c1=0,c2=1;
        for(ll j=2;j*j<=x;++j)
            if(x%j==0)
            {
                ll t=0;
                while(x%j==0)++t,x/=j;
                if((t&1))
                {
                    if(!c1)c1=j;
                    else c2=j;
                }
            }
        if(x>1)
        {
            if(!c1)c1=x;else c2=x;
        }
        //printf("c1=%lld c2=%lld\n",c1,c2);
        if(!c1)
        {
            puts("1");return 0;
        }
        adde(c1,c2),adde(c2,c1);
    }
    bfs(1);
    for(ll i=2;i<=1000;++i)
    {
        if(is_prime(i))bfs(i);
    }
    if(ans>n)puts("-1");
    else printf("%lld",ans);
    return 0;
}