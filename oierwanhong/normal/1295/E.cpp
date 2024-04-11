//By Luogu send again
//Wan Hong 2.2
//notebook
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
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
ll n;
struct Segment_Tree
{
	struct node
	{
		ll minv,tag;
	}t[MAXN<<2|1];
	#define rt t[num]
	#define tl t[num<<1]
	#define tr t[num<<1|1]
	void pushup(un num)
	{
		rt.minv=min(tl.minv,tr.minv);
	}
	void pushdown(un l,un r,un num)
	{
		if(!rt.tag)return;
		tl.minv+=rt.tag,tl.tag+=rt.tag;
		tr.minv+=rt.tag,tr.tag+=rt.tag;
		rt.tag=0;
	}
	void modify(ll ql,ll qr,ll k,un l=0,un r=n,un num=1)
	{
		if(ql<=l&&r<=qr)
		{
			rt.minv+=k;
			rt.tag+=k;
			return;
		}
		pushdown(l,r,num);
		un mid=(l+r)>>1;
		if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
		if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
		pushup(num);
	}
	ll Qmin()
	{
		return t[1].minv;
	}
}sgt;
ll p[MAXN],a[MAXN];
int main()
{
	n=read();
	for(ll i=1;i<=n;++i)p[i]=read();
	for(ll i=1;i<=n;++i)a[i]=read();
	for(ll i=1;i<=n;++i)
		sgt.modify(p[i],n,a[i]);
	ll ans=INF;
	for(ll i=1;i<n;++i)//[1,i],[i+1,n]
	{
		sgt.modify(p[i],n,-a[i]);
		sgt.modify(0,p[i]-1,a[i]);
		umin(ans,sgt.Qmin());
	}
	printf("%lld",ans);
	return 0;
}