#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int bl=310;
int n,m,fir[100005],a[100005],f[100005],b[100005],ft,c[100005],lazy[100005];
void build(int x)
{
	if(c[x]) return;
	int fl=0;
	for(int i=fir[x];i<fir[x+1];i++)
	{
		if(b[a[i]]!=x) f[i]=i;
		else f[i]=f[a[i]],fl=1;
	}
	if(!fl) c[x]=1;
}
void col(int x,int v)
{
	if(!c[x])
	{
		for(int i=fir[x];i<fir[x+1];i++)
			a[i]=max(a[i]-v,1);
		build(x);
		return;
	}
	lazy[x]=min(lazy[x]+v,(int)1e5);
}
void pushdown(int x)
{
	for(int i=fir[x];i<fir[x+1];i++)
		a[i]=max(a[i]-lazy[x],1);
	lazy[x]=0;
}
void modify(int l,int r,int v)
{
	if(b[l]==b[r])
	{
		pushdown(b[l]);
		for(int i=l;i<=r;i++)
			a[i]=max(a[i]-v,1);
		build(b[l]);
		return;
	}
	pushdown(b[l]);
	for(int i=l;i<fir[b[l]+1];i++)
		a[i]=max(a[i]-v,1);
	build(b[l]);
	pushdown(b[r]);
	for(int i=fir[b[r]];i<=r;i++)
		a[i]=max(a[i]-v,1);
	build(b[r]);
	for(int i=b[l]+1;i<b[r];i++)
		col(i,v);
}
inline int querya(int x)
{
	return max(a[x]-lazy[b[x]],1);
}
int lca(int u,int v)
{
	while(f[u]!=f[v])
	{
	//	printf("u=%d,v=%d\n",u,v);
		if(f[u]<f[v]) swap(u,v);
		u=querya(f[u]);
	}
	while(u!=v)
	{
		if(u<v) swap(u,v);
		u=querya(u);
	}
	return u;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		b[i]=(i-1)/bl+1;
		if(!fir[b[i]]) fir[b[i]]=i,ft++;
	}
	fir[ft+1]=n+1;
	a[1]=1;
	for(int i=2;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=ft;i++)
		build(i);
	for(int i=1;i<=m;i++)
	{
		int op,x,y,v;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			scanf("%d",&v);
			modify(x,y,v);
		}
		else printf("%d\n",lca(x,y));
	//	for(int i=1;i<=n;i++)
	//		printf("i=%d,a=%d,f=%d\n",i,querya(i),f[i]);
	}
	return 0;
}