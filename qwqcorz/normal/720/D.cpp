#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int K=1e5+5;
const int p=1e9+7;

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
struct bit
{
	int n,t[N];
	int query(int x){int ret=0;for (;x;x-=x&-x) ret+=t[x];return ret;}
	void add(int x,int y){for (;x<=n;x+=x&-x) t[x]+=y;}
	void add(int l,int r,int x){add(l,x),add(r+1,-x);}
}c;
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*4],tag[N*4];
	void update(int w,int l,int r,int x)
	{
		t[w]=(r-l+1LL)*x%p;
		tag[w]=x;
	}
	void push_down(int w,int l,int r)
	{
		if (!~tag[w]) return;
		update(ls,l,mid,tag[w]);
		update(rs,mid+1,r,tag[w]);
		tag[w]=-1;
	}
	void cover(int w,int l,int r,int ql,int qr,int x)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) return update(w,l,r,x);
		push_down(w,l,r);
		cover(ls,l,mid,ql,qr,x);
		cover(rs,mid+1,r,ql,qr,x);
		t[w]=(t[ls]+t[rs])%p;
	}
	int query(int w,int l,int r,int ql,int qr)
	{
		if (qr<l||r<ql) return 0;
		if (ql<=l&&r<=qr) return t[w];
		push_down(w,l,r);
		return (query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr))%p;
	}
	void clear()
	{
		memset(t,0,sizeof(t));
		memset(tag,-1,sizeof(tag));
	}
	#undef mid
	#undef rs
	#undef ls
}t;
struct rectangle
{
	int x1,y1,x2,y2,low;
}a[K];
void getlow(int n,int m,int k)
{
	sort(a+1,a+1+k,[&](const rectangle &a,const rectangle &b){
		return a.y2==b.y2?a.x1<b.x1:a.y2<b.y2;
	});
	t.clear();
	for (int i=1;i<=k;i++)
	{
		if (a[i].x1==1) a[i].low=a[i].y2+1;
		else if (t.query(1,1,n,a[i].x1,a[i].x1)==a[i].y2) a[i].low=a[i].y2+1;
		else a[i].low=t.query(1,1,n,a[i].x1-1,a[i].x1-1);
		t.cover(1,1,n,a[i].x1,a[i].x2,a[i].y2);
	}
}
vector<int>L[N],R[N];
int getdp(int n,int m,int k)
{
	c.n=m;
	t.clear();
	t.cover(1,1,m,1,1,1);
	for (int i=k;i>=1;i--)
		L[a[i].x1].push_back(i),
		R[a[i].x2+1].push_back(i);
	for (int i=1;i<=n;i++)
	{
		for (int j:L[i])
		{
			int l=a[j].y1,r=a[j].y2,low=a[j].low;
			if (!c.query(r+1))
			t.cover(1,1,m,r+1,r+1,t.query(1,1,m,low+1,r+1));
			c.add(l,r,1);
			t.cover(1,1,m,l,r,0);
		}
		for (int j:R[i]) c.add(a[j].y1,a[j].y2,-1);
//		for (int j=1;j<=m;j++) print(t.query(1,1,m,j,j)," \n"[j==m]);
	}
	return t.t[1];
}

signed main(signed bangumi,char *ss969[])
{
	(void)bangumi,(void)ss969;
	int n=read(),m=read(),k=read();
	for (int i=1;i<=k;i++)
		a[i].x1=read(),
		a[i].y1=read(),
		a[i].x2=read(),
		a[i].y2=read();
	n++;
	a[++k]=(rectangle){n,1,n,m-1};
	getlow(n,m,k);
	print(getdp(n,m,k));
	
	return 0;
}