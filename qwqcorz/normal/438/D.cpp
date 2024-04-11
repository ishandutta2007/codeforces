#include<bits/stdc++.h>
#define int long long
#define mid ((l+r)/2)
#define ls (w*2)
#define rs (w*2+1)
using namespace std;
const int N=1e5+5;

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
struct node
{
	int sum,Max;
	node operator +(const node &a)const
	{
		node ret;
		ret.sum=sum+a.sum;
		ret.Max=max(Max,a.Max);
		return ret;
	}
}t[N*4];
int a[N];
void build(int w,int l,int r)
{
	if (l==r) return void(t[w].Max=t[w].sum=a[l]);
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=t[ls]+t[rs];
}
void change(int w,int l,int r,int L,int R,int x)
{
	if (r<L||R<l) return;
	if (L<=r&&r<=R&&t[w].Max<x) return;
	if (l==r) return void(t[w].Max=t[w].sum=t[w].sum%x);
	change(ls,l,mid,L,R,x);
	change(rs,mid+1,r,L,R,x);
	t[w]=t[ls]+t[rs];
}
void cover(int w,int l,int r,int k,int x)
{
	if (r<k||k<l) return;
	if (l==r) return void(t[w].Max=t[w].sum=x);
	cover(ls,l,mid,k,x);
	cover(rs,mid+1,r,k,x);
	t[w]=t[ls]+t[rs];
}
int query(int w,int l,int r,int L,int R)
{
	if (r<L||R<l) return 0;
	if (L<=l&&r<=R) return t[w].sum;
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int opt=read();
		if (opt==1)
		{
			int l=read(),r=read();
			print(query(1,1,n,l,r));
		}
		if (opt==2)
		{
			int l=read(),r=read(),x=read();
			change(1,1,n,l,r,x);
		}
		if (opt==3)
		{
			int k=read(),x=read();
			cover(1,1,n,k,x);
		}
	}

	return 0;
}