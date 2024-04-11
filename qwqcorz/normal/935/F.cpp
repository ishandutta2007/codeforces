#include<bits/stdc++.h>
#define mid ((l+r)/2)
#define ls (w*2)
#define rs (w*2+1)
#define int long long
using namespace std;
const int N=1e5+5;
const int inf=1ll<<60;

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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int a[N];
struct node
{
	bool flag;
	int Min,l,r,x,y,val;
	node(int v=0)
	{
		flag=0;
		l=r=val=v;
		Min=inf;
		x=1;
		y=-1;
	}
//	void operator +=(const int &y)
//	{
//		l+=y;
//		r+=y;
//	}
}t[N*4];
node operator +(const node &a,const node &b)
{
	node ret;
	ret.flag=a.flag||b.flag||(a.r>=0&&b.l<=0);
	ret.l=a.l;
	ret.r=b.r;
	ret.Min=min(a.Min,b.Min);
	ret.x=a.x<0?a.x:b.x;
	ret.y=a.y>0?a.y:b.y;
	if (a.r>=0&&b.l>0) ret.Min=min(ret.Min,b.l);
	if (a.r<0&&b.l<=0) ret.Min=min(ret.Min,-a.r);
	if (a.r<0&&b.l>0)
	{
		ret.x=a.r;
		ret.y=b.l;
	}
	return ret;
}
void build(int w,int l,int r)
{
	if (l==r) return void(t[w]=node(a[l]));
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=t[ls]+t[rs];
}
void change(int w,int l,int r,int x,int y)
{
//	if (l==r) return t[w]+=y;
	if (r<x||x<l) return;
//	print(w,' ');
//	print(x,' ');
//	print(l,',');
//	print(r,':');
//	print(t[w].val+y);
	if (l==r) return void(t[w]=node(t[w].val+y));
	change(ls,l,mid,x,y);
	change(rs,mid+1,r,x,y);
	t[w]=t[ls]+t[rs];
}
node query(int w,int l,int r,int L,int R)
{
//	print(w,' ');
//	print(l,',');
//	print(r,':');
//	print(t[w].val);
	if (L<=l&&r<=R) return t[w];
	if (R<=mid) return query(ls,l,mid,L,R);
	if (L>mid) return query(rs,mid+1,r,L,R);
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}

signed main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<n;i++) ans+=labs(a[i]=a[i+1]-a[i]);
	build(1,1,n-1);
	int Q=read();
	while (Q--)
	{
		int opt=read(),l=read(),r=read(),x=read();
		if (opt==1)
		{
			int now=-inf;
			node tmp=query(1,1,n-1,l-1,r);
//			print(tmp.l,' ');
//			print(tmp.r,':');
//			print(tmp.flag);
			if (tmp.flag) now=x*2;
			else
			{
				if (tmp.Min<inf) now=max(now,max(x-tmp.Min,0ll)*2ll);
				if (tmp.x<0&&tmp.y>0) now=max(now,(max(x-(-tmp.x),0ll)-min(tmp.y,x))*2ll);
			}
//			print(ans);
			print(ans+now);
		}
		else
		{
			ans-=llabs(a[l-1]);
			ans+=llabs(a[l-1]+=x);
			ans-=llabs(a[r]);
			ans+=llabs(a[r]-=x);
			change(1,1,n-1,l-1,x);
			change(1,1,n-1,r,-x);
		}
//		puts("");
//		for (int i=1;i<n;i++) print(a[i],' ');puts("");
//		for (int i=1;i<n;i++) print(query(1,1,n-1,i,i).l,' ');puts("");
//		puts("");
	}

	return 0;
}