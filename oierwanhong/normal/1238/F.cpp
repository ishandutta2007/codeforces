//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
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
#define MAXN 300011
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
ll f[MAXN],ans;
ll dfs(ll u,ll fa=0)
{
    std::vector<ll>a;
    f[u]=1;
    for(ll i=last[u];i;i=e[i].nxt)
    {
        ll v=e[i].v;
        if(v==fa)continue;
        a.push_back(dfs(v,u));
    }
    std::sort(a.begin(),a.end()),std::reverse(a.begin(),a.end());
    if(a.size()>0)
    {
        f[u]=a[0]+a.size();
        umax(ans,a[0]+a.size()+!!fa);
    }
    if(a.size()>1)umax(ans,a[0]+a[1]+ll(a.size())-1+!!fa);
    return f[u];
}
int main()
{
    ll t=read();
    while(t--)
    {
        cnt=0;ans=1;
        ll n=read();
        for(ll i=1;i<=n;++i)last[i]=f[i]=0;
        for(ll i=1;i<n;++i)
        {
            ll u=read(),v=read();
            adde(u,v),adde(v,u);
        }
        dfs(1);
        printf("%lld\n",ans);
    }
}