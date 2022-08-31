#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[500005],b[500005][3],c[500005][2];
int stmn[500005],stmx[500005],tpmn,tpmx,vis[500005];
int f[500005][2],g[500005][2],sum[2000005][3];
void pushup(int x)
{
	sum[x][0]=sum[x*2][0]+sum[x*2+1][0];
	sum[x][1]=sum[x*2][1]+sum[x*2+1][1];
	sum[x][2]=sum[x*2][2]+sum[x*2+1][2];
}
void modify(int x,int l,int r,int qx,int fl)
{
	if(l>qx||r<qx) return;
	if(l==r)
	{
		sum[x][fl]=1;
		return;
	}
	int mid=(l+r)/2;
	modify(x*2,l,mid,qx,fl);
	modify(x*2+1,mid+1,r,qx,fl);
	pushup(x);
}
int query(int x,int l,int r,int qx,int fl)
{
	if(l>qx||!sum[x][fl]) return 0;
	if(l==r) return l;
	int mid=(l+r)/2,q1,q2;
	q1=query(x*2+1,mid+1,r,qx,fl);
	if(q1) return q1;
	return query(x*2,l,mid,qx,fl);
}
void printb(int x)
{
	printf("4\n%d %d %d %d\n",b[x][0],b[x][1],b[x][2],x);
}
void printc(int x)
{
	printf("3\n%d %d %d\n",c[x][0],c[x][1],x);
}
bool cmp(const int x,const int y)
{
	return a[x]<a[y];
}
bool cmp2(const int x,const int y)
{
	return a[x]>a[y];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//int las=0,lmx=0,lmn=0;
	for(int i=1;i<=n;i++)
	{
		//int nw=las,nwx=lmx,nwn=lmn;
		vis[i]=2;
		if(a[i]==a[i-1])
		{
			stmn[tpmn]=i;
			stmx[tpmx]=i;
			continue;
		}
		while(tpmn&&a[stmn[tpmn]]>a[i])
		{
			int v=stmn[tpmn];
			vis[v]--;
			if(a[stmn[tpmn]]!=a[i]) 
			{
				if(!vis[v]) modify(1,1,n,v,0);
				modify(1,1,n,v,1);
			}
			tpmn--;
		}
		while(tpmx&&a[stmx[tpmx]]<a[i])
		{
			int v=stmx[tpmx];
			vis[v]--;
			if(a[stmx[tpmx]]!=a[i]) 
			{
				if(!vis[v]) modify(1,1,n,v,0);
				modify(1,1,n,v,2);
			}
			tpmx--;
		}
		int v1=*(lower_bound(stmn+1,stmn+tpmn+1,i,cmp)-1);
		int v2=*(lower_bound(stmx+1,stmx+tpmx+1,i,cmp2)-1);
	/*	printf("i=%d,tpmn=%d,tpmx=%d,v1=%d,v2=%d\n",i,tpmn,tpmx,v1,v2);
		for(int i=1;i<=tpmn;i++)
			printf("%d ",stmn[i]);
		printf("\n");
		for(int i=1;i<=tpmx;i++)
			printf("%d ",stmx[i]);
		printf("\n"); */
		if(v1&&v2)
		{
			int q=query(1,1,n,min(v1,v2),0);
			//printf("q=%d\n",q);
			b[i][0]=q;
			b[i][1]=*lower_bound(stmn+1,stmn+tpmn+1,q);
			b[i][2]=*lower_bound(stmx+1,stmx+tpmx+1,q);
			if(b[i][1]>b[i][2]) swap(b[i][1],b[i][2]);
		}
		if(v1)
		{
			int q=query(1,1,n,v1,1);
			c[i][0]=q;
			c[i][1]=*lower_bound(stmn+1,stmn+tpmn+1,q);
			//if(c[i][0]>c[i][1]) swap(c[i][0],c[i][1]);
		}
		if(v2)
		{
			int q=query(1,1,n,v2,2);
			if(q>c[i][0]) 
			{
				c[i][0]=q;
				c[i][1]=*lower_bound(stmx+1,stmx+tpmx+1,q);
			}
		}
		//las=nw;
	//	lmn=nwn;
	//	lmx=nwx;
		stmn[++tpmn]=i;
		stmx[++tpmx]=i;
	}
	for(int i=1;i<=n;i++)
	{
		f[i][0]=b[i][0],f[i][1]=i;
		if(f[i][0]<f[i-1][0]) f[i][0]=f[i-1][0],f[i][1]=f[i-1][1];
		g[i][0]=min(c[i][0],c[i][1]),g[i][1]=i;
		if(g[i][0]<g[i-1][0]) g[i][0]=g[i-1][0],g[i][1]=g[i-1][1];
	}
	for(int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(f[r][0]>=l)
			printb(f[r][1]);
		else if(g[r][0]>=l)
			printc(g[r][1]);
		else printf("0\n");
	}
	return 0;
}