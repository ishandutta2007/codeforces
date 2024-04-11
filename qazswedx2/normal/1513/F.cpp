#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
struct pt
{
	int l,r,fl;
	bool operator<(const pt x) const
	{
		return r==x.r?fl<x.fl:r<x.r;
	}
}a[1000005];
int n,b[1000005],bt,lazy[5000005],lazy2[5000005];
int ans=0;
void col(int x,int v)
{
	lazy[x]=max(lazy[x],v);
}
void col2(int x,int v)
{
	lazy2[x]=max(lazy2[x],v);
}
void pushdown(int x)
{
	if(lazy[x])
	{
		col(x*2,lazy[x]);
		col(x*2+1,lazy[x]);
		lazy[x]=0;
	}
	if(lazy2[x])
	{
		col2(x*2,lazy2[x]);
		col2(x*2+1,lazy2[x]);
		lazy2[x]=0;
	}
}
void build(int x,int l,int r)
{
	lazy[x]=lazy2[x]=0;
	if(l==r) return;
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
}
void modify(int x,int l,int r,int ql,int qr,int v,int fl)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		if(fl==0) col(x,v);
		else col2(x,v);
		return;
	}
	pushdown(x);
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr,v,fl);
	modify(x*2+1,mid+1,r,ql,qr,v,fl);
}
int query(int x,int l,int r,int qx)
{
	if(l==r) return max(lazy[x],lazy2[x]-b[l]);
	pushdown(x);
	int mid=(l+r)/2;
	if(qx<=mid) return query(x*2,l,mid,qx);
	return query(x*2+1,mid+1,r,qx);
}
void solve(int fl)
{
	build(1,1,bt);
	for(int i=1;i<=n;i++)
	{
		int l=a[i].l,r=a[i].r;
		if(a[i].fl==fl)
		{
			modify(1,1,bt,1,l-1,b[r]-b[l],0);
			modify(1,1,bt,l,r,b[r],1);
		}
		else ans=max(ans,query(1,1,bt,l));
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].l);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].r);
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		b[++bt]=a[i].l;
		b[++bt]=a[i].r;
		if(a[i].l>a[i].r) swap(a[i].l,a[i].r),a[i].fl=1;
		sum+=a[i].r-a[i].l;
	}
	sort(b+1,b+bt+1);
	bt=unique(b+1,b+bt+1)-b-1;
	for(int i=1;i<=n;i++)
	{
		a[i].l=lower_bound(b+1,b+bt+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+bt+1,a[i].r)-b;
	}
	sort(a+1,a+n+1);
	solve(0);
	solve(1);
	printf("%lld\n",sum-2*ans);
	return 0;
}