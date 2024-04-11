#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef pair<long long,long long> pll;
struct Edge{int to,next; pll v;}e[600010];
struct node{int l,r; long long val,laz;}t[1200001];
int q,n,hd[300010],cnt,x,y,dep[300010],L[300010],R[300010],po[300010],fa[300010][19],rt,siz[300010],qx[600010],qy[600010];
long long w[300001],v0,v1,fv[300010],ans[600010];
vector<int> T[300010],nw,qu[300001];
bool bo[300001];
pll f[600001];

void addedge(int x,int y,long long v0,long long v1)
{
	e[++cnt].next=hd[x],hd[x]=cnt,e[cnt].to=y,e[cnt].v=mp(v0,v1);
	e[++cnt].next=hd[y],hd[y]=cnt,e[cnt].to=x,e[cnt].v=mp(v0,v1);
}

pll operator +(pll a,pll b) {return mp(a.first+b.first,a.second+b.second);}

void dfs(int x,int fa)
{
	L[x]=(++cnt),po[cnt]=x;
	for (int i=hd[x]; i; i=e[i].next) if (e[i].to!=fa) 
		f[e[i].to]=(f[x]+e[i].v),fv[e[i].to]=e[i].v.first+e[i].v.second,dfs(e[i].to,x);
	R[x]=cnt;
}

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r,t[i].laz=0;
	if (l==r) {t[i].val=w[po[l]]+f[po[l]].first+f[po[l]].second; return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
	t[i].val=min(t[i<<1].val,t[i<<1|1].val);
}

void pushdown(int i)
{
	if (!t[i].laz) return;
	t[i<<1].val+=t[i].laz,t[i<<1|1].val+=t[i].laz;
	t[i<<1].laz+=t[i].laz,t[i<<1|1].laz+=t[i].laz;
	t[i].laz=0;
}

void add(int i,int l,int r,long long val)
{
	if (t[i].l==l&&t[i].r==r) {t[i].val+=val,t[i].laz+=val; return;}
	pushdown(i); int mid=(t[i].l+t[i].r)>>1;
	if (r<=mid) add(i<<1,l,r,val); else
	if (l>mid) add(i<<1|1,l,r,val); else
	add(i<<1,l,mid,val),add(i<<1|1,mid+1,r,val);
	t[i].val=min(t[i<<1].val,t[i<<1|1].val);
}

void Dfs(int x,int fa)
{
	if (x!=1)
	{
		add(1,L[x],R[x],-fv[x]),add(1,1,L[x]-1,fv[x]);
		if (R[x]<n) add(1,R[x]+1,n,fv[x]);
	}
	w[x]=t[1].val;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa) Dfs(e[i].to,x);
	if (x!=1)
	{
		add(1,L[x],R[x],fv[x]),add(1,1,L[x]-1,-fv[x]);
		if (R[x]<n) add(1,R[x]+1,n,-fv[x]);
	}
}

void getsiz(int x,int fa)
{
	siz[x]=1,nw.push_back(x);
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa&&bo[e[i].to]) getsiz(e[i].to,x),siz[x]+=siz[e[i].to];
}

void work(int x,int Fa)
{
	nw.clear(),getsiz(x,0); 
	int mi=n+1,mii;
	for (int i=0,sz=nw.size(),ma; i<sz; i++)
	{
		y=nw[i],ma=sz-siz[y];
		for (int j=hd[y]; j; j=e[j].next)
			if (bo[e[j].to]&&siz[e[j].to]<siz[y]) ma=max(ma,siz[e[j].to]);
		if (ma<mi) mi=ma,mii=y;
	}
	fa[mii][0]=Fa,bo[mii]=0,dep[mii]=dep[Fa]+1;
	for (int i=hd[mii]; i; i=e[i].next)
		if (bo[e[i].to]) work(e[i].to,mii);
}

int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=18; j>=0; j--)
		if (dep[fa[x][j]]>=dep[y]) x=fa[x][j];
	if (x==y) return x;
	for (int j=18; j>=0; j--)
		if (fa[x][j]!=fa[y][j]) x=fa[x][j],y=fa[y][j];
	return fa[x][0];
}

void getans(int x,int fa)
{
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa&&bo[e[i].to])
		{
			f[(e[i].to<<1)-1].first=min(f[(x<<1)-1].first+e[i].v.first,f[x<<1].first+e[i].v.second+w[e[i].to]);
			f[(e[i].to<<1)-1].second=min(f[(x<<1)-1].second+e[i].v.first,f[x<<1].second+e[i].v.second+w[e[i].to]);
			f[e[i].to<<1].first=min(f[(x<<1)-1].first+e[i].v.first+w[e[i].to],f[x<<1].first+e[i].v.second);
			f[e[i].to<<1].second=min(f[(x<<1)-1].second+e[i].v.first+w[e[i].to],f[x<<1].second+e[i].v.second);
			getans(e[i].to,x);
		}
}

void solve(int x)
{
	f[(x<<1)-1]=mp(0,w[x]),f[x<<1]=mp(w[x],0),getans(x,0),bo[x]=0;
	for (int i=0,siz=qu[x].size(); i<siz; i++) 
		ans[qu[x][i]]=min(f[qx[qu[x][i]]].first+f[qy[qu[x][i]]].first,f[qx[qu[x][i]]].second+f[qy[qu[x][i]]].second);
	for (int i=0,siz=T[x].size(); i<siz; i++) solve(T[x][i]);
}

int main()
{
	scanf("%d",&n),cnt=0,memset(hd,0,sizeof(hd));
	for (int i=1; i<=n; i++) scanf("%I64d",&w[i]);
	for (int i=1; i<n; i++) scanf("%d%d%I64d%I64d",&x,&y,&v0,&v1),addedge(x,y,v0,v1);
	cnt=f[1].first=f[1].second=0,dfs(1,0),build(1,1,n),Dfs(1,0);
	memset(bo,1,sizeof(bo)),dep[0]=0,work(1,0);
	for (int i=1; i<=n; i++) if (!fa[i][0]) rt=i; else T[fa[i][0]].push_back(i);
	for (int j=1; j<=18; j++)
		for (int i=1; i<=n; i++) fa[i][j]=fa[fa[i][j-1]][j-1];
	scanf("%d",&q);
	for (int i=1; i<=q; i++) scanf("%d%d",&qx[i],&qy[i]),qu[lca(qx[i]+1>>1,qy[i]+1>>1)].push_back(i);
	for (memset(bo,1,sizeof(bo)),solve(rt),x=1; x<=q; x++) printf("%I64d\n",ans[x]); 
	return 0;
}