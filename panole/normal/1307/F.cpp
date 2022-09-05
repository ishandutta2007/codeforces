#include<bits/stdc++.h>
using namespace std;

const int inf=1000000000;
bool bo[200010];
int dfn[200010],tp[200010],siz[200010],n,k,r,hd[200010],cnt,fa[200010],dep[200010],Fa[200010],bel[200010],x,y,f[200010][18],q[200010],l,p[200010];
struct node{int to,next;}e[400010];
struct seg{int l,r; pair<int,int> mi;}t[800010];

int ask(int x) {return Fa[x]==x?x:Fa[x]=ask(Fa[x]);}

void dfs(int x)
{
	siz[x]=1;
	dep[x]=dep[fa[x]]+1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,dfs(e[i].to),siz[x]+=siz[e[i].to];
}

void Dfs(int x)
{
	dfn[x]=(++cnt); int ma=0,maa;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&siz[e[i].to]>ma) ma=siz[e[i].to],maa=e[i].to;
	if (!ma) return;
	tp[maa]=tp[x],Dfs(maa);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=maa) tp[e[i].to]=e[i].to,Dfs(e[i].to);
}

int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=17; j>=0; j--)
		if (dep[f[x][j]]>=dep[y]) x=f[x][j];
	if (x==y) return x;
	for (int j=17; j>=0; j--)
		if (f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
	return fa[x];
}

int getdis(int x,int y) {return dep[x]+dep[y]-2*dep[lca(x,y)];}

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].mi=make_pair(inf,0);
	if (l==r) return;
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}

void change(int i,int x,pair<int,int> v)
{
	if (t[i].l==t[i].r) {t[i].mi=v; return;}
	int mid=(t[i].l+t[i].r)>>1;
	change(i<<1|(x>mid),x,v);
	t[i].mi=min(t[i<<1].mi,t[i<<1|1].mi);
}

pair<int,int> query(int i,int l,int r)
{
	if (t[i].l==l&&t[i].r==r) return t[i].mi;
	int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) return query(i<<1,l,r);
	if (l>mid) return query(i<<1|1,l,r);
	return min(query(i<<1,l,mid),query(i<<1|1,mid+1,r));
}

void add(int x)
{
	int nw=-dep[x],X=x;
	while (x&&p[x]==inf) p[x]=nw,change(1,dfn[x],make_pair(nw,X)),x=fa[x],nw+=2;
}

int query(int x)
{
	int X=x;
	pair<int,int> ans=make_pair(inf,0);
	while (x)
	{
		ans=min(ans,query(1,dfn[tp[x]],dfn[x]));
		x=fa[tp[x]];
	}
	x=X;
	if (ans.first+dep[x]>k) return 0;
	return ans.second;
}

int main()
{
	scanf("%d%d%d",&n,&k,&r);
	for (int i=1; i<n; i++)
	{
		scanf("%d%d",&x,&y);
		e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
		e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
	}
	for (int i=1; i<=r; i++) scanf("%d",&x),bo[x]=1;
	for (int i=1; i<=n; i++) p[i]=inf;
	dfs(1),cnt=0,tp[1]=1,Dfs(1),build(1,1,n);
	for (int i=1; i<=n; i++) f[i][0]=fa[i];
	for (int j=1; j<=17; j++)
		for (int i=1; i<=n; i++)
			f[i][j]=f[f[i][j-1]][j-1];
	q[l=r=1]=1;
	while (l<=r)
	{
		x=q[l++];
		if (bo[x])
		{
			Fa[x]=query(x);
			if (!Fa[x]) Fa[x]=x;
			bel[x]=Fa[x],add(x);
		} else 
		{
			bel[x]=query(x);
			if (!bel[x]) bel[x]=x;
			Fa[x]=x;
		}
		for (int i=hd[x]; i; i=e[i].next)
			if (e[i].to!=fa[x]) q[++r]=e[i].to;
	}
	scanf("%d",&r);
	while (r--)
	{
		scanf("%d%d",&x,&y);
		if (getdis(x,y)<=k) {puts("YES"); continue;}
		int xx=ask(bel[x]),yy=ask(bel[y]);
		if (xx==yy||getdis(x,yy)<=k||getdis(xx,y)<=k) puts("YES");
		else puts("NO");
	}
	return 0;
}