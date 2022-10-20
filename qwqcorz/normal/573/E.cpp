#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int N=1e5+5;
const int inf=1e18;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int a[N];
struct KTT
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct line
	{
		int k,b;
		bool operator <(const line &a)const
		{
			return b!=a.b?b<a.b:k<a.k;
		}
	};
	struct node
	{
		line v;
		int id,t,tagk,tagb;
		void add(int x,int y)
		{
			t-=x;
			v.b+=v.k*x+y;
			tagk+=x;
			tagb+=y;
		}
		friend node operator +(node a,node b)
		{
			line x=a.v,y=b.v;
			if (x<y) swap(a,b),swap(x,y);
			node ret=(node){x,a.id,min(a.t,b.t),0,0};
			if (x.k<y.k) ret.t=min(ret.t,(x.b-y.b+y.k-x.k-1)/(y.k-x.k));
			return ret;
		}
	}t[N*4];
	void push_down(int w)
	{
		if (!t[w].tagk&&!t[w].tagb) return;
		t[ls].add(t[w].tagk,t[w].tagb);
		t[rs].add(t[w].tagk,t[w].tagb);
		t[w].tagk=t[w].tagb=0;
	}
	void build(int w,int l,int r)
	{
		if (l==r) return t[w]=(node){(line){a[l],a[l]},l,inf,0,0},void();
		build(ls,l,mid);
		build(rs,mid+1,r);
		t[w]=t[ls]+t[rs];
	}
	void addk(int w,int l,int r,int ql,int qr,int x)
	{
		if (ql<=l&&r<=qr&&x<t[w].t) return t[w].add(x,0);
		push_down(w);
		if (ql<=mid) addk(ls,l,mid,ql,qr,x);
		if (qr>mid) addk(rs,mid+1,r,ql,qr,x);
		t[w]=t[ls]+t[rs];
	}
	void addb(int w,int l,int r,int ql,int qr,int x)
	{
		if (ql<=l&&r<=qr) return t[w].add(0,x);
		push_down(w);
		if (ql<=mid) addb(ls,l,mid,ql,qr,x);
		if (qr>mid) addb(rs,mid+1,r,ql,qr,x);
		t[w]=t[ls]+t[rs];
	}
	#undef mid
	#undef rs
	#undef ls
}t;

signed main()
{
	int n=read(),ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	t.build(1,1,n);
	for (int i=1;i<=n;i++)
	{
		auto mx=t.t[1];
		if (mx.v.b<0) break;
		ans+=mx.v.b;
		int x=mx.id;
		if (x<n) t.addk(1,1,n,x+1,n,1);
		if (x>1) t.addb(1,1,n,1,x-1,a[x]);
		t.addb(1,1,n,x,x,-inf);
	}
	print(ans);
	
	return 0;
}