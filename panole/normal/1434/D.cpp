#include<bits/stdc++.h>
using namespace std;

int m,n,dep[500010],L[500010],R[500010],q[500010],l,r,hd[500010],cnt,ans[500010],col[500010],c[500010],fa[500010],id[500010];
struct edg{int to,next,val;}e[1000010];
bool bo[500010];

struct node{int l,r,val[2],laz;}t[2000010];

void addedge(int x,int y,int z)
{
	e[++cnt]=(edg){y,hd[x],z},hd[x]=cnt;
	e[++cnt]=(edg){x,hd[y],z},hd[y]=cnt;
}

void dfs(int x)
{
	L[x]=++cnt,id[cnt]=x,dep[x]=dep[fa[x]]+1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) col[e[i].to]=col[x]^e[i].val,fa[e[i].to]=x,dfs(e[i].to);
	R[x]=cnt;
}

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].laz=0,t[i].val[0]=t[i].val[1]=0;
	if (l==r) {t[i].val[col[id[l]]]=dep[id[l]]; return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
	t[i].val[0]=max(t[i<<1].val[0],t[i<<1|1].val[0]);
	t[i].val[1]=max(t[i<<1].val[1],t[i<<1|1].val[1]);
}

void pushdown(int x)
{
	if (!t[x].laz) return;
	t[x<<1].laz^=1,t[x<<1|1].laz^=1;
	swap(t[x<<1].val[0],t[x<<1].val[1]);
	swap(t[x<<1|1].val[0],t[x<<1|1].val[1]);
	t[x].laz=0;
}

void change(int i,int l,int r)
{
	if (t[i].l==l&&t[i].r==r)
	{
		swap(t[i].val[0],t[i].val[1]);
		t[i].laz^=1;
		return;
	}
	pushdown(i);
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) change(i<<1,l,r); else
	if (l>mid) change(i<<1|1,l,r); else
	change(i<<1,l,mid),change(i<<1|1,mid+1,r);
	t[i].val[0]=max(t[i<<1].val[0],t[i<<1|1].val[0]);
	t[i].val[1]=max(t[i<<1].val[1],t[i<<1|1].val[1]);
}

void work(int rt)
{
	dep[0]=-1,col[rt]=0,cnt=0,fa[rt]=0,dfs(rt);
	build(1,1,n);
	for (int i=1; i<=m; i++) 
	{
		int x=e[c[i]*2-1].to,y=e[c[i]*2].to;
		if (fa[x]==y) swap(x,y);
		change(1,L[y],R[y]);
		ans[i]=max(ans[i],t[1].val[0]);
	}
}

int main()
{
	scanf("%d",&n),cnt=0;
	for (int i=1; i<n; i++)
	{
		int z;
		scanf("%d%d%d",&l,&r,&z);
		addedge(l,r,z);
	}
	q[l=r=1]=1;
	memset(bo,0,sizeof(bo));
	bo[1]=1;
	while (l<=r)
	{
		int x=q[l++];
		for (int i=hd[x]; i; i=e[i].next)
			if (!bo[e[i].to]) bo[e[i].to]=1,q[++r]=e[i].to;
	}
	q[1]=q[r],l=r=1;
	memset(bo,0,sizeof(bo));
	bo[q[1]]=1;
	while (l<=r)
	{
		int x=q[l++];
		for (int i=hd[x]; i; i=e[i].next)
			if (!bo[e[i].to]) bo[e[i].to]=1,q[++r]=e[i].to;
	}
	scanf("%d",&m);
	for (int i=1; i<=m; i++) scanf("%d",&c[i]);
	work(q[1]),work(q[r]);
	for (int i=1; i<=m; i++) printf("%d\n",ans[i]);
	return 0;
}