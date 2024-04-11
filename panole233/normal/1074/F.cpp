#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

int n,m,hd[200001],cnt,x,y,l[200001],r[200001],tmp,fa[200001],f[200001][19],dep[200001],l1,r1,l2,r2,v;
map<int,bool> ma[200001];

struct node
{
	int to,next;
}e[400001];

struct node2
{
	int l,r,val,sum;
}t[800001];

void addedge(int x,int y)
{
	e[++cnt].next=hd[x];
	hd[x]=cnt;
	e[cnt].to=y;
}

void dfs(int x)
{
	l[x]=(++cnt);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,dep[e[i].to]=dep[x]+1,dfs(e[i].to);
	r[x]=cnt;
}

void build(int i,int l,int r)
{
	t[i].l=l; t[i].r=r; t[i].val=t[i].sum=0;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid); build(i<<1|1,mid+1,r);
}

void pushup(int i)
{
	if (t[i].val) t[i].sum=t[i].r-t[i].l+1;
	else if (t[i].l==t[i].r) t[i].sum=0;
	else t[i].sum=t[i<<1].sum+t[i<<1|1].sum;
}

void add(int i,int l,int r,int v)
{
	if (l>r) return;
	if (l==t[i].l&&r==t[i].r) {t[i].val+=v,pushup(i); return;}
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) add(i<<1,l,r,v); else
	if (l>mid) add(i<<1|1,l,r,v); else
	add(i<<1,l,mid,v),add(i<<1|1,mid+1,r,v);
	pushup(i);
}

int main()
{
	scanf("%d%d",&n,&m); cnt=0;
	for (int i=0; i<=n; i++) ma[i].clear();
	memset(hd,0,sizeof(hd));
	for (int i=1; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	memset(fa,0,sizeof(fa));
	dep[1]=1; dep[0]=0; cnt=0; dfs(1);
	for (int i=1; i<=n; i++) f[i][0]=fa[i];
	for (int j=1; j<19; j++)
		for (int i=1; i<=n; i++) f[i][j]=f[f[i][j-1]][j-1];
	build(1,1,n);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		if (l[x]>l[y]) tmp=x,x=y,y=tmp;
		if (ma[x].find(y)==ma[x].end()||!ma[x][y]) v=1,ma[x][y]=1; else v=-1,ma[x][y]=0;
		if (r[x]>=l[y]) 
		{
			int Y=y;
			for (int j=18; j>=0; j--)
				if (dep[f[Y][j]]>dep[x]) Y=f[Y][j];
			add(1,l[Y],l[y]-1,v); add(1,r[y]+1,r[Y],v);
		} else add(1,1,l[x]-1,v),add(1,r[x]+1,l[y]-1,v),add(1,r[y]+1,n,v);
		printf("%d\n",n-t[1].sum);
	}
	return 0;
}