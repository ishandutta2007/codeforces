#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int p=998244353;

int get()
{
	char c=getchar();
	while (c<'0'||'1'<c) c=getchar();
	return c=='1';
}
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
int a[N],pw[N];
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
struct node
{
	int l,r,tot,h;
}t[N*4];
node operator +(const node &a,const node &b)
{
	if (!a.tot&&!b.tot) return (node){a.l+b.l,a.r+b.r,0,0};
	node ret;
	if (!a.tot){ret=b;ret.l+=a.r;return ret;}
	if (!b.tot){ret=a;ret.r+=b.l;return ret;}
	ret.l=a.l,ret.r=b.r,ret.tot=a.tot+b.tot;
	ret.h=(1LL*(a.h+((a.r+b.l)&1))*pw[b.tot]+b.h)%p;
	return ret;
}
void build(int w,int l,int r)
{
	if (l==r) return void(t[w]=(node){a[l],a[l],!a[l],0});
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=t[ls]+t[rs];
}
node query(int w,int l,int r,int ql,int qr)
{
	if (ql<=l&&r<=qr) return t[w];
	if (qr<=mid) return query(ls,l,mid,ql,qr);
	if (ql>mid) return query(rs,mid+1,r,ql,qr);
	return query(ls,l,mid,ql,qr)+query(rs,mid+1,r,ql,qr);
}
pair<int,int>get(node x)
{
	if (!x.tot) return make_pair(0,x.tot);
	int h=(x.h+(x.r&1)+(x.l&1)*pw[x.tot])%p;
	return make_pair(h,x.tot);
}
#undef mid
#undef rs
#undef ls

signed main(signed bangumi,char *ss1672[])
{
	(void)bangumi,(void)ss1672;
	int n=read();
	for (int i=1;i<=n;i++) a[i]=get();
	for (int i=pw[0]=1;i<=n;i++) pw[i]=pw[i-1]*2%p;
	build(1,1,n);
	int m=read();
	for (int i=1;i<=m;i++)
	{
		int l=read(),r=read(),len=read();
		pair<int,int>x=get(query(1,1,n,l,l+len-1));
		pair<int,int>y=get(query(1,1,n,r,r+len-1));
		puts(x==y?"YES":"NO");
	}
	
	return 0;
}