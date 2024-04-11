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
#define MAXN 200011
ll ind[MAXN],outd[MAXN],minv[MAXN];
std::vector<ll>g[MAXN],Rg[MAXN];
ll q[MAXN];
bool vis1[MAXN],vis2[MAXN];
void color1(ll u)
{
    vis1[u]=1;
    for(auto v:g[u])
        if(!vis1[v])color1(v);
}
void color2(ll u)
{
    vis2[u]=1;
    for(auto v:Rg[u])
        if(!vis2[v])color2(v);
}
char a[MAXN];
int main()
{
    ll n=read(),m=read();
    while(m--)
    {
        ll u=read(),v=read();
        g[u].push_back(v);++ind[v],++outd[u];
        Rg[v].push_back(u);
    }
    ll h=1,t=1;
    for(ll i=1;i<=n;++i)
        if(!ind[i])q[t++]=i;
    while(h<t)
    {
        ll u=q[h++];
        for(auto v:g[u])
        {
            if(!--ind[v])q[t++]=v;
        }
    }
    if(h<=n)return puts("-1")&0;
    ll ans=0;
    for(ll i=1;i<=n;++i)
    {
        if(!vis1[i]&&!vis2[i])++ans,a[i]='A';
        else a[i]='E';
        color1(i),color2(i);
    }
    printf("%lld\n%s",ans,a+1);
    return 0;
}