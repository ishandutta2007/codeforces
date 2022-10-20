#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

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
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*4];
	void change(int w,int l,int r,int x,int y)
	{
		if (l==r) return void(t[w]=y);
		if (x<=mid) change(ls,l,mid,x,y);
			   else change(rs,mid+1,r,x,y);
		t[w]=min(t[ls],t[rs]);
	}
	int query(int w,int l,int r,int x)
	{
		if (r<=x) return t[w];
		if (l>x) return N;
		return min(query(ls,l,mid,x),query(rs,mid+1,r,x));
	}
	#undef ls
	#undef rs
	#undef mid
}t;
int a[N];
bool vis[N],b[N];

signed main(signed Recall,char *_902_[])
{
	(void)Recall,(void)_902_;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++)
	{
		if (a[i]>1&&t.query(1,1,n,a[i]-1)!=t.query(1,1,n,a[i])) vis[a[i]]=1;
		if (a[i]>1) vis[1]=1;
		t.change(1,1,n,a[i],i);
	}
	for (int i=n,mex=1;i>=1;i--)
	{
		b[a[i]]=1;
		while (b[mex]) mex++;
		vis[mex]=1;
	}
	int mex=1;
	while (vis[mex]) mex++;
	print(mex);
	
	return 0;
}