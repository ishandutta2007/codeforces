#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
const int LOG=20;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int n;
namespace segment_tree
{
	#define mid ((l+r)/2)
	struct node
	{
		int sum,ls,rs;
	}t[N*LOG*LOG];
	int cntn=0;
	void add(int &w,int l,int r,int x,int y)
	{
		if (!w) w=++cntn;
		t[w].sum+=y;
		if (l==r) return;
		if (x<=mid) add(t[w].ls,l,mid,x,y);
			   else add(t[w].rs,mid+1,r,x,y);
	}
	int query(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return 0;
		if (ql<=l&&r<=qr) return t[w].sum;
		return query(t[w].ls,l,mid,ql,qr)+query(t[w].rs,mid+1,r,ql,qr);
	}
	#undef mid
}
using namespace segment_tree;
struct tree_node
{
	int w,mid,ls,rs,tot;
	ll sum,val;
}a[N*2];
void pushup(int w)
{
	a[w].sum=a[a[w].ls].sum+a[a[w].rs].sum
			+min(a[w].val,1LL*a[a[w].ls].tot*a[a[w].rs].tot-a[w].val);
}
int p[N],w[N],cnt=0;
int build(int l,int r)
{
	int now=++cnt;
	for (int i=l;i<=r;i++) if (i%2==1) add(a[now].w,1,n,p[i/2+1],1),a[now].tot++;
	if (l==r) return now;
	int mn=N,pos=0;
	for (int i=l;i<=r;i++) if (i%2==0&&mn>w[i/2]) mn=w[i/2],pos=i;
	a[now].mid=pos;
	a[now].ls=build(l,pos-1);
	a[now].rs=build(pos+1,r);
	for (int i=pos+1;i<=r;i++) if (i%2==1) a[now].val+=query(a[a[now].ls].w,1,n,1,p[i/2+1]);
	pushup(now);
	return now;
}
void update(int w,int l,int r,int x,int k,int y)
{
	add(a[w].w,1,n,k,y);
	if (x<a[w].mid) a[w].val+=y*query(a[a[w].rs].w,1,n,k,n);
			   else a[w].val+=y*query(a[a[w].ls].w,1,n,1,k);
	if (l<r)
	{
		if (x<a[w].mid) update(a[w].ls,l,a[w].mid-1,x,k,y);
				   else update(a[w].rs,a[w].mid+1,r,x,k,y);
	}
	pushup(w);
}

signed main()
{
	n=read();
	for (int i=1;i<=n;i++) p[i]=read();
	for (int i=1;i<n;i++) w[i]=read();
	int rt=build(1,n*2-1),Q=read();
	while (Q--)
	{
		int x=read(),y=read();
		update(rt,1,n*2-1,x*2-1,p[x],-1);
		update(rt,1,n*2-1,y*2-1,p[y],-1);
		swap(p[x],p[y]);
		update(rt,1,n*2-1,x*2-1,p[x],1);
		update(rt,1,n*2-1,y*2-1,p[y],1);
		print(a[1].sum);
	}
	
	return 0;
}