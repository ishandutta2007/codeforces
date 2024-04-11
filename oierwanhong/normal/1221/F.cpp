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
#define MAXN 1000011
ll len,fx[MAXN];
ll place(ll val){return std::lower_bound(fx+1,fx+len+1,val)-fx;}
struct node
{
    ll maxv,pos,tag;
    node(){maxv=-INF;}
    node operator +(const node& t)const
    {
    	node res;
    	if(maxv<t.maxv)return t;
    	return *this;
	}
};
struct Segment_Tree
{
    node t[MAXN<<2|1];
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    void pushup(un num)
    {
        if(tl.maxv>tr.maxv)rt.maxv=tl.maxv,rt.pos=tl.pos;
        else rt.maxv=tr.maxv,rt.pos=tr.pos;
    }
    void pushdown(un num)
    {
        if(rt.tag)
        {
            tl.maxv+=rt.tag,tl.tag+=rt.tag;
            tr.maxv+=rt.tag,tr.tag+=rt.tag;
            rt.tag=0;
        }
    }
    void build(un l=1,un r=len,un num=1)
    {
        if(l==r)rt.maxv=-fx[l],rt.pos=fx[l];
        else
        {
            un mid=(l+r)>>1;
            build(l,mid,num<<1),build(mid+1,r,num<<1|1);
            pushup(num);
        }
    }
    void modify(un ql,un qr,ll k,un l=1,un r=len,un num=1)
    {
        if(ql<=l&&r<=qr)
        {
            rt.maxv+=k,rt.tag+=k;return;
        }
        pushdown(num);
        un mid=(l+r)>>1;
        if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
        if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
        pushup(num);
    }
    node Qmax(un ql,un qr,un l=1,un r=len,un num=1)
    {
    	if(ql<=l&&r<=qr)return rt;
    	pushdown(num);
    	un mid=(l+r)>>1;node res;
    	if(ql<=mid)res=res+Qmax(ql,qr,l,mid,num<<1);
    	if(qr>mid)res=res+Qmax(ql,qr,mid+1,r,num<<1|1);
    	return res;
	}
}sgt;
struct seg
{
    ll l,r,v;
}a[MAXN];
std::vector<pll>p[MAXN];
int main()
{
    ll n=read();
    for(ll i=1;i<=n;++i)
    {
        ll x=read(),y=read(),v=read();
        fx[++len]=x,fx[++len]=y;
        a[i]={min(x,y),max(x,y),v};
    }
    std::sort(fx+1,fx+len+1);len=std::unique(fx+1,fx+len+1)-fx-1;
    sgt.build();
    for(ll i=1;i<=n;++i)
	{
		ll l=place(a[i].l),r=place(a[i].r);
		p[l].push_back(pll(r,a[i].v));
	}
    ll ans=0,ansl=ll(1e9)+1,ansr=ll(1e9)+1;
    for(ll i=len;i;--i)
    {
    	for(auto x:p[i])sgt.modify(x.first,len,x.second);
        node tmp=sgt.Qmax(i,len);
        if(umax(ans,tmp.maxv+fx[i]))ansl=fx[i],ansr=tmp.pos;
    }
    printf("%lld\n%lld %lld %lld %lld",ans,ansl,ansl,ansr,ansr);
    return 0;

}