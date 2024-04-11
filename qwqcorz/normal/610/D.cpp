#include<bits/stdc++.h>
#define ll long long
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
void write(ll x)
{
	if (x<0) putchar('-'),x=-x;
	if (x<10) putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
void print(ll x=-1,char c='\n')
{
	write(x);
	putchar(c);
}
ll ans=0;
struct segment
{
	int x,l,r,Add;
	bool operator <(const segment &a)const
	{
		return x<a.x;
	}
}a[N];
int b[N];
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
int t[N*4],sum[N*4];
void push_up(int w,int l,int r)
{
	if (t[w]) return void(sum[w]=b[r+1]-b[l]);
	if (l==r) sum[w]=0;
		 else sum[w]=sum[ls]+sum[rs];
}
void add(int w,int l,int r,int ql,int qr,int x)
{
	if (qr<l||r<ql) return;
	if (ql<=l&&r<=qr) return t[w]+=x,push_up(w,l,r),void();
	add(ls,l,mid,ql,qr,x);
	add(rs,mid+1,r,ql,qr,x);
	push_up(w,l,r);
}
//void output(int w,int l,int r)
//{
//	print(l,' ');
//	print(r,':');
//	print(t[w],' ');
//	print(sum[w]);
//	if (l==r) return;
//	output(ls,l,mid);
//	output(rs,mid+1,r);
//}
#undef ls
#undef rs
#undef mid

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	int n=read(),cnt=0;
	for (int i=1;i<=n;i++)
	{
		int x1=read(),y1=read(),x2=read(),y2=read();
		if (x1>x2) swap(x1,x2);
		if (y1>y2) swap(y1,y2);
		a[i*2-1]=(segment){x1,y1,y2+1,1};
		a[i*2]=(segment){x2+1,y1,y2+1,-1};
		b[++cnt]=y1;
		b[++cnt]=y2+1;
	}
	sort(a+1,a+1+cnt);
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n*2;i++)
		a[i].l=lower_bound(b+1,b+1+cnt,a[i].l)-b,
		a[i].r=lower_bound(b+1,b+1+cnt,a[i].r)-b;
//	for (int i=1;i<=cnt;i++) print(b[i],'.');puts("");
	for (int i=1;i<n*2;i++)
	{
		add(1,1,cnt,a[i].l,a[i].r-1,a[i].Add);
		ans+=1LL*sum[1]*(a[i+1].x-a[i].x);
//		printf("%d,%d:%d:%d\n",a[i].l,a[i].r-1,a[i].Add,sum[1]);
//		output(1,1,cnt);
//		puts("");
	}
	print(ans);
	
	return 0;
}