#include<bits/stdc++.h>
using namespace std;

struct node{int to,next;}e[200010];
struct seg{int l,r; pair<int,int> x;}t[800010];
int n,p[200010],f[400010][19],g[400010][19],lo[400010],tot,PO[200010],L[200010],R[200010],po[200010],fa[200010],hd[200010],cnt,dep[200010],q,ord,x,y;

void dfs(int x)
{
	L[x]=(++cnt),dep[x]=dep[fa[x]]+1,f[++tot][0]=dep[x],g[tot][0]=x,PO[x]=tot;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,dfs(e[i].to),f[++tot][0]=dep[x],g[tot][0]=x;
	R[x]=cnt;
}

int lca(int x,int y)
{
	x=PO[x],y=PO[y];
	if (x>y) swap(x,y);
	int len=lo[y-x+1];
	if (f[x][len]<f[y-(1<<len)+1][len]) return g[x][len];
	else return g[y-(1<<len)+1][len];
}

bool check(int x,int y,int z)
{
	int l=lca(x,y);
	if (L[l]<=L[z]&&R[l]>=L[z]&&L[z]<=L[y]&&R[z]>=L[y]) return 1;
	if (L[l]<=L[z]&&R[l]>=L[z]&&L[z]<=L[x]&&R[z]>=L[x]) return 1;
	return 0;
}

pair<int,int> merge(pair<int,int> A,pair<int,int> B)
{
	if (check(A.first,A.second,B.first)&&check(A.first,A.second,B.second)) return make_pair(A.first,A.second);
	if (check(A.first,B.second,B.first)&&check(A.first,B.second,A.second)) return make_pair(A.first,B.second);
	if (check(B.first,A.second,A.first)&&check(B.first,A.second,B.second)) return make_pair(B.first,A.second);
	if (check(B.first,B.second,A.first)&&check(B.first,B.second,A.second)) return make_pair(B.first,B.second);
	if (check(A.first,B.first,A.second)&&check(A.first,B.first,B.second)) return make_pair(A.first,B.first);
	if (check(A.second,B.second,A.first)&&check(A.second,B.second,B.first)) return make_pair(A.second,B.second);
	return make_pair(0,0);
}

void pushup(int i)
{
	if (!t[i<<1].x.first||!t[i<<1|1].x.first) t[i].x=make_pair(0,0);
	else t[i].x=merge(t[i<<1].x,t[i<<1|1].x);
}

void build(int i,int l,int r)
{
	t[i].l=l,t[i].r=r;
	if (l==r) {t[i].x=make_pair(po[l],po[l]); return;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
	pushup(i);
}

void change(int i,int x,int v)
{
	if (t[i].l==t[i].r) {t[i].x=make_pair(v,v); return;}
	int mid=(t[i].l+t[i].r)>>1;
	if (x<=mid) change(i<<1,x,v);
	else change(i<<1|1,x,v);
	pushup(i);
}

int find(int i,pair<int,int> nw)
{
	if (t[i].l==t[i].r) return t[i].l-1;
	pair<int,int> mid=(t[i<<1].x.first!=0?merge(t[i<<1].x,nw):make_pair(0,0));
	if (mid.first!=0) return find(i<<1|1,mid);
	return find(i<<1,nw);
}

int main()
{
	lo[1]=0;
	for (int i=2; i<=400000; i++) lo[i]=lo[i>>1]+1;
	scanf("%d",&n),memset(hd,0,sizeof(hd));
	for (int i=1; i<=n; i++) scanf("%d",&p[i]),p[i]++,po[p[i]]=i;
	for (int i=2; i<=n; i++) scanf("%d",&cnt),e[i]=(node){i,hd[cnt]},hd[cnt]=i;
	memset(fa,0,sizeof(fa)),dep[0]=cnt=tot=0,dfs(1);
	for (int j=1; j<=18; j++)
		for (int i=1; i+(1<<j)-1<=tot; i++)
			if (f[i][j-1]<f[i+(1<<j-1)][j-1]) f[i][j]=f[i][j-1],g[i][j]=g[i][j-1];
			else f[i][j]=f[i+(1<<j-1)][j-1],g[i][j]=g[i+(1<<j-1)][j-1];
	build(1,1,n),scanf("%d",&q);
	while (q--)
	{
		scanf("%d",&ord);
		if (ord==2) printf("%d\n",t[1].x.first!=0?n:find(1,make_pair(po[1],po[1])));
		else
		{
			scanf("%d%d",&x,&y),change(1,p[x],y),change(1,p[y],x);
			swap(p[x],p[y]),po[p[x]]=x,po[p[y]]=y;
		}
	}
	return 0;
}