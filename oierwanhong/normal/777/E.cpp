#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::string str;
typedef std::pair<ll,ll> pll;
ll read(){ll x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return f*x;}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
void umax(ll& a,ll t){if(t>a)a=t;}
const ll INF=1ll<<58;
#define MAXN 200011
ll diff;
ll fx[MAXN];
ll place(ll val){return std::lower_bound(fx+1,fx+diff+1,val)-fx;}
struct Segment_Tree
{
	ll t[MAXN<<2|1];
	#define rt t[num]
	void modify(un pos,ll k,un l=1,un r=diff,un num=1)
	{
		if(l==r){umax(rt,k);return;}
		un mid=(l+r)>>1;
		if(pos<=mid)modify(pos,k,l,mid,num<<1);
		else modify(pos,k,mid+1,r,num<<1|1);
		rt=max(t[num<<1],t[num<<1|1]);
	}
	ll Qmax(un ql,un qr,un l=1,un r=diff,un num=1)
	{
		if(ql<=l&&r<=qr)return rt;
		un mid=(l+r)>>1;ll ans=0;
		if(ql<=mid)umax(ans,Qmax(ql,qr,l,mid,num<<1));
		if(qr>mid)umax(ans,Qmax(ql,qr,mid+1,r,num<<1|1));
		return ans;
	}
}sgt;
struct one
{
	ll a,b,h;
	bool operator <(const one& t)const
	{
		if(b==t.b)return a>t.a;
		return b>t.b;
	}
}a[MAXN];
int main()
{
	ll n=read();
	for(ll i=1;i<=n;++i)fx[++diff]=a[i].a=read(),fx[++diff]=a[i].b=read(),a[i].h=read();
	std::sort(fx+1,fx+diff+1),diff=std::unique(fx+1,fx+diff+1)-fx-1;
	std::sort(a+1,a+n+1);
	for(ll i=1;i<=n;++i)
	{
		ll val=sgt.Qmax(1,place(a[i].b)-1);
		sgt.modify(place(a[i].a),val+a[i].h);
	}
	printf("%lld",sgt.Qmax(1,diff));
	return 0;
}