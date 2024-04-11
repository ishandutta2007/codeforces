#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
void umin(ll& a,ll t){if(t<a)a=t;}
const ll INF=1ll<<50;
#define MAXN 200011
struct edge
{
    ll v,w,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v,ll w)
{
    e[++cnt].v=v,e[cnt].w=w;
    e[cnt].nxt=last[u],last[u]=cnt;
}
bool vis[MAXN],ring[MAXN],find=0;
ll a[MAXN],s[MAXN],top=0;
ll maxv=0,len[MAXN],d1[MAXN],d2[MAXN],cnt_ring=0;
void dfs1(ll u,ll fa=0)
{
    vis[u]=1,s[++top]=u;
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa)continue;
        if(!vis[v])dfs1(v,u);
        else
        {
            while(s[top]!=v)ring[s[top]]=1,a[++cnt_ring]=s[top],--top;
            ring[v]=1,a[++cnt_ring]=v;
            find=1;
        }
        if(find)return;
    }
    --top;
}

ll pred[MAXN],sufd[MAXN],prelen[MAXN],suflen[MAXN];
void dfs2(ll u,ll rt,ll fa)
{
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(ring[v]||v==fa)continue;
        dfs2(v,rt,u);
        umax(maxv,len[u]+e[i].w+len[v]);
        umax(len[u],e[i].w+len[v]);
    }
}
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)
    {
        ll u=read(),v=read(),w=read();
        adde(u,v,w),adde(v,u,w);
    }
    dfs1(1);
    for(ll x=1;x<=cnt_ring;++x)dfs2(a[x],a[x],0);
    pred[1]= prelen[1]=len[a[1]];
    ll d=0,tmp=len[a[1]];
    for(ll x=2;x<=cnt_ring;++x)
    {
        for(ll i=last[a[x]];i;i=e[i].nxt)
            if(e[i].v==a[x-1])d+=e[i].w;
        if(x>1)prelen[x]=max(prelen[x-1],d+len[a[x]]);
        pred[x]=max(pred[x-1],d+len[a[x]]+tmp);
        umax(tmp,len[a[x]]-d);
    }
    sufd[cnt_ring+1]=suflen[cnt_ring+1]=-INF;
    tmp=d=0;
    a[cnt_ring+1]=a[1];
    for(ll x=cnt_ring;x;--x)
    {
        for(ll i=last[a[x]];i;i=e[i].nxt)
            if(e[i].v==a[x+1])d+=e[i].w;
        suflen[x]=max(suflen[x+1],d+len[a[x]]);
        //printf("suflen %lld=%lld,d=%lld\n",a[x],suflen[x],d);
        sufd[x]=max(sufd[x+1],d+len[a[x]]+tmp);
        umax(tmp,len[a[x]]-d);
    }
    ll ans=INF;
    for(ll x=1;x<=cnt_ring;++x)
    {
        //printf("x=%lld,prelen=%lld,suflen=%lld,pred=%lld,sufd=%lld\n",a[x],prelen[x],suflen[x+1],pred[x],sufd[x+1]);
        umin(ans,max(maxv,max(prelen[x]+suflen[x+1],max(pred[x],sufd[x+1]))));
    }
    printf("%lld",ans);
    return 0;
}