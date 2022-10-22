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
#define MAXN 2511
struct point
{
    ll x,y,k;
}a[MAXN];
ll getw(point a,point b){return (a.k+b.k)*(abs(a.y-b.y)+abs(a.x-b.x));}
struct edge
{
    ll u,v,w;
    bool operator <(const edge& t)const{return w<t.w;}
}e[MAXN*MAXN];
struct DSU
{
    ll fa[MAXN];
    void build(ll n){for(ll i=1;i<=n;++i)fa[i]=i;}
    ll find(ll x)
    {
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    bool uni(ll u,ll v)
    {
        u=find(u),v=find(v);
        if(u==v)return 0;
        fa[u]=v;return 1;
    }
}s;
ll sta[MAXN];
std::vector<pll>ed;
int main()
{
    ll n=read(),m=0;
    s.build(n+1);
    for(ll i=1;i<=n;++i)a[i].x=read(),a[i].y=read();
    for(ll i=1;i<=n;++i)e[++m]={n+1,i,read()};
    for(ll i=1;i<=n;++i)a[i].k=read();
    for(ll i=1;i<=n;++i)
        for(ll j=i+1;j<=n;++j)e[++m]={i,j,getw(a[i],a[j])};
    std::sort(e+1,e+m+1);
    ll ans=0,v=0;
    for(ll i=1;i<=m;++i)
        if(s.uni(e[i].u,e[i].v))
        {
            ans+=e[i].w;
            if(e[i].u==n+1)sta[e[i].v]=1,++v;
            else ed.push_back(pll(e[i].u,e[i].v));
        }
    printf("%lld\n%lld\n",ans,v);
    for(ll i=1;i<=n;++i)
        if(sta[i])printf("%lld ",i);
    printf("\n%llu\n",ed.size());
    for(auto x:ed)printf("%lld %lld\n",x.first,x.second);
    return 0;
}