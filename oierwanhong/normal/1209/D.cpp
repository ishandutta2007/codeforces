//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef int ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 200011
struct DSU
{
    ll fa[MAXN];
    void build(ll n)
    {
        for(ll i=1;i<=n;++i)fa[i]=i;
    }
    ll find(ll x)
    {
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    void uni(ll u,ll v)
    {
        u=find(u),v=find(v);
        fa[u]=v;
    }
    bool same(ll u,ll v){return find(u)==find(v);}
}s;
int main()
{
    ll n=read(),k=read(),ans=0;
    s.build(n);
    for(ll i=1;i<=k;++i)
    {
        ll a=read(),b=read();
        if(s.same(a,b))++ans;
        else s.uni(a,b);
    }
    std::cout<<ans;
}