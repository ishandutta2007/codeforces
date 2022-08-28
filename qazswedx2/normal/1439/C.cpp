#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll sum[1000005];
int n,m,lazy[1000005],mx[1000005],a[1000005];
void pushup(int x)
{
	sum[x]=sum[x*2]+sum[x*2+1];
	mx[x]=max(mx[x*2],mx[x*2+1]);
}
void col(int x,int l,int r,int v)
{
	sum[x]=1ll*(r-l+1)*v;
	mx[x]=v;
	lazy[x]=v;
}
void pushdown(int x,int l,int r)
{
	if(lazy[x]!=-1)
	{
		int mid=(l+r)/2;
		col(x*2,l,mid,lazy[x]);
		col(x*2+1,mid+1,r,lazy[x]);
		lazy[x]=-1;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=mx[x]=a[l];
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
		col(x,l,r,v);
		return;
	}
	pushdown(x,l,r);
	int mid=(l+r)/2;
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
int query(int x,int l,int r,int k)
{
	if(l==r)
	{
		if(mx[x]<=k) return 0;
		return l;
	}
	pushdown(x,l,r);
	int mid=(l+r)/2;
	if(mx[x*2+1]>k) return query(x*2+1,mid+1,r,k);
	return query(x*2,l,mid,k);
}
int query2(int x,int l,int r,ll v)
{
	if(l==r)
	{
		if(v>=sum[x]) return n+1;
		return l;
	}
	pushdown(x,l,r);
	int mid=(l+r)/2;
	if(sum[x*2]<=v) return query2(x*2+1,mid+1,r,v-sum[x*2]);
	return query2(x*2,l,mid,v);
}
ll querysum(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2;
	pushdown(x,l,r);
	return querysum(x*2,l,mid,ql,qr)+querysum(x*2+1,mid+1,r,ql,qr);
}
int main()
{
	memset(lazy,-1,sizeof(lazy));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			int l=query(1,1,n,y);
			modify(1,1,n,l+1,x,y);
		}
		else
		{
			int ans=0;
			while(x<=n)
			{
				int r=query2(1,1,n,querysum(1,1,n,1,x-1)+y)-1;
				int cur=querysum(1,1,n,x,r);
				ans+=r-x+1;
				y-=cur;
				int nw=query(1,1,n,y)+1;
			//	printf("x=%d,r=%d,cur=%d,y=%d,nw=%d\n",x,r,cur,y,nw);
				x=max(nw,r+1); 
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}