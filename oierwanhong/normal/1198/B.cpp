//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	char c;
	ll f=1,x=0;
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
ll max(ll a,ll b)
{
	return a>b?a:b;
}
ll min(ll a,ll b)
{
    return a<b?a:b;
}

/**********/
#define MAXN 200011
ll n;
struct Segment_Tree
{
	struct node
	{
		ll v,tag;
	}t[MAXN<<2|1];
	#define rt t[num]
	#define tl t[num<<1]
	#define tr t[num<<1|1]
	void pushdown(un l,un r,un num)
	{
		if(rt.tag==-1)return;
		un mid=(l+r)>>1;
		tl.v=max(tl.v,rt.tag);
		tl.tag=max(tl.tag,rt.tag);
		tr.v=max(tr.v,rt.tag);
		tr.tag=max(tr.tag,rt.tag);
		rt.tag=-1;
	}
	void build(un l=1,un r=n,un num=1)
	{
		if(l==r)rt.v=read();
		else
		{
			un mid=(l+r)>>1;
			build(l,mid,num<<1);build(mid+1,r,num<<1|1);
		}
		rt.tag=-1;
	}
	void mpoint(un p,ll x,un l=1,un r=n,un num=1)
	{
		if(l==r)
		{
			if(l==p)rt.v=x;
			return;
		}
		un mid=(l+r)>>1;
		pushdown(l,r,num);
		if(p<=mid)mpoint(p,x,l,mid,num<<1);
		else mpoint(p,x,mid+1,r,num<<1|1);
	}
	void mpart(ll x,un l=1,un r=n,un num=1)
	{
		rt.v=rt.tag=max(rt.tag,x);
	}
	ll qpoint(un p,un l=1,un r=n,un num=1)
	{
		if(l==r)
		{
			if(l==p)return rt.v;
			return 0;
		}
		un mid=(l+r)>>1;
		pushdown(l,r,num);
		if(p<=mid)return qpoint(p,l,mid,num<<1);
		else return qpoint(p,mid+1,r,num<<1|1);
	}
}sgt;
int main()
{
	n=read();
	sgt.build();
	ll m=read();
	for(ll i=1;i<=m;++i)
	{
		ll op=read();
		if(op==2)
		{
			sgt.mpart(read());
		}
		else
		{
			ll p=read(),x=read();
			sgt.mpoint(p,x);
		}
	}
	for(ll i=1;i<=n;++i)printf("%lld ",sgt.qpoint(i));
	return 0;
}