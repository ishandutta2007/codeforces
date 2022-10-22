//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
/**********/
#define MAXN 200011
#define MAXM 4000011
struct edge
{
    ll v,w,nxt;
}e[MAXM];
ll cnt=0,last[MAXN];
void adde(ll u,ll v,ll w)
{
    e[++cnt]={v,w,last[u]},last[u]=cnt;
}

struct node
{
    ll u,dis;
    bool operator <(const node& t)const{return dis>t.dis;}
};
std::priority_queue<node>q;
ll dis[MAXN];
ll Dij(ll s,ll t)
{
    memset(dis,0x3f,sizeof dis);
    dis[s]=0,q.push(node{s,0});
    while(!q.empty())
    {
        ll u=q.top().u,tmp=q.top().dis;q.pop();
        if(dis[u]!=tmp)continue;
        for(ll i=last[u];i;i=e[i].nxt)
        {
            ll v=e[i].v;
            if(umin(dis[v],dis[u]+e[i].w))q.push(node{v,dis[v]});
        }
    }
    return dis[t];
}
int main()
{
    ll n=read(),m=read();
    for(ll i=1;i<=n;++i)
    {
        ll x=read(),s=read(),w=0;
        do
        {
            adde(max(1,x-s-w),min(m+1,x+s+w+1),w);
            ++w;
        } while (x-s-w>0&&x+s+w<=m);
        
    }
    for(ll i=1;i<=m;++i)adde(i,i+1,1),adde(i+1,i,0);
    printf("%lld",Dij(1,m+1));
    return 0;
}