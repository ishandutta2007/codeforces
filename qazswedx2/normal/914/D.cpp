#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000005],sum[3000005];
int gcd(int x,int y)
{
	if(!y) return x;
	return gcd(y,x%y);
}
void pushup(int x)
{
	sum[x]=gcd(sum[x*2],sum[x*2+1]);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x);
}
void modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]=v;
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x);
}
int query(int x,int l,int r,int ql,int qr,int v)
{
	//printf("x=%d,l=%d,r=%d,ql=%d,qr=%d,v=%d,sum=%d\n",x,l,r,ql,qr,v,sum[x]);
	if(l>qr||r<ql) return 0;
	if(sum[x]%v==0) return 0; 
	if(l==r) return 1;
	int mid=(l+r)/2,ans=0;
	if(sum[x*2]%v&&mid>=ql) 
	{
		ans+=query(x*2,l,mid,ql,qr,v);
		if(ans>1) return ans;
	}
	if(sum[x*2+1]%v&&mid+1<=qr)
		ans+=query(x*2+1,mid+1,r,ql,qr,v);
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int op,x,y,z;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			scanf("%d",&z);
			int q=query(1,1,n,x,y,z);
			if(q>1) printf("NO\n");
			else printf("YES\n");
		}
		else
		{
			modify(1,1,n,x,y);
		}
	}
	return 0;
}