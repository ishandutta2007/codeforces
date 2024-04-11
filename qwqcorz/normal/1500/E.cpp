#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=4e5+5;

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
struct Operator
{
	int opt,x;
}q[N];
#define num t[1].tot
int a[N],b[N],cnt=0,n,m;
struct segment_tree
{
	#define ls (w*2)
	#define rs (w*2+1)
	#define mid ((l+r)/2)
	struct node {
		int tot,sum,lsum,rsum;
		friend node operator +(const node &a,const node &b)
		{
			node ret;
			ret.tot=a.tot+b.tot;
			ret.sum=a.sum+b.sum;
			ret.lsum=a.lsum+b.lsum+a.sum*b.tot;
			ret.rsum=a.rsum+b.rsum+b.sum*a.tot;
			return ret;
		}
	}t[N*4];
	void add(int w,int l,int r,int type,int x)
	{
		if (l==r)
		{
			t[w].tot+=type;
			t[w].lsum=t[w].rsum=t[w].sum+=type*b[x];
			return;
		}
		if (x<=mid) add(ls,l,mid,type,x);
			   else add(rs,mid+1,r,type,x);
		t[w]=t[ls]+t[rs];
	}
	int QueryL(int w,int l,int r,int x)
	{
		if (l==r) return l;
		if (t[ls].tot>=x) return QueryL(ls,l,mid,x);
					 else return QueryL(rs,mid+1,r,x-t[ls].tot);
	}
	node Query(int w,int l,int r,int L,int R)
	{
		if (L<=l&&r<=R) return t[w];
		if (L<=mid&&R>mid) return Query(ls,l,mid,L,R)+Query(rs,mid+1,r,L,R);
		if (L<=mid) return Query(ls,l,mid,L,R);
		if (R>mid) return Query(rs,mid+1,r,L,R);
		return t[0];
	}
	int QuerySum(int w,int l,int r,int L,int R)
	{
		if (L<=l&&r<=R) return t[w].sum;
		if (L<=mid&&R>mid) return QuerySum(ls,l,mid,L,R)+QuerySum(rs,mid+1,r,L,R);
		if (L<=mid) return QuerySum(ls,l,mid,L,R);
		if (R>mid) return QuerySum(rs,mid+1,r,L,R);
		return 0;
	}
	void add(int type,int x) {//insert&delete
		add(1,1,cnt,type,x);
	}
	int QueryL(int x) {//x 
		return QueryL(1,1,cnt,x);
	}
	int QueryR(int x) {//x 
		return QueryL(1,1,cnt,num-x+1);
	}
	int QueryLkth(int x) {//x 
		if (x<=0) return 0;
		return QuerySum(1,1,cnt,1,QueryL(x));
	}
	int QueryRkth(int x) {//x 
		if (x<=0) return 0;
		return QuerySum(1,1,cnt,QueryR(x),cnt);
	}
	int QueryLpre(int x) {//xLi 
		if (x<=0) return 0;
		return Query(1,1,cnt,1,QueryL(x)).lsum;
	}
	int QueryRpre(int x) {//xRi 
		if (x<=0) return 0;
		return Query(1,1,cnt,QueryR(x),cnt).rsum;
	}
	int QueryLsuf(int x) {//xLi 
		x=num-x+1;
		if (x<=0) return 0;
		return t[1].lsum-QueryLpre(num-x);
	}
	int QueryRsuf(int x) {//xRi 
		x=num-x+1;
		if (x<=0) return 0;
		return t[1].rsum-QueryRpre(num-x);
	}
	#undef mid
	#undef ls
	#undef rs
}t;
#undef num
#define num t.t[1].tot
int calc(int x)
{
	return t.QueryLkth(x+1)-t.QueryRkth(x);
}
int solve()
{
	if (num<=1) return 0;
	if (num==2) return t.QueryRkth(1)-t.QueryLkth(1);
	int x=(num-1)/2;
	int l=1,r=x;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (calc(mid)<=0) r=mid-1;
					 else l=mid+1;
	}
	int ql=l;
	l=x,r=num-1;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (calc(mid)<=0) l=mid+1;
					 else r=mid-1;
	}
	int qr=r;
	if (ql<=x&&calc(ql)<=0)
	{
		if (qr>=x&&calc(qr)<=0)
		{
			return t.QueryRpre(ql-1)-t.QueryLpre(ql-1)+
				   t.QueryRsuf(qr+2)-t.QueryLsuf(qr+2)+
				   t.QueryRkth(qr+1)-t.QueryLkth(ql);
		}
		else return t.QueryRpre(ql-1)-t.QueryLpre(ql-1)+
					t.QueryRkth(num)-t.QueryLkth(ql);
	}
	else
		if (qr>=x&&calc(qr)<=0)
		{
			return t.QueryRsuf(qr+2)-t.QueryLsuf(qr+2)+
				   t.QueryRkth(qr+1)-t.QueryLkth(1);
		}
		else return t.t[1].rsum-t.t[1].lsum;
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++) b[++cnt]=a[i]=read();
	for (int i=1;i<=m;i++) q[i].opt=read(),b[++cnt]=q[i].x=read();
	b[++cnt]=0;
	b[++cnt]=1e14;
	sort(b+1,b+1+cnt);
	cnt=unique(b+1,b+1+cnt)-b-1;
	for (int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+cnt,a[i])-b;
	for (int i=1;i<=m;i++) q[i].x=lower_bound(b+1,b+1+cnt,q[i].x)-b;
	for (int i=1;i<=n;i++) t.add(1,a[i]);
	print(solve());
	for (int i=1;i<=m;i++)
	{
		if (q[i].opt==1) t.add(1,q[i].x);
					else t.add(-1,q[i].x);
		print(solve());
	}
	
	return 0;
}