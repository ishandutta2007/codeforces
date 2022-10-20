#include<bits/stdc++.h>
#define int long long
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
int a[N];
#define ls (w*2)
#define rs (w*2+1)
#define mid ((l+r)/2)
struct node
{
	int sum[2],val[2],ans,mn;
}t[N*4];
node operator +(node a,node b)
{
	node ret;
	for (int i=0;i<=1;i++) ret.sum[i]=a.sum[i]+b.sum[i];
	for (int i=0;i<=1;i++) ret.val[i]=a.val[i]+b.val[i];
	int tmp=min(a.val[0],b.val[1]);
	ret.ans=a.ans+b.ans+tmp;
	ret.val[0]-=tmp;
	ret.val[1]-=tmp;
	ret.mn=min(a.mn,b.mn+a.sum[1]-a.sum[0]);
	return ret;
}
void build(int w,int l,int r)
{
	if (l==r)
	{
		t[w].mn=min(a[l],0LL);
		if (a[l]<0) t[w].sum[0]=t[w].val[0]=-a[l];
		if (a[l]>0) t[w].sum[1]=t[w].val[1]=a[l];
		return;
	}
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
#undef mid
#undef rs
#undef ls

void Multi_test_no_horses()
{
	int n=read(),Q=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=1;i<=n;i++) a[i]=read()-a[i];
	build(1,1,n);
	while (Q--)
	{
		int l=read(),r=read();
		node now=query(1,1,n,l,r);
		print(now.sum[0]==now.sum[1]&&now.mn>=0?now.sum[0]-now.ans:-1);
	}
}

signed main(signed Hello,char *CodeForces[])
{
	(void)Hello,(void)CodeForces;
	int T=1;
//	int T=read();
	while (T--) Multi_test_no_horses();
	
	return 0;
}