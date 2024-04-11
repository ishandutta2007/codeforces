//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
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
#define MAXN 200011
ll a[MAXN];
struct one
{
    ll l,r,d;
    void in(){l=read(),r=read(),d=read();}
}trap[MAXN];
ll n,m,k,ti,c[MAXN];
bool check(ll mid)
{
	for(ll i=1;i<=m+1;++i)c[i]=0;
	for(ll i=1;i<=k;++i)
		if(trap[i].d>mid)
			if(trap[i].l<=trap[i].r)++c[trap[i].l],--c[trap[i].r+1];
	for(ll i=1;i<=m+1;++i)c[i]+=c[i-1];
	ll res=m+1;
	for(ll i=1;i<=m+1;++i)res+=2*!!c[i];
	return res<=ti;
}
int main()
{
    n=read(),m=read(),k=read(),ti=read();
    for(ll i=1;i<=n;++i)a[i]=read();
    for(ll i=1;i<=k;++i)trap[i].in();
    un l=1,r=MAXN;
    while(l<r)
    {
        un mid=(l+r)>>1;
        if(check(mid))r=mid;
        else l=mid+1;
    }
    ll ans=0;
    for(ll i=1;i<=n;++i)ans+=(a[i]>=l);
    printf("%lld",ans);
    return 0;
}