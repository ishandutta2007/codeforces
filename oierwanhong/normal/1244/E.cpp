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
const ll INF=1ll<<58;
/**********/
#define MAXN 100011
ll a[MAXN], fx[MAXN],c[MAXN],pre[MAXN],suf[MAXN],f[MAXN];
ll len;
ll place(ll val){return std::lower_bound(fx+1,fx+len+1,val)-fx;}
int main()
{
    ll n=read(),k=read();
    for(ll i=1;i<=n;++i)fx[++len]=a[i]=read();
    std::sort(fx+1,fx+len+1),len=std::unique(fx+1,fx+len+1)-fx-1;
    for(ll i=1;i<=n;++i)++c[place(a[i])];
    for(ll i=1;i<=len;++i)pre[i]=pre[i-1]+c[i];
    for(ll i=len;i;--i)suf[i]=suf[i+1]+c[i],f[i]=f[i+1]+suf[i+1]*(fx[i+1]-fx[i]);
    ll ans=INF,cost=0;
    for(ll i=1;i<=len;++i)
    {
        cost+=pre[i-1]*(fx[i]-fx[i-1]);
        if(cost>k)break;
        un l=i,r=len;
        while(l<r)
        {
            un mid=(l+r)>>1;
            if(f[mid]>k-cost)l=mid+1;
            else r=mid;
        }
        umin(ans,max(0,fx[r]-fx[i]-(k-cost-f[r])/suf[r]));
    }
    cost=0;
    for(ll i=1;i<=len;++i)f[i]=f[i-1]+pre[i-1]*(fx[i]-fx[i-1]);
    for(ll i=len;i;--i)
    {
        cost+=suf[i+1]*(fx[i+1]-fx[i]);
        if(cost>k)break;
        un l=1,r=i;
        while(l<r)
        {
            un mid=(l+r+1)>>1;
            if(f[mid]>k-cost)r=mid-1;
            else l=mid;
        }
        umin(ans,max(0,fx[i]-fx[r]-(k-cost-f[r])/pre[r]));
    }
    printf("%lld",ans);
    return 0;
}