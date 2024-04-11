#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,m,a[500005],vis[500005],b[105],bt,tans[500005];
int mx,mxid;
#define id(i,j) (((i)-1)*m+(j))
void check1()
{
	for(int i=1;i<=n;i++)
	{
		int nw=0;
		for(int j=1;j<=m;j++)
			if(a[id(i,j)]!=tans[j])
				nw++;
		if(nw>2) return;
	}
	printf("Yes\n");
	for(int i=1;i<=m;i++)
		printf("%d ",tans[i]);
	printf("\n");
	exit(0);
}
void dfs1(int dep)
{
	if(dep==bt+1)
	{
		check1();
		return;
	}
	int u=b[dep];
	tans[u]=a[id(1,u)];
	dfs1(dep+1);
	tans[u]=a[id(mxid,u)];
	dfs1(dep+1);
}
struct pt
{
	int val,id;
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
}p[500005];
void check2()
{
	int ps=-1;
	for(int i=1;i<=m;i++)
	{
		if(tans[i]==-1)
		{
			if(ps!=-1) return;
			ps=i;
		}
	}
	if(ps==-1) return;
	int ct=0;
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		for(int j=1;j<=m;j++)
		{
			if(j==ps) continue;
			if(a[id(i,j)]!=tans[j]) vis[i]++;
		}
		if(vis[i]>2) return;
		ct+=(vis[i]==2);
	}
	for(int i=1;i<=n;i++)
	{
		p[i].id=i;
		p[i].val=a[id(i,ps)];
	}
	sort(p+1,p+n+1);
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r<n&&p[r+1].val==p[l].val) r++;
		int qwq=0;
		for(int i=l;i<=r;i++)
			if(vis[p[i].id]==2)
				qwq++;
		if(qwq==ct)
		{
			printf("Yes\n");
			tans[ps]=p[l].val;
			for(int j=1;j<=m;j++)
				printf("%d ",tans[j]);
			printf("\n");
			exit(0);
		}
	}
}
void dfs2(int dep)
{
	if(dep==bt+1)
	{
		check2();
		return;
	}
	int u=b[dep];
	tans[u]=a[id(1,u)];
	dfs2(dep+1);
	tans[u]=a[id(mxid,u)];
	dfs2(dep+1);
	tans[u]=-1;
	dfs2(dep+1);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[id(i,j)]);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(a[id(1,j)]!=a[id(i,j)])
				vis[i]++;
		if(vis[i]>mx)
		{
			mx=vis[i];
			mxid=i;
		}
	}
	if(mx<=2)
	{
		printf("Yes\n");
		for(int i=1;i<=m;i++)
			printf("%d ",a[id(1,i)]);
		printf("\n");
		return 0;
	}
	if(mx>4)
	{
		printf("No\n");
		return 0;
	}
	for(int j=1;j<=m;j++)
		if(a[id(1,j)]!=a[id(mxid,j)])
			b[++bt]=j;
	if(mx==4)
	{
		for(int j=1;j<=m;j++)
			tans[j]=a[id(1,j)];
		dfs1(1);
		printf("No\n");
		return 0;
	}
	for(int j=1;j<=m;j++)
		tans[j]=a[id(1,j)];
	dfs2(1);
	printf("No\n");
	return 0;
}