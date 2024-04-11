#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
const int p=95542721;

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
int a[N];
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	const int p,len;
	segment_tree(int x,int y):p(x),len(y){}
	struct node
	{
		int k,sum[48],tag;
		inline void set(int x,int len,int p)
		{for (register int i=0;i<len;i++) sum[i+k>=len?i+k-len:i+k]=x,x=x*x%p*x%p;}
		inline void add(int len,int x=1)
		{
			(k+=x)>=len?k-=len:0;
			(tag+=x)>=len?tag-=len:0;
		}
	}t[N*4];
	inline void push_up(int w)
	{
		t[w].k=0;
		for (register int i=0;i<len;i++)
		t[w].sum[i]=t[ls].sum[i+t[ls].k>=len?i+t[ls].k-len:i+t[ls].k]
				   +t[rs].sum[i+t[rs].k>=len?i+t[rs].k-len:i+t[rs].k];
	}
	inline void push_down(int w)
	{
		if (!t[w].tag) return;
		t[ls].add(len,t[w].tag);
		t[rs].add(len,t[w].tag);
		t[w].tag=0;
	}
	void change(int w,int l,int r,int x,int y)
	{
		if (l==r) return t[w].set(y,len,p);
		push_down(w);
		if (x<=mid) change(ls,l,mid,x,y);
			   else change(rs,mid+1,r,x,y);
		push_up(w);
	}
	int query(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return 0;
		if (ql<=l&&r<=qr) return t[w].sum[t[w].k];
		push_down(w);
		return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
	}
	void power(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) return t[w].add(len);
		push_down(w);
		power(ls,l,mid,ql,qr);
		power(rs,mid+1,r,ql,qr);
		push_up(w);
	}
	void send(int n)
	{
		for (int i=1;i<=n;i++) change(1,1,n,i,a[i]);
	}
	#undef mid
	#undef rs
	#undef ls
}t(p,48);

signed main()
{
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	int Q=read(); t.send(n);
	for (int i=1;i<=Q;i++)
	{
		int opt=read(),l=read(),r=read();
		if (opt==1) print(t.query(1,1,n,l,r)%p);
			   else t.power(1,1,n,l,r);
	}
	
	return 0;
}