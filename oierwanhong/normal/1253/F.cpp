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
/**********/
#define MAXN 600011
struct edge
{
    ll v,w,nxt;
}e[MAXN];
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
ll dis[MAXN];
std::priority_queue<node>q;
void Dij(ll k)
{
    memset(dis,0x3f,sizeof dis);
    for(ll i=1;i<=k;++i)dis[i]=0,q.push(node{i,0});
    while(!q.empty())
    {
        ll u=q.top().u,tmp=q.top().dis;q.pop();
        if(tmp!=dis[u])continue;
        for(ll i=last[u];i;i=e[i].nxt)
        {
            ll v=e[i].v;
            if(umin(dis[v],dis[u]+e[i].w))q.push(node{v,dis[v]});
        }
    }
}

namespace Kru
{
    struct KEdge
    {
        ll u,v,w;
        bool operator <(const KEdge& t)const{return w<t.w;}
    }ke[MAXN];
    std::vector<ll>g[MAXN];
    ll tot=0,val[MAXN],fa[MAXN];
    struct DSU
    {
        ll fa[MAXN];
        void build(ll n){for(ll i=1;i<=n;++i)fa[i]=i;}
        ll find(ll x)
        {
            if(fa[x]==x)return x;
            return fa[x]=find(fa[x]);
        }
        bool same(ll u,ll v){return find(u)==find(v);}
        void uni(ll u,ll v)
        {
            u=find(u),v=find(v);
            fa[u]=v;
        }
    }s;
    void adde(ll u,ll v,ll w){ke[++tot]={u,v,w};}

    ll dep[MAXN],size[MAXN],mson[MAXN];
    ll top[MAXN],cur=0;
    void dfs1(ll u,ll now_dep=1)
    {
        dep[u]=now_dep;size[u]=1;
        for(auto v:g[u])
        {
            if(v==fa[u])continue;
            dfs1(v,now_dep+1);
            if(size[v]>size[mson[u]])mson[u]=v;
            size[u]+=size[v];
        }
    }
    void dfs2(ll u,ll now_top)
    {
        top[u]=now_top;
        if(mson[u])dfs2(mson[u],now_top);
        for(auto v:g[u])
            if(v!=fa[u]&&v!=mson[u])dfs2(v,v);
    }
    void build(ll n)
    {
        s.build(n+n);std::sort(ke+1,ke+tot+1);
        ll cnt=n;
        for(ll i=1;i<=tot;++i)
        {
            ll u=s.find(ke[i].u),v=s.find(ke[i].v);
            if(u!=v)
            {
                //printf("connect %lld and %lld,w=%lld\n",u,v,ke[i].w);
                val[++cnt]=ke[i].w;
                fa[u]=fa[v]=cnt;g[cnt].push_back(u),g[cnt].push_back(v);
                s.uni(u,cnt),s.uni(v,cnt);
            }
        }
        dfs1(cnt),dfs2(cnt,cnt);
    }
    ll get_max(ll u,ll v)
    {
        while(top[u]!=top[v])
        {
            if(dep[top[u]]>=dep[top[v]])u=fa[top[u]];
            else v=fa[top[v]];
        }
        if(dep[u]>=dep[v])return val[v];
        else return val[u];
    }
}
int main()
{
    ll n=read(),m=read(),k=read(),q=read();
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read(),w=read();
        adde(u,v,w),adde(v,u,w);
    }
    Dij(k);
    //for(ll i=1;i<=n;++i)printf("dis[%lld] = %lld\n",i,dis[i]);
    for(ll u=1;u<=n;++u)
        for(ll i=last[u];i;i=e[i].nxt)
        {
            ll v=e[i].v;
            if(u<v)Kru::adde(u,v,dis[u]+dis[v]+ e[i].w);
        }
    Kru::build(n);
    while(q--)
    {
        ll s=read(),t=read();
        printf("%lld\n",Kru::get_max(s,t));
    }
    return 0;
}