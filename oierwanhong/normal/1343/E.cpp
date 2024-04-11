//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
const ll INF=1ll<<58;
/**********/
#define MAXN 200011
struct edge
{
    ll v,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v;
    e[cnt].nxt=last[u],last[u]=cnt;
}
ll dis1[MAXN],dis2[MAXN],dis3[MAXN];
std::queue<ll>q;
void bfs(ll s,ll dis[])
{
    dis[s]=1;q.push(s);
    while(!q.empty())
    {
        ll u=q.front();q.pop();
        for(ll i=last[u];i;i=e[i].nxt)
        {
            ll v=e[i].v;
            if(!dis[v])dis[v]=dis[u]+1,q.push(v);
        }
    }
}
ll price[MAXN];
void work()
{
    cnt=0;
    ll n=read(),m=read(),a=read(),b=read(),c=read();
    for(ll i=1;i<=n;++i)dis1[i]=dis2[i]=dis3[i]=0,last[i]=0;
    for(ll i=1;i<=m;++i)price[i]=read();
    std::sort(price+1,price+m+1);
    for(ll i=1;i<=m;++i)price[i]+=price[i-1];
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read();adde(u,v),adde(v,u);
    }
    bfs(a,dis1),bfs(b,dis2),bfs(c,dis3);
    for(ll i=1;i<=n;++i)--dis1[i],--dis2[i],--dis3[i];
    ll ans=INF;
    for(ll i=1;i<=n;++i)
    {
        ll x=dis1[i]+dis2[i]+dis3[i];
        if(x>m)continue;
        umin(ans,price[x]+price[dis2[i]]);
    }
    printf("%lld\n",ans);
}
int main()
{
    ll task=read();
    while(task--)work();
    return 0;
}