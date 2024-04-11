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
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
ll abs(ll x){return x>0?x:-x;}
/**********/
#define MAXN 2000011
#define MAXM 5000011
struct edge
{
    ll v,nxt;
}e[MAXM<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v)
{
    e[++cnt].v=v;
    e[cnt].nxt=last[u],last[u]=cnt;
}

ll dfn[MAXN],low[MAXN],scnt=0,scc[MAXN],cur=0;
bool ins[MAXN];
ll s[MAXN],top=0;
void tarjan(ll u)
{
    dfn[u]=low[u]=++cur;
    s[++top]=u,ins[u]=1;
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(!dfn[v])tarjan(v),umin(low[u],low[v]);
        else if(ins[v])umin(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        ++scnt;
        while(s[top]!=u)
        {
            scc[s[top]]=scnt,ins[s[top--]]=0;
        }
        scc[s[top]]=scnt,ins[s[top--]]=0;
    }
}
ll yes(ll x){return x<<1;}
ll no(ll x){return x<<1|1;}
ll n,p,M,m;
ll num(ll x){return p+1+x;}
int main()
{
    n=read(),p=read(),M=read(),m=read();
    for(ll i=1;i<=n;++i)
    {
        ll u=read(),v=read();
        adde(no(u),yes(v)),adde(no(v),yes(u));
    }
    for(ll i=1;i<=p;++i)
    {
        ll l=read(),r=read();
        adde(yes(i),no(num(l-1))),adde(yes(i),yes(num(r)));
        adde(yes(num(l-1)),no(i)),adde(no(num(r)),no(i));
    }
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=read();
        adde(yes(u),no(v)),adde(yes(v),no(u));
    }
    for(ll i=0;i<M;++i)adde(yes(num(i)),yes(num(i+1))),adde(no(num(i+1)),no(num(i)));
    adde(yes(num(0)),no(num(0)));
    for(ll i=1;i<=no(num(M));++i)
        if(!dfn[i])tarjan(i);
    for(ll i=1;i<=p+M+1;++i)
        if(scc[yes(i)]==scc[no(i)])return puts("-1")&0;
    ll ans=0;
    for(ll i=1;i<=p;++i)ans+=(scc[yes(i)]<scc[no(i)]);
    for(ll f=1;f<=M;++f)
        if(scc[yes(p+1+f)]<scc[no(p+1+f)]){printf("%d %d\n",ans,f);break;}
    for(ll i=1;i<=p;++i)
        if(scc[yes(i)]<scc[no(i)])printf("%d ",i);
    return 0;
}