//Wan Hong 3.1
//home
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
typedef long long ll;
typedef unsigned un;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll x=0,f=1;
	char c;
	do
	{
		c=getchar();
		if(c=='-')f=-1;
	}while(c<'0'||c>'9');
	do
	{
		x=x*10+c-'0';
		c=getchar();
	}while(c>='0'&&c<='9');
	return f*x;
}
ll min(ll a,ll b)
{
	return a<b?a:b;
}
ll max(ll a,ll b)
{
	return a>b?a:b;
}
bool umin(ll &a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}
bool umax(ll &a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
/**********/
#define MAXN 300011
ll n;
struct Segment_Tree
{
    struct node
    {
        ll maxv,tag;
    }t[MAXN<<2|1];
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    void pushdown(un num)
    {
        if(!rt.tag)return;
        tl.maxv+=rt.tag,tl.tag+=rt.tag;
        tr.maxv+=rt.tag,tr.tag+=rt.tag;
        rt.tag=0;
    }
    void modify(un ql,un qr,ll k,un l=1,un r=n,un num=1)
    {
        if(ql<=l&&r<=qr)
        {
            rt.maxv+=k;
            rt.tag+=k;
            return;
        }
        pushdown(num);
        un mid=(l+r)>>1;
        if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
        if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
        rt.maxv=max(tl.maxv,tr.maxv);
    }
    ll Qmax()
    {
        return t[1].maxv;
    }
}sgt;
ll p[MAXN],dex[MAXN],ans[MAXN];
int main()
{
    n=read();
    ll cur=n;
    for(ll i=1;i<=n;++i)p[i]=read(),dex[p[i]]=i;
    sgt.modify(1,dex[cur],1);
    for(ll i=1;i<=n;++i)
    {
        while(sgt.Qmax()<=0)sgt.modify(1,dex[--cur],1);
        ans[i]=cur;
        sgt.modify(1,read(),-1);
    }
    for(ll i=1;i<=n;++i)printf("%lld ",ans[i]);
    return 0;
}