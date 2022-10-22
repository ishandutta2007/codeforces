//Wan Hong 2.2
//home
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
typedef long long ll;
typedef std::pair<ll,ll> pll;
typedef std::string str;
#define INF (1ll<<58)
ll read()
{
	ll f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
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
bool umax(ll& a,ll b)
{
	if(b>a)return a=b,1;
	return 0;
}
bool umin(ll& a,ll b)
{
	if(b<a)return a=b,1;
	return 0;
}

/**********/
#define MAXN 1000011
struct Segment_Tree
{
	struct node
	{
		ll maxv,tag;
	}t[MAXN<<2|1];
	#define rt t[num]
	#define tl t[num<<1]
	#define tr t[num<<1|1]
	void pushup(ll num)
	{
		rt.maxv=max(tl.maxv,tr.maxv);
	}
	void build(ll* a,ll l=1,ll r=MAXN-1,ll num=1)
	{
		if(l==r)rt.maxv=a[l],rt.tag=0;
		else
		{
			ll mid=(l+r)>>1;
			build(a,l,mid,num<<1),build(a,mid+1,r,num<<1|1);
			pushup(num);
		}
	}
	void pushdown(ll l,ll r,ll num)
	{
		if(!rt.tag)return;
		ll mid=(l+r)>>1;
		tl.maxv+=rt.tag,tl.tag+=rt.tag;
		tr.maxv+=rt.tag,tr.tag+=rt.tag;
		rt.tag=0;
	}
	void modify(ll ql,ll qr,ll k,ll l=1,ll r=MAXN-1,ll num=1)
	{
		if(ql<=l&&r<=qr)
		{
			rt.maxv+=k,rt.tag+=k;
			return;
		}
		pushdown(l,r,num);
		ll mid=(l+r)>>1;
		if(ql<=mid)modify(ql,qr,k,l,mid,num<<1);
		if(qr>mid)modify(ql,qr,k,mid+1,r,num<<1|1);
		pushup(num);
	}
	ll Qmax()
	{
		return t[1].maxv;
	}
}sgt;
struct monsters
{
	ll a,b,v;
	bool operator <(const monsters& t)
	const
	{
		return a<t.a;
	}
}mon[MAXN];
struct weapons
{
	ll a,v;
	bool operator <(const weapons& t)
	const
	{
		return a<t.a;
	}
}a[MAXN];
ll c[MAXN];
int main()
{
	memset(c,0xcf,sizeof c);
	ll n=read(),m=read(),p=read(),ans=-INF;
	for(ll i=1;i<=n;++i)a[i].a=read(),a[i].v=read();
	std::sort(a+1,a+n+1);
	for(ll i=1;i<=m;++i)
	{
		ll x=read(),v=read();
		umax(c[x],-v);
	}
	sgt.build(c);
	for(ll i=1;i<=p;++i)mon[i].a=read(),mon[i].b=read(),mon[i].v=read();
	std::sort(mon+1,mon+p+1);
	ll it=1;
	for(ll i=1;i<=n;++i)
	{
		while(it<=p&&mon[it].a<a[i].a)sgt.modify(mon[it].b+1,MAXN-1,mon[it].v),++it;
		umax(ans,sgt.Qmax()-a[i].v);
	}
	printf("%lld",ans);
	return 0;
}