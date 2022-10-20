#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
const int inf=1LL<<60;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,nxt;
}e[N];
int head[N],cnte=0;
void add_edge(int u,int v)
{
	e[++cnte].to=v;
	e[cnte].nxt=head[u];
	head[u]=cnte;
}
int c[N],d[N],a[N],b[N],st[N],ed[N],cntdfn=0;
void dfs(int now,int father)
{
	c[now]+=c[father];
	d[now]+=d[father];
	st[now]=++cntdfn;
	for (int i=head[now];i;i=e[i].nxt)
	{
		int to=e[i].to;
		dfs(to,now);
	}
	ed[now]=cntdfn;
}
template<int f>
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node
	{
		int mn,a,b,tag;
		node(int B=0,int C=0,int D=0,int E=0){mn=B,a=C,b=D,tag=E;}
		bool add(int x)
		{
			if (x<=mn) return tag+=x,a+=x,mn-=x,1;
			else return 0;
		}
	}t[N*4];
	friend node operator +(node a,node b)
	{
		if (a.a*a.b*f<b.a*b.b*f) swap(a,b);
		int tmp=b.b!=a.b?(a.a*a.b-b.a*b.b)/(b.b-a.b):inf;
		if (tmp<0) tmp=inf;
		return (node){min({a.mn,b.mn,tmp}),a.a,a.b};
	}
	void push_down(int w)
	{
		if (!t[w].tag) return;
		assert(t[ls].add(t[w].tag));
		assert(t[rs].add(t[w].tag));
		t[w].tag=0;
	}
	void add(int w,int l,int r,int ql,int qr,int x)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) if (t[w].add(x)) return;
		if (l==r) return t[w].a+=x,t[w].tag+=x,void();
		push_down(w);
		add(ls,l,mid,ql,qr,x);
		add(rs,mid+1,r,ql,qr,x);
		t[w]=t[ls]+t[rs];
	}
	int query(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return 0;
		if (ql<=l&&r<=qr) return t[w].a*t[w].b;
		push_down(w);
		return max(query(ls,l,mid,ql,qr)*f,query(rs,mid+1,r,ql,qr)*f)*f;
	}
	void build(int w,int l,int r)
	{
		if (l==r) return void(t[w]=(node){inf,a[l],b[l]});
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=t[ls]+t[rs];
	}
	#undef mid
	#undef rs
	#undef ls
};
segment_tree<+1> t1;
segment_tree<-1> t2;

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),q=read();
	for (int i=2;i<=n;i++) add_edge(read(),i);
	for (int i=1;i<=n;i++) c[i]=read();
	for (int i=1;i<=n;i++) d[i]=read();
	dfs(1,0);
	for (int i=1;i<=n;i++) a[st[i]]=c[i];
	for (int i=1;i<=n;i++) b[st[i]]=abs(d[i]);
	t1.build(1,1,n);
	t2.build(1,1,n);
	while (q--)
	{
		int opt=read(),v=read(),x=opt==1?read():0;
		if (opt==1)
			t1.add(1,1,n,st[v],ed[v],x),
			t2.add(1,1,n,st[v],ed[v],x);
		else
			print(max(t1.query(1,1,n,st[v],ed[v]),-t2.query(1,1,n,st[v],ed[v])));
	}
	
	return 0;
}