#include<bits/stdc++.h>
#define int long long
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
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
struct node
{
	int sum,Max,Min;
}t[N*4];
node operator +(const node &a,const node &b)
{
	node ret;
	ret.sum=a.sum+b.sum;
	ret.Max=max(a.Max,b.Max);
	ret.Min=min(a.Min,b.Min);
	return ret;
}
int tag[N*4],a[N];
void build(int w,int l,int r)
{
	tag[w]=0;
	if (l==r) return void(t[w].Max=t[w].Min=t[w].sum=a[l]);
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=t[ls]+t[rs];
}
void cover(int w,int x,int l,int r)
{
	tag[w]=x;
	t[w].sum=x*(r-l+1);
	t[w].Max=t[w].Min=x;
}
void pushdown(int w,int l,int r)
{
	if (!tag[w]) return;
	cover(ls,tag[w],l,mid);
	cover(rs,tag[w],mid+1,r);
	tag[w]=0;
}
void cover(int w,int l,int r,int x,int y)
{
	if (l>x) return;
	if (r<=x&&t[w].Max<=y) return cover(w,y,l,r);
	if (t[w].Min>=y) return;
	pushdown(w,l,r);
	cover(ls,l,mid,x,y);
	cover(rs,mid+1,r,x,y);
	t[w]=t[ls]+t[rs];
}
int query(int w,int l,int r,int x)
{
	if (x<l) return 0;
	if (r<=x) return t[w].sum;
	pushdown(w,l,r);
	return query(ls,l,mid,x)+query(rs,mid+1,r,x);
}
int find1(int w,int l,int r,int y)
{
	if (t[w].sum<=y) return r;
	if (t[w].Max>y) return l-1;
	if (l==r) return l;
	pushdown(w,l,r);
	if (t[ls].sum<=y) return find1(rs,mid+1,r,y-t[ls].sum);
	return find1(ls,l,mid,y);
}
int find2(int w,int l,int r,int y)
{
	if (t[w].Min>y) return r+1;
	if (l==r) return l;
	pushdown(w,l,r);
	if (t[ls].Min<=y) return find2(ls,l,mid,y);
	return find2(rs,mid+1,r,y);
}

signed main()
{
	int n=read(),m=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		int opt=read(),x=read(),y=read();
		if (opt==1) cover(1,1,n,x,y);
		if (opt==2)
		{
			x=max(find2(1,1,n,y),x);
			int ans=0;
			while (x<=n)
			{
				int nxt=find1(1,1,n,y+query(1,1,n,x-1));//print(x,',');print(nxt); 
				if (nxt<x) break;
				ans+=nxt-x+1;
				y-=query(1,1,n,nxt)-query(1,1,n,x-1);//print(y);
				x=max(find2(1,1,n,y),nxt+1);
			}
			print(ans);
		}
	}

	return 0;
}