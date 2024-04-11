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
#define INF (1ll<<58)
ll read(){ll f=1,x=0;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
bool umax(ll& a,ll b){if(b>a)return a=b,1;return 0;}
bool umin(ll& a,ll b){if(b<a)return a=b,1;return 0;}
/**********/
#define MAXN 500011
struct edge
{
    ll v,w,nxt;
}e[MAXN<<1|1];
ll cnt=0,last[MAXN];
void adde(ll u,ll v,ll w)
{
    e[++cnt]={v,w,last[u]},last[u]=cnt;
    e[++cnt]={u,w,last[v]},last[v]=cnt;
}
ll f[2][MAXN],n,k;
void dfs(ll u,ll fa=0)
{
    std::priority_queue<ll>q;
    ll sum=0;
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa)continue;
        dfs(v,u);
        sum+=f[0][v];
        if(f[1][v]+e[i].w-f[0][v]>0)q.push(f[1][v]+e[i].w-f[0][v]);
    }
    ll cur=1;
    while(!q.empty()&&cur<k)sum+=q.top(),q.pop(),++cur;
    f[0][u]=f[1][u]=sum;
    if(!q.empty())f[0][u]+=q.top();
}
int main()
{
    ll task=read();
    while(task--)
    {
        n=read(),k=read();
        cnt=0;for(ll i=1;i<=n;++i)last[i]=0,f[0][i]=f[1][i]=0;
        for(ll i=1;i<n;++i)
        {
            ll u=read(),v=read(),w=read();
            adde(u,v,w);
        }
        dfs(1);
        printf("%lld\n",max(f[0][1],f[1][1]));
    }
    return 0;
}