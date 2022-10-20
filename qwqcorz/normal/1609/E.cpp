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
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct sgt
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int t[N*4],tag[N*4];
	void update(int w,int x){t[w]+=x,tag[w]+=x;}
	void push_up(int w){t[w]=min(t[ls],t[rs]);}
	void push_down(int w)
	{
		if (!tag[w]) return;
		update(ls,tag[w]);
		update(rs,tag[w]);
		tag[w]=0;
	}
	void add(int w,int l,int r,int ql,int qr,int x)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) return update(w,x);
		push_down(w);
		add(ls,l,mid,ql,qr,x);
		add(rs,mid+1,r,ql,qr,x);
		push_up(w);
	}
	#undef mid
	#undef rs
	#undef ls
}mn;
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int a[N*4],b[N*4],t[N*4],tag[2][N*4];
	segment_tree(){memset(t,0x3f,sizeof(t));}
	void update(int w,int x,int y)
	{
		t[w]+=y;
		tag[x][w]+=y;
		(x==0?a[w]:b[w])+=y;
	}
	void push_up(int w)
	{
		t[w]=min({t[ls],t[rs],a[ls]+b[rs]});
		a[w]=min(a[ls],a[rs]);
		b[w]=min(b[ls],b[rs]);
	}
	void push_down(int x,int w)
	{
		if (!tag[x][w]) return;
		update(ls,x,tag[x][w]);
		update(rs,x,tag[x][w]);
		tag[x][w]=0;
	}
	void push_down(int w){push_down(0,w),push_down(1,w);}
	void add(int o,int w,int l,int r,int ql,int qr,int x)
	{
		if (qr<l||r<ql) return;
		if (ql<=l&&r<=qr) return update(w,o,x);
		push_down(w);
		add(o,ls,l,mid,ql,qr,x);
		add(o,rs,mid+1,r,ql,qr,x);
		push_up(w);
	}
	void build(int w,int l,int r)
	{
		if (l==r) return;
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=0;
	}
	#undef mid
	#undef rs
	#undef ls
}t;
int tot[3],n,q;
char a[N];
void add(int x,char y,int v)
{
	tot[y-'a']+=v;
	if (y=='a')
		t.add(0,1,1,n,x+1,n,v);
	if (y=='b')
		t.add(0,1,1,n,x,n,-v),
		t.add(1,1,1,n,x+1,n,v);
	if (y=='c')
		t.add(1,1,1,n,1,x-1,v);
	t.add(0,1,1,n,x,x,y!='a'?v:0),
	t.add(1,1,1,n,x,x,y!='c'?v:0);
	if (y=='c') mn.add(1,0,n,0,x-1,v);
	if (y=='a') mn.add(1,0,n,x,n,v);
}
void GreenDay()
{
	n=read(),q=read();
	scanf("%s",a+1);
	t.build(1,1,n);
	for (int i=1;i<=n;i++) add(i,a[i],1);
	while (q--)
	{
		int x=read();
		add(x,a[x],-1);
		cin>>a[x];
		add(x,a[x],1);
		print(min({mn.t[1],t.t[1],tot[0],tot[1],tot[2]}));
	}
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}