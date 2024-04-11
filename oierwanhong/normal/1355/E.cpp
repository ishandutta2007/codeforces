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
/**********/
#define MAXN 200011
ll a[MAXN],cost_add,cost_rm,cost_mv,n;
ll f(ll h)
{
    ll add=0,rm=0;
    for(ll i=1;i<=n;++i)
        if(a[i]>h)rm+=a[i]-h;
        else add+=h-a[i];
    if(add>rm)return rm*cost_mv+(add-rm)*cost_add;
    else return add*cost_mv+(rm-add)*cost_rm;
}
int main()
{
    n=read();cost_add=read(),cost_rm=read(),cost_mv=min(read(),cost_add+cost_rm);
    for(ll i=1;i<=n;++i)a[i]=read();
    ll l=0,r=ll(1e9);
    while(l+2<r)
    {
        ll k=(r-l)/3;
        ll mid1=l+k,mid2=r-k;
        if(f(mid1)<=f(mid2))r=mid2;
        else l=mid1;
    }
    ll ans=f(l);
    for(ll x=l+1;x<=r;++x)umin(ans,f(x));
    printf("%lld",ans);
    return 0;
}