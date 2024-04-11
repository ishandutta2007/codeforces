#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

struct bit
{
	int t[N],n;
	void modify(int x,int y){for (;x<=n;x+=x&-x) t[x]^=y;}
	int query(int x){int ret=0;for (;x;x&=x-1) ret^=t[x];return ret;}
}b;
struct node
{
	int f[30],size;
	void insert(int x)
	{
		if (!x) return;
		for (int i=29;i>=0;i--)
		if (x>>i&1)
		{
			if (f[i]) x^=f[i];
				 else return f[i]=x,size++,void();
			if (!x) return;
		}
	}
	friend node operator +(const node &a,const node &b)
	{
		node ret=a;
		for (int i=0;i<30;i++) if (b.f[i]) ret.insert(b.f[i]);
		return ret;
	}
}t[N*4];
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
void modify(int w,int l,int r,int x,int y)
{
	if (l==r) return (t[w]=node()).insert(y);
	if (x<=mid) modify(ls,l,mid,x,y);
		   else modify(rs,mid+1,r,x,y);
	t[w]=t[ls]+t[rs];
}
node query(int w,int l,int r,int ql,int qr)
{
	if (qr<l||r<ql) return node();
	if (ql<=l&&r<=qr) return t[w];
	return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
}
#undef mid
#undef rs
#undef ls
int a[N];

void GreenDay()
{
	int n=read(),m=read(); b.n=n+1;
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=n;i>=1;i--) a[i]=a[i-1]^a[i];
	for (int i=1;i<=n;i++) b.modify(i,a[i]);
	for (int i=1;i<=n;i++) modify(1,1,n+1,i,a[i]);
	for (int i=1;i<=m;i++)
	{
		int opt=read(),l=read(),r=read();
		if (opt==1)
		{
			int x=read();
			b.modify(l,x),b.modify(r+1,x);
			a[l]^=x,a[r+1]^=x;
			modify(1,1,n+1,l,a[l]);
			modify(1,1,n+1,r+1,a[r+1]);
		}
		else
		{
			node res=query(1,1,n+1,l+1,r);
			res.insert(b.query(l));
			print(1<<res.size);
		}
	}
}

signed main()
{
	int T=1;
//	int T=read();
	while (T--) GreenDay();
	
	return 0;
}