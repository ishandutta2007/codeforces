//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
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
const ll INF=1<<28;
/**********/
#define MAXN 200011
ll n,pos[MAXN];
struct Segment_Tree
{
    ll t[MAXN<<2|1];
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    void modify(un p,ll k,un l=0,un r=n,un num=1)
    {
        if(l==r){rt+=k;return;}
        un mid=(l+r)>>1;
        if(p<=mid)modify(p,k,l,mid,num<<1);
        else modify(p,k,mid+1,r,num<<1|1);
        rt=min(tl,tr);
    }
    ll Qmin(un ql,un qr,un l=0,un r=n,un num=1)
    {
        if(ql<=l&&r<=qr)return rt;
        un mid=(l+r)>>1;ll ans=INF;
        if(ql<=mid)umin(ans,Qmin(ql,qr,l,mid,num<<1));
        if(qr>mid)umin(ans,Qmin(ql,qr,mid+1,r,num<<1|1));
        return ans;
    }
}sgt;
int main()
{
    ll n1=read(),n2=read(),n3=read();
    n=n1+n2+n3;
    for(ll i=1;i<=n1;++i)pos[read()]=1;
    for(ll i=1;i<=n2;++i)pos[read()]=2;
    for(ll i=1;i<=n3;++i)pos[read()]=3;
    ll delta=n1+n2,ans=delta;
    for(ll i=1;i<=n;++i)
    {
    	if(pos[i]==2)--delta;
        else if(pos[i]==3)++delta;
    	ll tmp=sgt.Qmin(i-1,i-1)+delta;
    	if(pos[i]==1)--tmp;
        else if(pos[i]==2)++tmp;
        sgt.modify(i,tmp-delta);
        //printf("delta=%lld,tmp=%lld,minv=%lld\n",delta,tmp,sgt.Qmin(0,i)+delta);
        umin(ans,sgt.Qmin(0,i)+delta);
    }
    printf("%lld",ans);
    return 0;
}