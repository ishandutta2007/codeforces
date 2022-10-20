#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
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
int a[N];
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
int tmp[4];
struct node
{
	int m1[10],m2[10];
	void set(int k)
	{
		int tmp=k;
		for (int i=0;i<=9;i++)
		{
			int x=tmp%10;
			tmp/=10;
			m1[i]=x?k:inf;
			m2[i]=inf;
		}
	}
	node operator +(const node &a)
	{
		node ret=*this;
		for (int i=0;i<=9;i++)
		{
			tmp[0]=ret.m1[i];
			tmp[1]=ret.m2[i];
			tmp[2]=a.m1[i];
			tmp[3]=a.m2[i];
			sort(tmp,tmp+4);
			ret.m1[i]=tmp[0];
			ret.m2[i]=tmp[1];
		}
		return ret;
	}
}t[N*4];
void build(int w,int l,int r)
{
	if (l==r) return t[w].set(a[l]);
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=t[ls]+t[rs];
}
void change(int w,int l,int r,int x,int y)
{
	if (l==r) return t[w].set(y);
	if (x<=mid) change(ls,l,mid,x,y);
		   else change(rs,mid+1,r,x,y);
	t[w]=t[ls]+t[rs];
}
node query(int w,int l,int r,int ql,int qr)
{
	if (ql<=l&&r<=qr) return t[w];
	if (qr<=mid) return query(ls,l,mid,ql,qr);
	if (ql>mid) return query(rs,mid+1,r,ql,qr);
	return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
}
#undef ls
#undef rs
#undef mid

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int opt=read(),x=read(),y=read();
		if (opt==1) change(1,1,n,x,y);
		else
		{
			node ret=query(1,1,n,x,y);
			int ans=inf*2;
			for (int i=0;i<=9;i++)
			if (ret.m1[i]<inf&&ret.m2[i]<inf)
			ans=min(ans,ret.m1[i]+ret.m2[i]);
			print(ans==inf*2?-1:ans);
		}
	}
	
	return 0;
}