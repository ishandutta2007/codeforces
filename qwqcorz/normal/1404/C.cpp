#include<bits/stdc++.h>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=3e5+5;
const int inf=1e9+7;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(int x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
struct Query
{
	int l,r,id;
	bool operator <(const Query &a)const
	{
		return l>a.l;
	}
}q[N];
int a[N],ans[N];
struct segment_tree
{
	struct node
	{
		pair<int,int>mx;
		int tot,tag;
		node operator +(const node &a)const
		{
			node ret;
			ret.tag=0;
			ret.mx=max(mx,a.mx);
			ret.tot=tot+a.tot;
			return ret;
		}
		void update(int x)
		{
			mx.fi+=x;
			tag+=x;
		}
	}t[N*4];
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	void build(int w,int l,int r)
	{
		if (l==r) return void(t[w]=(node){mk(-a[l],l),0,0});
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=t[ls]+t[rs];
	}
	void push_down(int w)
	{
		if (!t[w].tag) return;
		t[ls].update(t[w].tag);
		t[rs].update(t[w].tag);
		t[w].tag=0;
	}
	void add(int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return t[w].update(1);
		if (qr<l||r<ql) return;
		push_down(w);
		add(ls,l,mid,ql,qr);
		add(rs,mid+1,r,ql,qr);
		t[w]=t[ls]+t[rs];
	}
	void del(int w,int l,int r,int x)
	{
		if (l==r) return void(t[w]=(node){mk(-inf,l),1,0});
		push_down(w);
		if (x<=mid) del(ls,l,mid,x);
			   else del(rs,mid+1,r,x);
		t[w]=t[ls]+t[rs];
	}
	node query(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return (node){mk(-inf,0),0,0};
		if (ql<=l&&r<=qr) return t[w];
		push_down(w);
		return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
	}
	#undef ls
	#undef rs
	#undef mid
}t;

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),Q=read();
	for (int i=1;i<=n;i++) (a[i]=i-read())<0?a[i]=inf:0;
	for (int i=1;i<=Q;i++)
	{
		q[i].l=read()+1;
		q[i].r=n-read();
		q[i].id=i;
	}
	sort(q+1,q+1+Q);
	t.build(1,1,n);
	for (int i=n,j=1;i>=1;i--)
	{
		pair<int,int>tmp;
		while ((tmp=t.query(1,1,n,i,n).mx).fi==0)
		{
			t.del(1,1,n,tmp.se);
			t.add(1,1,n,tmp.se+1,n);
		}
		while (j<=Q&&q[j].l==i) ans[q[j].id]=t.query(1,1,n,1,q[j].r).tot,j++;
	}
	for (int i=1;i<=Q;i++) print(ans[i]);
	
	return 0;
}