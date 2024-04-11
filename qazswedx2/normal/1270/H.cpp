#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000005],sum[5000005],cnt[5000005],lazy[5000005],pn=1e6+10;
void pushup(int x)
{
	sum[x]=min(sum[x*2],sum[x*2+1]);
	cnt[x]=0;
	if(sum[x]==sum[x*2]) cnt[x]+=cnt[x*2];
	if(sum[x]==sum[x*2+1]) cnt[x]+=cnt[x*2+1];
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
void modify(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,v);
		return;
	}
	int mid=(l+r)/2;
	pushdown(x);
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x);
}
void modify2(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		cnt[x]+=v;
		return;
	}
	int mid=(l+r)/2;
	pushdown(x);
	modify2(x*2,l,mid,qx,v);
	modify2(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
void tmodify(int x,int fl)
{
	modify(1,1,pn,min(a[x],a[x+1])+1,max(a[x],a[x+1]),fl);
}
void print(int x,int l,int r)
{
	printf("x=%d,l=%d,r=%d,cnt=%d,sum=%d,lazy=%d\n",x,l,r,cnt[x],sum[x],lazy[x]);
	if(l==r) return;
	int mid=(l+r)/2;
	print(x*2,l,mid);
	print(x*2+1,mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	a[0]=1e9;
	for(int i=0;i<=n;i++)
		tmodify(i,1);
	for(int i=1;i<=n;i++)
		modify2(1,1,pn,a[i],1);
	for(int i=1;i<=m;i++)
	{
		int x,v;
		scanf("%d%d",&x,&v);
		tmodify(x-1,-1);
		tmodify(x,-1);
		modify2(1,1,pn,a[x],-1);
		a[x]=v;
		tmodify(x-1,1);
		tmodify(x,1);
		modify2(1,1,pn,a[x],1);
		printf("%d\n",cnt[1]);
	//	print(1,1,pn);
	}
	return 0;
}