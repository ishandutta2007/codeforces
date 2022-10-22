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
struct node
{
    ll minv[10],ans;
    node(){memset(minv,0x3f,sizeof minv),ans=INF;}
    node operator +(const node& t)
    {
        node res;
        res.ans=min(ans,t.ans);
        for(ll i=0;i<9;++i)res.minv[i]=min(minv[i],t.minv[i]),umin(res.ans,minv[i]+t.minv[i]);
        return res;
    }
};
ll n,m;
struct Segment_Tree
{
    node t[MAXN<<2|1];
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    void modify(un pos,ll k,un l=1,un r=n,un num=1)
    {
        if(l==r)
        {
            rt=node();
            ll x=k;
            for(ll i=0;i<9;x/=10,++i)
                if(x%10)rt.minv[i]=k;
            return;
        }
        un mid=(l+r)>>1;
        if(pos<=mid)modify(pos,k,l,mid,num<<1);
        else modify(pos,k,mid+1,r,num<<1|1);
        rt=tl+tr;
    }
    node Query(un ql,un qr,un l=1,un r=n,un num=1)
    {
        if(ql<=l&&r<=qr)return rt;
        un mid=(l+r)>>1;
        node res;
        if(ql<=mid)res=res+Query(ql,qr,l,mid,num<<1);
        if(qr>mid)res=res+Query(ql,qr,mid+1,r,num<<1|1);
        return res;
    }
}sgt;
int main()
{
    n=read(),m=read();
    for(ll i=1;i<=n;++i)sgt.modify(i,read());
    while(m--)
    {
        ll op=read(),x=read(),y=read();
        if(op==1)sgt.modify(x,y);
        else
        {
            ll ans=sgt.Query(x,y).ans;
            printf("%lld\n",ans>ll(1e10)?-1ll:ans);
        } 
    }
    return 0;
}