//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef long long ll;
typedef int un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
/**********/
#define MAXN 1000011
ll l[MAXN],ans=0;
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
ll n,k;
ll dfs(ll u,ll fa=0)
{
	if(deg[u]==1)return 1;
    ll maxv=0;
    for(ll i=last[u];i;i=e[i].nxt)
        if(e[i].v!=fa)
        {
            ll t=dfs(e[i].v,u);
            if(t+maxv>k)++ans,umin(maxv,t);
            else umax(maxv,t);
        }
    return maxv?maxv+1:0ll;
}
int main()
{
    n=read(),k=read();
    for(ll i=1;i<n;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    for(ll i=1;i<=n;++i)
        if(deg[i]>1)
        {
            ll p=dfs(i);printf("%lld",ans+!!p);
            return 0;
        }
    return 0;
}