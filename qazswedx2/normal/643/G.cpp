#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,p,a[200005],sum[1000005][6][2],ct[1000005],lazy[1000005],nid=1000000;
void change(int x,int v,int w)
{
	int mn=w;
	//if(x==4) printf("change:x=%d,v=%d,w=%d\n",x,v,w);
	for(int i=0;i<ct[x];i++)
	{
		if(sum[x][i][0]==v)
		{
			sum[x][i][1]+=w;
			return;
		}
		mn=min(mn,sum[x][i][1]);
	}
	if(ct[x]<p)
	{
		sum[x][ct[x]][0]=v;
		sum[x][ct[x]][1]=w;
		ct[x]++;
		return;
	}
	for(int i=0;i<ct[x];i++)
		sum[x][i][1]-=mn;
	for(int i=ct[x]-1;i>=0;i--)
	{
		if(sum[x][i][1]<=0)
		{
			if(i!=ct[x]-1)
			{
				swap(sum[x][i][0],sum[x][ct[x]-1][0]);
				swap(sum[x][i][1],sum[x][ct[x]-1][1]);
			}
			ct[x]--;
		}
	}
	if(w!=mn)
	{
		sum[x][ct[x]][0]=v;
		sum[x][ct[x]][1]=w-mn;
		ct[x]++;
	}
}
void pushup(int x,int ls,int rs)
{
	ct[x]=ct[rs];
	for(int i=0;i<ct[x];i++)
		sum[x][i][0]=sum[rs][i][0],sum[x][i][1]=sum[rs][i][1];
	for(int i=0;i<ct[ls];i++)
		change(x,sum[ls][i][0],sum[ls][i][1]);
}
void col(int x,int v,int l,int r)
{
	lazy[x]=v;
	ct[x]=1;
	sum[x][0][0]=v,sum[x][0][1]=r-l+1;
}
void pushdown(int x,int l,int r)
{
	if(lazy[x])
	{
		int mid=(l+r)/2;
		col(x*2,lazy[x],l,mid);
		col(x*2+1,lazy[x],mid+1,r);
		lazy[x]=0;
	}
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		col(x,a[l],l,r);
		return;
	}
	int mid=(l+r)/2;
	build(x*2,l,mid);
	build(x*2+1,mid+1,r);
	pushup(x,x*2,x*2+1);
}
void modify(int x,int l,int r,int ql,int qr,int v)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		col(x,v,l,r);
		return;
	}
	int mid=(l+r)/2;
	pushdown(x,l,r);
	modify(x*2,l,mid,ql,qr,v);
	modify(x*2+1,mid+1,r,ql,qr,v);
	pushup(x,x*2,x*2+1);
}
void query(int x,int l,int r,int ql,int qr)
{
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr)
	{
		pushup(nid,x,nid);
		return;
	}
	pushdown(x,l,r);
	int mid=(l+r)/2;
	query(x*2,l,mid,ql,qr);
	query(x*2+1,mid+1,r,ql,qr);
}
void print(int x,int l,int r)
{
	printf("x=%d,l=%d,r=%d,ct=%d\n",x,l,r,ct[x]);
	for(int i=0;i<ct[x];i++)
		printf("(%d,%d) ",sum[x][i][0],sum[x][i][1]);
	printf("\n");
	if(l==r) return;
	int mid=(l+r)/2;
	pushdown(x,l,r);
	print(x*2,l,mid);
	print(x*2+1,mid+1,r);
}
int main()
{
	scanf("%d%d%d",&n,&m,&p);
	p=100/p;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	//print(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int op,l,r,x;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1)
		{
			scanf("%d",&x);
			modify(1,1,n,l,r,x);
		}
		else
		{
			ct[nid]=0;
			query(1,1,n,l,r);
			printf("%d ",ct[nid]);
			for(int j=0;j<ct[nid];j++)
				printf("%d ",sum[nid][j][0]);
			printf("\n");
		}
		//print(1,1,n);
	}
	return 0;
}