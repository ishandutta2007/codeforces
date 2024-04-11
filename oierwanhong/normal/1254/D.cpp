//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
const ll mod=998244353;
#define MAXN 150011
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
ll fa[MAXN],dep[MAXN],size[MAXN],mson[MAXN];
void dfs1(ll u,ll now_dep=1)
{
    dep[u]=now_dep,size[u]=1;
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(fa[u]==v)continue;
        fa[v]=u;
        dfs1(v,now_dep+1);
        if(size[v]>size[mson[u]])mson[u]=v;
        size[u]+=size[v];
    }
}
ll top[MAXN],dfn[MAXN],cur=0;
void dfs2(ll u,ll now_top)
{
    top[u]=now_top,dfn[u]=++cur;
    if(mson[u])dfs2(mson[u],now_top);
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v!=fa[u]&&v!=mson[u])dfs2(v,v);
    }
}
ll n,m;
struct BIT
{
    ll t[MAXN];
    #define lowb (i&-i)
    void modify(ll i,ll k)
    {
        while(i<=n)t[i]+=k,i+=lowb;
    }
    ll Qsum(ll i)
    {
        ll res=0;
        while(i)res=(res+t[i])%mod,i-=lowb;
        return res;
    }
}t;
ll val[MAXN];
ll Qpow(ll a,ll p)
{
    ll res=1;
    while(p)
    {
        if(p&1)res=res*a%mod;
        a=a*a%mod;
        p>>=1;
    }
    return res;
}
int main()
{
    n=read(),m=read();
    ll inv_n=Qpow(n,mod-2);
    for(ll i=1;i<n;++i)
    {
        ll u=read(),v=read();
        adde(u,v),adde(v,u);
    }
    dfs1(1),dfs2(1,1);
    while(m--)
    {
        ll op=read(),u=read();
        if(op==1)
        {
            ll k=read()*inv_n%mod;
            val[u]=(val[u]+k)%mod;
            if(mson[u])t.modify(dfn[mson[u]],(n-size[mson[u]])*k%mod),t.modify(dfn[mson[u]]+size[mson[u]],-(n-size[mson[u]])*k%mod);
            t.modify(1,size[u]*k%mod),t.modify(dfn[u],-size[u]*k%mod),t.modify(dfn[u]+size[u],size[u]*k%mod);
        }
        else
        {
            ll ans=(val[u]*n+t.Qsum(dfn[u]))%mod;
            while(u)
            {
                ans=(ans+val[fa[top[u]]]*(n-size[top[u]]))%mod;
                u=fa[top[u]];
            }
            printf("%lld\n",(ans+mod)%mod);
        }
    }
    return 0;
}