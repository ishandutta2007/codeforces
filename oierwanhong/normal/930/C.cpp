//Wan Hong 3.1
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
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
#define MAXN 200011
ll n,m;
struct Segment_Tree
{
    ll t[MAXN<<2|1];
    #define rt t[num]
    #define tl t[num<<1]
    #define tr t[num<<1|1]
    void modify(un pos,ll k,un l=0,un r=n,un num=1)
    {
        if(l==r){rt=k;return;}
        un mid=(l+r)>>1;
        if(pos<=mid)modify(pos,k,l,mid,num<<1);
        else modify(pos,k,mid+1,r,num<<1|1);
        rt=max(tl,tr);
    }
    ll Qmax(un ql,un qr,un l=0,un r=n,un num=1)
    {
        if(ql<=l&&r<=qr)return rt;
        un mid=(l+r)>>1;
        ll ans=0;
        if(ql<=mid)umax(ans,Qmax(ql,qr,l,mid,num<<1));
        if(qr>mid)umax(ans,Qmax(ql,qr,mid+1,r,num<<1|1));
        return ans;
    }
}t0,t1;
ll a[MAXN];
int main()
{
    n=read(),m=read();
    for(ll i=1;i<=n;++i)
    {
        ll l=read(),r=read();
        ++a[l],--a[r+1];
    }
    for(ll i=1;i<=m;++i)a[i]+=a[i-1];
    for(ll i=1;i<=m;++i)
    {
        ll v=t0.Qmax(0,a[i]);
        t0.modify(a[i],v+1);
        t1.modify(a[i],max(t1.Qmax(a[i],n),v)+1);
    }
    printf("%lld",max(t0.Qmax(0,n),t1.Qmax(0,n)));
    return 0;
}