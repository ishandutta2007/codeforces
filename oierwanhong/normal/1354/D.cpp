//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
typedef int ll;
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
#define MAXN 1000011
ll n,m;
struct Segment_Tree
{
    ll t[MAXN<<2|1];
    #define rt t[num]
    #define tl t[num<<1]
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
    ll Qmin()
    {
        if(!t[1])return 0;
        return Qkth(1);
    }
}sgt;
int main()
{
    n=read(),m=read();
    for(ll i=1;i<=n;++i)sgt.modify(read(),1);
    while(m--)
    {
        ll k=read();
        if(k<0)sgt.modify(sgt.Qkth(-k),-1);
        else sgt.modify(k,1);
    }
    printf("%d",sgt.Qmin());
    return 0;
}