#include<bits/stdc++.h>
#define int long long
#define piir pair<int,int>
#define piiir pair<int,piir>
#define mk make_pair
#define fi first
#define se second
using namespace std;
const int N=5e5+5;
const int inf=1LL<<60;

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
vector<piir>a[N*2];
int b[N*2],l[N],r[N],c[N];
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
int tag[N*8];
piir t[N*8];
void update(int w,int x)
{
	tag[w]+=x;
	t[w].fi+=x;
}
void push_down(int w)
{
	if (!tag[w]) return;
	update(ls,tag[w]);
	update(rs,tag[w]);
	tag[w]=0;
}
void build(int w,int l,int r)
{
	if (l==r) return void(t[w]=mk(b[l],l));
	build(ls,l,mid);
	build(rs,mid+1,r);
	t[w]=max(t[ls],t[rs]);
}
void add(int w,int l,int r,int ql,int qr,int x)
{
	if (qr<l||r<ql) return;
	if (ql<=l&&r<=qr) return update(w,x);
	push_down(w);
	add(ls,l,mid,ql,qr,x);
	add(rs,mid+1,r,ql,qr,x);
	t[w]=max(t[ls],t[rs]);
}
piir query(int w,int l,int r,int ql,int qr)
{
	if (qr<l||r<ql) return mk(-inf,0);
	if (ql<=l&&r<=qr) return t[w];
	push_down(w);
	return max(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
}
#undef mid
#undef rs
#undef ls

signed main(signed Goodbye,char *Wangang[])
{
	(void)Goodbye,(void)Wangang;
	b[0]=2e9;
	int n=read(),cnt=0;
	for (int i=1;i<=n;i++)
	{
		b[++cnt]=l[i]=read();
		b[++cnt]=r[i]=read();
		c[i]=read();
		if (l[i]>r[i]) swap(l[i],r[i]);
	}
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n;i++)
	{
		l[i]=lower_bound(b+1,b+1+cnt,l[i])-b;
		r[i]=lower_bound(b+1,b+1+cnt,r[i])-b;
		a[r[i]].push_back(mk(l[i],c[i]));
	}
	build(1,1,cnt);
	piiir ans(0,mk(0,0));
	for (int i=1;i<=cnt;i++)
	{
		for (piir j:a[i]) add(1,1,cnt,1,j.fi,j.se);
		piir tmp=query(1,1,cnt,1,i);
		ans=max(ans,mk(tmp.fi-b[i],mk(tmp.se,i)));
	}
	print(ans.fi);
	print(b[ans.se.fi],' '),print(b[ans.se.fi],' ');
	print(b[ans.se.se],' '),print(b[ans.se.se]);
	
	return 0;
}