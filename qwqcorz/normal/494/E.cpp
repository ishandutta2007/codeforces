#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e4+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int getS(int l,int r)
{
	r--;
	if (l>r) return 0;
	int ret=0;
	for (int i=0,c=1;i<30;i++,c*=2) ret|=((r/c-(l+c-1)/c+1)&1)<<i;
	return ret;
}
int b[N*2],st[N*2];
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	int sum[N*8],tot[N*8];
	void push_up(int w,int l,int r)
	{
		if (tot[w]) sum[w]=st[r]^st[l-1];
		else sum[w]=l==r?0:sum[ls]^sum[rs];
	}
	void update(int w,int l,int r,int x)
	{
		tot[w]+=x;
		push_up(w,l,r);
	}
	void add(int w,int l,int r,int ql,int qr,int x)
	{
		if (ql<=l&&r<=qr) return update(w,l,r,x);
		if (ql<=mid) add(ls,l,mid,ql,qr,x);
		if (qr>mid) add(rs,mid+1,r,ql,qr,x);
		push_up(w,l,r);
	}
	#undef mid
	#undef rs
	#undef ls
}t;
struct matrix
{
	int x1,y1,x2,y2;
}a[N];
struct segment
{
	int x,l,r,y;
	bool operator <(const segment &a)const
	{
		return x==a.x?y>a.y:x<a.x;
	}
}s[N*2];

signed main()
{
	int m=read(),n=read(),k=read(),cnt=0; m=0;
	for (int i=1;i<=n;i++) a[i].x1=read(),a[i].y1=read(),a[i].x2=read(),a[i].y2=read();
	for (int i=1;i<=n;i++)
	{
		int x1=a[i].x1,y1=a[i].y1,x2=a[i].x2+1,y2=a[i].y2+1;
		s[++m]=(segment){x1,y1,y2,1};
		s[++m]=(segment){x2,y1,y2,-1};
		b[++cnt]=y1,b[++cnt]=y2;
	}
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<cnt;i++) st[i]=st[i-1]^getS(b[i],b[i+1]);
	sort(s+1,s+1+m);
	s[m+1].x=s[m].x;
	int ans=0;
	for (int i=1;i<=m;i++)
	{
		s[i].l=lower_bound(b+1,b+1+cnt,s[i].l)-b;
		s[i].r=lower_bound(b+1,b+1+cnt,s[i].r)-b;
		if (s[i].l<s[i].r) t.add(1,1,cnt-1,s[i].l,s[i].r-1,s[i].y);
		ans^=getS(s[i].x,s[i+1].x)&t.sum[1];
	}
	int res=0;
	for (int c=1;c<=k;c*=2) res^=ans&c;
	puts(res?"Hamed":"Malek");
	
	return 0;
}