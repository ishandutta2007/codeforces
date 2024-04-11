#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
const ll INF=1ll<<58;
#define MAXN 200011
ll c[MAXN],n;
struct BIT
{
    ll t[MAXN];
    #define lowb (i&-i)
    void modify(ll i,ll k)
    {
        while(i<=n)t[i]+=k,i+=lowb;
    }
    ll Qsum(ll i)
    {
        ll res=0;
        while(i)res+=t[i],i-=lowb;
        return res;
    }
    ll Bestpos(ll k)
    {
        ll l=0,r=n;
        while(l<r)
        {
            ll mid=(l+r+1)>>1;
            if(Qsum(mid)<=k)l=mid;
            else r=mid-1;
        }
        return l+1;
    }
}t;
ll a[MAXN];
int main()
{
    n=read();
    for(ll i=1;i<=n;++i)a[i]=read()+1,t.modify(a[i],1);
    for(ll i=1;i<=n;++i)
    {
    	t.modify(a[i],-1);
        c[i]+=t.Qsum(a[i]);
        
    }
    for(ll i=1;i<=n;++i)a[i]=read()+1,t.modify(a[i],1);
    for(ll i=1;i<=n;++i)
    {
    	t.modify(a[i],-1);
        c[i]+=t.Qsum(a[i]);
    }
    for(ll i=n-1;i;--i)
        c[i-1]+=c[i]/(n-i+1),c[i]%=(n-i+1);
    for(ll i=1;i<=n;++i)t.modify(i,1);
    for(ll i=1;i<=n;++i)
    {
        ll x=t.Bestpos(c[i]);
        t.modify(x,-1);
        printf("%lld ",x-1);
    }
    return 0;
}