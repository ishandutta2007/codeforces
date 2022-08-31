#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],b[1000005],c[1000005],sum[2000005],lazy[2000005];
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
int query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return 0;
	if(ql<=l&&r<=qr) return sum[x];
	int mid=(l+r)/2,q1,q2;
	q1=query(x*2,l,mid,ql,qr);
	q2=query(x*2+1,mid+1,r,ql,qr);
	return max(q1,q2);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),c[a[i]]=i;
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	int nw=n;
	for(int i=1;i<=n;i++)
	{
		printf("%d ",nw);
		modify(1,1,n,1,b[i],-1);
		while(nw)
		{
			modify(1,1,n,1,c[nw],1);
			if(sum[1]>0)
			{
				modify(1,1,n,1,c[nw],-1);
				break;
			}
			nw--;
		}
	}
	return 0;
}