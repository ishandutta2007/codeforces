//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
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
#define MAXN 5011
#define MAXM 200011
struct edge
{
    ll v,w,cost,nxt;
}e[MAXM<<1|1];
ll cnt=1,last[MAXN],cur[MAXN];
void adde(ll u,ll v,ll w,ll c)
{
    e[++cnt]={v,w,c,last[u]},last[u]=cnt;
    e[++cnt]={u,0,-c,last[v]},last[v]=cnt;
}
ll dis[MAXN];
bool vis[MAXN],inq[MAXN];
bool spfa(ll s,ll t,ll n)
{
    for(ll i=1;i<=n;++i)vis[i]=0,dis[i]=INF,cur[i]=last[i];
    std::queue<ll>q;
    dis[s]=0;q.push(s);
    while(q.size())
    {
        ll u=q.front();inq[u]=0;q.pop();
        for(ll i=last[u];i;i=e[i].nxt)
        {
            ll v=e[i].v;
            if(e[i].w>0&&umin(dis[v],dis[u]+e[i].cost))
                if(!inq[v])q.push(v),inq[v]=1;
        }
    }
    return dis[t]<INF;
}
ll sumc=0;
ll ex_flow(ll u,ll t,ll flow=INF)
{
    if(u==t)return flow;
    vis[u]=1;
    ll f=0;
    for(ll& i=cur[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(e[i].w>0&&!vis[v]&&dis[v]==dis[u]+e[i].cost)
        {
            ll tmp=ex_flow(v,t,min(e[i].w,flow-f));
            e[i].w-=tmp,e[i^1].w+=tmp;
            sumc+=tmp*e[i].cost;
            f+=tmp;
            if(f==flow)return f;
        }
    }
    return f;
}
pll min_cost_zkw(ll s,ll t,ll n)
{
    ll res=0;
    while(spfa(s,t,n))res+=ex_flow(s,t);
    return pll(res,sumc);
}
char s1[MAXN],s2[MAXN];
ll a[MAXN],numR[MAXM],numB[MAXM];
int main()
{
    ll n1=read(),n2=read(),m=read(),r=read(),b=read();scanf("%s%s",s1+1,s2+1);
    ll s=n1+n2+1,t=s+1,S=t+1,T=S+1,sum=0;
    for(ll i=1;i<=n1;++i)
        if(s1[i]=='B')--a[i],++a[t],adde(i,t,INF,0);
        else if(s1[i]=='R')--a[s],++a[i],adde(s,i,INF,0);
        else --a[s],++a[t],adde(s,i,INF,0),adde(i,t,INF,0);
    for(ll i=1;i<=n2;++i)
        if(s2[i]=='R')--a[n1+i],++a[t],adde(n1+i,t,INF,0);
        else if(s2[i]=='B')--a[s],++a[n1+i],adde(s,n1+i,INF,0);
        else --a[s],++a[t],adde(s,n1+i,INF,0),adde(n1+i,t,INF,0);
    adde(t,s,INF,0);
    for(ll i=1;i<=m;++i)
    {
        ll u=read(),v=n1+read();
        numR[i]=cnt+1,adde(u,v,1,r);
        numB[i]=cnt+1,adde(v,u,1,b);
    }
    for(ll i=1;i<=n1+n2+2;++i)
        if(a[i]>0)adde(S,i,a[i],0),sum+=a[i];
        else if(a[i]<0)adde(i,T,-a[i],0);
    pll res=min_cost_zkw(S,T,T);
    if(res.first<sum)return puts("-1")&0;
    printf("%lld\n",res.second);
    for(ll i=1;i<=m;++i)
        if(e[numR[i]^1].w)putchar('R');
        else if(e[numB[i]^1].w)putchar('B');
        else putchar('U');
}