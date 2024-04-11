#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,mx[1000005],mxl[1000005],mxr[1000005],mn[1000005],mnl[1000005],mnr[1000005];
int idmxl[1000005],idmxr[1000005],idmnl[1000005],idmnr[1000005];
int idmxlr[1000005],idmxrl[1000005],idmnlr[1000005],idmnrl[1000005];
int sum[1000005],lazy[1000005];
int ansid1=1e6,ansid2=1e6+1,a[1000005],st[100005][2],tp;
void pushup(int x,int ls,int rs)
{
	sum[x]=sum[ls]+sum[rs];
	mxl[x]=max(mxl[ls],sum[ls]+mxl[rs]);
	if(mxl[x]==mxl[ls]) idmxlr[x]=idmxlr[ls];
	else idmxlr[x]=idmxlr[rs];
	mxr[x]=max(mxr[rs],sum[rs]+mxr[ls]);
	if(mxr[x]==mxr[rs]) idmxrl[x]=idmxrl[rs];
	else idmxrl[x]=idmxrl[ls];
	mx[x]=max(max(mx[ls],mx[rs]),mxr[ls]+mxl[rs]);
	if(mx[x]==mx[ls]) idmxl[x]=idmxl[ls],idmxr[x]=idmxr[ls];
	else if(mx[x]==mx[rs]) idmxl[x]=idmxl[rs],idmxr[x]=idmxr[rs];
	else idmxl[x]=idmxrl[ls],idmxr[x]=idmxlr[rs];
	mnl[x]=min(mnl[ls],sum[ls]+mnl[rs]);
	if(mnl[x]==mnl[ls]) idmnlr[x]=idmnlr[ls];
	else idmnlr[x]=idmnlr[rs];
	mnr[x]=min(mnr[rs],sum[rs]+mnr[ls]);
	if(mnr[x]==mnr[rs]) idmnrl[x]=idmnrl[rs];
	else idmnrl[x]=idmnrl[ls];
	mn[x]=min(min(mn[ls],mn[rs]),mnr[ls]+mnl[rs]);
	if(mn[x]==mn[ls]) idmnl[x]=idmnl[ls],idmnr[x]=idmnr[ls];
	else if(mn[x]==mn[rs]) idmnl[x]=idmnl[rs],idmnr[x]=idmnr[rs];
	else idmnl[x]=idmnrl[ls],idmnr[x]=idmnlr[rs];
}
void col(int x)
{
	sum[x]=-sum[x];
	swap(mxl[x],mnl[x]),swap(mxr[x],mnr[x]),swap(mx[x],mn[x]);
	mxl[x]=-mxl[x],mnl[x]=-mnl[x],mxr[x]=-mxr[x];
	mnr[x]=-mnr[x],mx[x]=-mx[x],mn[x]=-mn[x]; 
	swap(idmxlr[x],idmnlr[x]),swap(idmxrl[x],idmnrl[x]);
	swap(idmxl[x],idmnl[x]),swap(idmxr[x],idmnr[x]);
	lazy[x]^=1;
}
void pushdown(int x)
{
	if(lazy[x])
	{
		col(x*2);
		col(x*2+1);
		lazy[x]=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		sum[x]=mxl[x]=mxr[x]=mx[x]=mnl[x]=mnr[x]=mn[x]=a[l];
		idmxl[x]=idmxr[x]=idmxlr[x]=idmxrl[x]=idmnl[x]=idmnr[x]=idmnlr[x]=idmnrl[x]=l;
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x,x*2,x*2+1);
}
void modifyl(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x);
		return;
	}
	int mid=(l+r)/2;
	pushdown(x);
	modifyl(x*2,l,mid,ql,qr);
	modifyl(x*2+1,mid+1,r,ql,qr);
	pushup(x,x*2,x*2+1);
}
void modify(int x,int l,int r,int qx,int v)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x]=mxl[x]=mxr[x]=mx[x]=mnl[x]=mnr[x]=mn[x]=v;
		return;
	}
	int mid=(l+r)/2;
	pushdown(x);
	modify(x*2,l,mid,qx,v);
	modify(x*2+1,mid+1,r,qx,v);
	pushup(x,x*2,x*2+1);
}
void copyt(int x,int y)
{
	sum[x]=sum[y],mxl[x]=mxl[y],mxr[x]=mxr[y];
	mx[x]=mx[y],idmxl[x]=idmxl[y],idmxr[x]=idmxr[y];
	idmxlr[x]=idmxlr[y],idmxrl[x]=idmxrl[y];
} 
void query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		if(idmxl[ansid1]==-1)
		{
			copyt(ansid1,x);
			return;
		}
		copyt(ansid2,ansid1);
		pushup(ansid1,ansid2,x);
		return;
	}
	int mid=(l+r)/2;
	pushdown(x);
	query(x*2,l,mid,ql,qr);
	query(x*2+1,mid+1,r,ql,qr);
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
		int op,l,r,k;
		scanf("%d%d%d",&op,&l,&r);
		if(op==0) modify(1,1,n,l,r);
		else
		{
			scanf("%d",&k);
			int ans=0;
			tp=0;
			while(k--)
			{
				idmxl[ansid1]=-1;
				query(1,1,n,l,r);
				if(mx[ansid1]<0) break;
				ans+=mx[ansid1];
				//printf("idmxl=%d,idmxr=%d\n",idmxl[ansid1],idmxr[ansid1]);
				modifyl(1,1,n,idmxl[ansid1],idmxr[ansid1]);
				st[++tp][0]=idmxl[ansid1];
				st[tp][1]=idmxr[ansid1];
			}
			for(int i=1;i<=tp;i++)
				modifyl(1,1,n,st[i][0],st[i][1]);
			printf("%d\n",ans);
		}
	}
}