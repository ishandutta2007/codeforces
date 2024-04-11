#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+5;

ll read()
{
	ll s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(ll x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	ll to,nxt,val;
}e[N];
ll head[N],cnt=0;
void add(ll u,ll v,ll w)
{
	e[++cnt].to=v;
	e[cnt].val=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
ll a[N],dp[N];
namespace Segment_Tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	ll t[N*4],tag[N*4];
	void update(ll w,ll x)
	{
		t[w]+=x;
		tag[w]+=x;
	}
	void push_up(ll w)
	{
		t[w]=max(t[ls],t[rs]);
	}
	void push_down(ll w)
	{
		if (!tag[w]) return;
		update(ls,tag[w]);
		update(rs,tag[w]);
		tag[w]=0;
	}
	void add(ll w,ll l,ll r,ll L,ll R,ll x)
	{
		if (r<L||R<l) return;
		if (L<=l&&r<=R) return update(w,x);
		push_down(w);
		add(ls,l,mid,L,R,x);
		add(rs,mid+1,r,L,R,x);
		push_up(w);
	}
	ll QueryMax(ll w,ll l,ll r,ll L,ll R)
	{
		if (r<L||R<l) return 0;
		if (L<=l&&r<=R) return t[w];
		push_down(w);
		return max(QueryMax(ls,l,mid,L,R),QueryMax(rs,mid+1,r,L,R));
	}
}

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	ll n=read(),m=read();
	for (ll i=1;i<=n;i++) a[i]=read();
	for (ll i=1;i<=m;i++)
	{
		ll l=read(),r=read(),p=read();
		add(r,l,p);
	}
	for (ll i=1;i<=n;i++)
	{
		Segment_Tree::add(1,1,n,1,i,-a[i]);
		for (ll j=head[i];j;j=e[j].nxt)
		Segment_Tree::add(1,1,n,1,e[j].to,e[j].val);
		dp[i]=max(dp[i-1],Segment_Tree::QueryMax(1,1,n,1,i));
		Segment_Tree::add(1,1,n,i+1,i+1,dp[i]);
	}
	print(dp[n]);

	return 0;
}