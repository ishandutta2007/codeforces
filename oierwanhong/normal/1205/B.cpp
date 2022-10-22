//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 1011
ll a[200011],dis[MAXN],n,ans=ll(1e6);
ll q[MAXN],pre[MAXN];
void bfs(ll s)
{
    memset(dis,0,sizeof dis);memset(pre,0,sizeof pre);
    dis[s]=1;
    ll h=1,t=1;
    q[t++]=s;
    while(h<t)
    {
        ll u=q[h++];
        for(ll v=1;v<=n;++v)
            if((u!=v&&v!=pre[u])&&(a[u]&a[v]))
            {
                if(!dis[v])pre[v]=u,dis[v]=dis[u]+1,q[t++]=v;
                else umin(ans,dis[u]+dis[v]-1);
            }
    }
}
int main()
{
    ll all=read();
    for(ll i=1;i<=all;++i)
    {
        ll x=read();
        if(x)a[++n]=x;
    }
    if(n>64*2)return puts("3")&0;
    for(ll i=1;i<=n;++i)bfs(i);
    if(ans>n)puts("-1");
    else printf("%lld",ans);
    return 0;
}