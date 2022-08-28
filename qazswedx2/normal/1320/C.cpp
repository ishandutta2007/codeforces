#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int val,val2,c;
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
}d[200005];
struct pt2
{
	int val,c;
	pt2(int val=0,int c=0):val(val),c(c){}
	bool operator<(const pt2 x) const
	{
		return val<x.val;
	}
}a[200005],b[200005];
int n,m,p,sum[5000005],lazy[5000005],val=1e6;
void pushup(int x)
{
	sum[x]=max(sum[x*2],sum[x*2+1]);
}
void col(int x,int v)
{
	sum[x]+=v;
	lazy[x]+=v;
}
void pushdown(int x)
{
	if(lazy[x])
	{
		col(x*2,lazy[x]);
		col(x*2+1,lazy[x]);
		lazy[x]=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=-b[l].c;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,v);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].val,&a[i].c);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&b[i].val,&b[i].c);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(int i=1;i<=p;i++)
		scanf("%d%d%d",&d[i].val,&d[i].val2,&d[i].c);
	sort(d+1,d+p+1);
	build(1,1,m);
	int nw=1,ans=-2e9;
	for(int i=1;i<=n;i++)
	{
		while(nw<=p&&d[nw].val<a[i].val)
		{
			int x=upper_bound(b+1,b+m+1,pt2(d[nw].val2))-b;
			modify(1,1,m,x,m,d[nw].c);
			//printf("nw=%d,c=%d,val=%d,x=%d\n",nw,d[nw].c,d[nw].val,x);
			nw++;
		}
	//	printf("i=%d,c=%d,sum=%d\n",i,a[i].c,sum[1]);
		ans=max(ans,sum[1]-a[i].c);
	}
	printf("%d",ans);
	return 0;
}