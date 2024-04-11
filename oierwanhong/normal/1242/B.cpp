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
const ll INF=1ll<<58;
/**********/
#define MAXN 200011
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
struct node
{
    ll u,k;
    bool operator <(const node& t)const{return  k>t.k;}
};
std::priority_queue<node>q;
ll deg[MAXN];bool vis[MAXN];
int main()
{
    ll n=read(),m=read(),ans=0;
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    for(ll u=1;u<=n;++u)q.push(node{u,0});
    for(ll cur=0;cur<n;++cur)
    {
        while(!q.empty()&&q.top().k<deg[q.top().u])q.pop();
        ll u=q.top().u,k=q.top().k;q.pop();
        if(k==cur)++ans;
		vis[u]=1;
        for(ll i=last[u];i;i=e[i].nxt)
        {
            ll v=e[i].v;
            if(!vis[v])++deg[v],q.push(node{v,deg[v]});
        }
    }
    printf("%lld",ans-1);
}