#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;

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
int d[N],h[N];
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node
	{
		int ans,lmax,rmax,sum;
	}t[N*4];
	friend node operator +(const node &a,const node &b)
	{
		node ret;
		ret.ans=max({a.ans,b.ans,a.rmax+b.lmax});
		ret.sum=a.sum+b.sum;
		ret.lmax=max(a.lmax,a.sum+b.lmax);
		ret.rmax=max(b.rmax,b.sum+a.rmax);
		return ret;
	}
	void build(int w,int l,int r)
	{
		if (l==r) return void(t[w]=(node){0,h[l]*2,h[l]*2+d[l],d[l]});
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=t[ls]+t[rs];
	}
	node query(int w,int l,int r,int ql,int qr)
	{
		if (ql<=l&&r<=qr) return t[w];
		if (qr<=mid) return query(ls,l,mid,ql,qr);
		if (ql>mid) return query(rs,mid+1,r,ql,qr);
		return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
	}
	#undef mid
	#undef rs
	#undef ls
}t;

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=n*2,q=read();
	for (int i=1;i<=n;i++) d[i]=d[i+n]=read();
	for (int i=1;i<=n;i++) h[i]=h[i+n]=read();
	t.build(1,1,m);
	while (q--)
	{
		int l=read(),r=read();
		if (r<l) print(t.query(1,1,m,r+1,l-1).ans);
			else print(t.query(1,1,m,r+1,n+l-1).ans);
	}
	
	return 0;
}