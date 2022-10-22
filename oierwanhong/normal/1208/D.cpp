//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
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
#define MAXN 300011
ll n;
struct Segment_Tree
{
    ll t[MAXN<<2|1];
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    void modify(un pos,ll k,un l=1,un r=n,un num=1)
    {
        rt+=k;
        if(l==r)return;
        un mid=(l+r)>>1;
        if(pos<=mid)modify(pos,k,l,mid,num<<1);
        else modify(pos,k,mid+1,r,num<<1|1);
    }
    ll Qkth(ll k,un l=1,un r=n,un num=1)
    {
        if(l==r)return l;
        un mid=(l+r)>>1;
        if(k<=tl)return Qkth(k,l,mid,num<<1);
        else return Qkth(k-tl,mid+1,r,num<<1|1);
    }
}sgt;
ll a[MAXN],ans[MAXN];
int main()
{
    n=read();
    for(ll i=1;i<=n;++i)sgt.modify(i,i);
    for(ll i=1;i<=n;++i)a[i]=read();
    for(ll i=n;i;--i)
    {
        ans[i]=sgt.Qkth(a[i]+1);
        sgt.modify(ans[i],-ans[i]);
    }
    for(ll i=1;i<=n;++i)printf("%lld ",ans[i]);
}