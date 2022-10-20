#include<bits/stdc++.h>
#define int long long
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
using namespace std;
const int N=2e5+5;

inline int read()
{
	register int s=0;
	register char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(register int x)
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
inline void print(const register int x,const register char c='\n')
{
	write(x);
	putchar(c);
}
int a[N],sum[N],top;
struct node
{
	int id,val,tag;
	bool operator <(const node &a)const
	{
		return val<a.val;
	}
	void update(int x)
	{
		val+=x;
		tag+=x;
	}
}t[N*4],st[N];
void push_down(int w)
{
	if (t[w].tag==0) return;
	t[ls].update(t[w].tag);
	t[rs].update(t[w].tag);
	t[w].tag=0;
}
void change(int w,int l,int r,int x,int y)
{
	if (r<x||x<l) return;
	if (l==r) return void(t[w]=(node){x,y,0});
	push_down(w);
	change(ls,l,mid,x,y);
	change(rs,mid+1,r,x,y);
	t[w]=max(t[ls],t[rs]);
	t[w].tag=0;
}
void add(int w,int l,int r,int L,int R,int x)
{
	if (r<L||R<l) return;
	if (L<=l&&r<=R) return t[w].update(x);
	push_down(w);
	add(ls,l,mid,L,R,x);
	add(rs,mid+1,r,L,R,x);
	t[w]=max(t[ls],t[rs]);
	t[w].tag=0;
}
void build(int w,int l,int r)
{
	if (l==r) return void(t[w]=(node){l,sum[l]-2ll*sum[l-1],0});
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=max(t[ls],t[rs]);
	t[w].tag=0;
}

signed main()
{
	int n=read(),q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	build(1,1,n);
//	print(t[5].val);
	while (q --> 0)
	{
		int x=read(),y=read();
		if (x<n) add(1,1,n,x+1,n,a[x]-y);
		add(1,1,n,x,x,y-a[x]);
		
		
		a[x]=y;
		top=0;
		while (t[1].val>0)
		{
//			print(t[1].id,',');
			st[++top]=t[1];
			change(1,1,n,t[1].id,-1);
		}
//			print(t[1].id,',');
		if (t[1].val==0) print(t[1].id);
					else puts("-1");
		for (int i=1;i<=top;i++) change(1,1,n,st[i].id,st[i].val);
	}

	return 0;
}