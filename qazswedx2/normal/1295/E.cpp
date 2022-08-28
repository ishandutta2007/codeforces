#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[1000005],b[1000005],c[1000005];
ll sum[1000005],lazy[1000005],d[1000005];
void pushup(int x)
{
	sum[x]=min(sum[x*2],sum[x*2+1]);
}
void col(int x,int l,int r,ll v)
{
	sum[x]+=v;
	lazy[x]+=v;
}
void pushdown(int x,int l,int r)
{
	if(lazy[x])
	{
		int mid=(l+r)/2;
		col(x*2,l,mid,lazy[x]);
		col(x*2+1,mid+1,r,lazy[x]);
		lazy[x]=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=d[l];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int ql,int qr,ll v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,l,r,v);
		return;
	}
	pushdown(x,l,r);
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
ll query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return 1e18;
	if(ql<=l&&r<=qr) return sum[x];
	pushdown(x,l,r);
	int mid=(l+r)/2;
	ll q1,q2;
	q1=query(x*2,l,mid,ql,qr);
	q2=query(x*2+1,mid+1,r,ql,qr);
	return min(q1,q2);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),c[a[i]]=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]),d[i]=b[i]+d[i-1];
	build(1,1,n);
	ll tans=query(1,1,n,1,n-1);
	for(int i=1;i<=n;i++)
	{
		int val=b[c[i]];
		modify(1,1,n,c[i],n,-val);
		modify(1,1,n,1,c[i]-1,val);
		tans=min(tans,query(1,1,n,1,n-1));
	}
	printf("%I64d\n",tans);
	return 0;
}