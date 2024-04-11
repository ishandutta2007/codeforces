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
int a[N],n,q;
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
struct node
{
	int sum,len,tag;
	node(){tag=-1;}
	void update(int x)
	{
		tag=x;
		sum=len*x;
	}
}t[N*4];
node operator +(const node &a,const node &b)
{
	node ret;
	ret.sum=a.sum+b.sum;
	ret.len=a.len+b.len;
	return ret;
}
void push_down(int w)
{
	if (!~t[w].tag) return;
	t[ls].update(t[w].tag);
	t[rs].update(t[w].tag);
	t[w].tag=-1;
}
void cover(int w,int l,int r,int ql,int qr,int x)
{
	if (r<ql||qr<l) return;
	if (ql<=l&&r<=qr) return t[w].update(x);
	if (l<r) push_down(w);
	cover(ls,l,mid,ql,qr,x);
	cover(rs,mid+1,r,ql,qr,x);
	t[w]=t[ls]+t[rs];
}
int query(int w,int l,int r,int ql,int qr)
{
//	print(w,' '),print(l,' '),print(r,':'),print(t[w].sum);
	if (r<ql||qr<l) return 0;
	if (ql<=l&&r<=qr) return t[w].sum;
	if (l<r) push_down(w);
	return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr); 
}
void build(int w,int l,int r)
{
	if (l==r)
	{
		t[w].len=1;
		t[w].sum=0;
		return; 
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=t[ls]+t[rs]; 
}
#undef mid
#undef rs
#undef ls
set<int>d;
void insert(int x)
{
	if (d.find(x)!=d.end()) return;
	auto r=d.lower_bound(x);
	cover(1,1,n,(*--r)+1,x,n-x);
	d.insert(x);
}
void erase(int x)
{
	if (d.find(x)==d.end()) return;
	auto p=d.find(x),l=p,r=p; l--,r++;
	cover(1,1,n,(*l)+1,x,n-(*r));
	d.erase(p);
}
inline int calc(int l,int r){return (l+r)*(r-l+1)/2;}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	n=read(),q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	d.insert(0),d.insert(n);
	for (int i=1;i<n;i++) if (a[i]>a[i+1]) insert(i);
	while (q--)
	{
		int opt=read(),x=read(),y=read();
		if (opt==1)
		{
			a[x]=y;
			if (x>1)
			{
				if (a[x-1]<=a[x]) erase(x-1);
							 else insert(x-1);
			}
			if (x<n)
			{
				if (a[x]<=a[x+1]) erase(x);
							 else insert(x);
			}
		}
		else
		{
			if (y==n)
			{
				print(calc(n-y+1,n-x+1)-query(1,1,n,x,y));
				continue;
			}
			auto p=d.upper_bound(y);
			int tmp=max(*--p,x-1);
			print(calc(n-y+1,n-x+1)-query(1,1,n,x,tmp)-(y-tmp)*(n-y));
		}
//		print(query(1,1,n,x,y));
	}
	
	return 0;
}