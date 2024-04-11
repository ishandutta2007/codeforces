#include<bits/stdc++.h>
using namespace std;

multiset<int> s;
vector<int> v[200010],V[200010];
int dep[200010],n,m,fa[200010],hd[200010],cnt,f[200010][18],g[200010][18],ans[200010],x,y,z,ve[200010],siz[200010];
struct Node{int x,y,po,val; bool bo;}E[200010];
bool cmp(Node a,Node b) {return a.val<b.val;}
struct node{int to,next,val;}e[400010];

int ask(int x) {return fa[x]==x?x:fa[x]=ask(fa[x]);}

void addedge(int x,int y,int v)
{
	e[++cnt]=(node){y,hd[x],v},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y],v},hd[y]=cnt;
}

void dfs(int x)
{
	dep[x]=dep[fa[x]]+1,siz[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) fa[e[i].to]=x,g[e[i].to][0]=e[i].val,dfs(e[i].to),siz[x]+=siz[e[i].to];
}

int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	for (int j=17; j>=0; j--)
		if (dep[f[x][j]]>=dep[y]) x=f[x][j];
	if (x==y) return x;
	for (int j=17; j>=0; j--)
		if (f[x][j]!=f[y][j]) x=f[x][j],y=f[y][j];
	return f[x][0];
}

void add(int x)
{
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]) add(e[i].to);
	for (int i=0,sz=v[x].size(); i<sz; i++) s.insert(v[x][i]);
	for (int i=0,sz=V[x].size(); i<sz; i++) s.erase(s.find(V[x][i])),s.erase(s.find(V[x][i]));
}

void Dfs(int x)
{
	int ma=0,maa;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to!=fa[x]&&siz[e[i].to]>ma) ma=siz[e[i].to],maa=e[i].to;
	if (ma)
	{
		for (int i=hd[x]; i; i=e[i].next)
			if (e[i].to!=fa[x]&&e[i].to!=maa) Dfs(e[i].to),s.clear();
		Dfs(maa);
		for (int i=hd[x]; i; i=e[i].next)
			if (e[i].to!=fa[x]&&e[i].to!=maa) add(e[i].to);
	}
	for (int i=0,sz=v[x].size(); i<sz; i++) s.insert(v[x][i]);
	for (int i=0,sz=V[x].size(); i<sz; i++) s.erase(s.find(V[x][i])),s.erase(s.find(V[x][i]));
	if (s.size()) ans[ve[x]]=(*s.begin())-1; else ans[ve[x]]=-1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1; i<=m; i++) scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].val),E[i].po=i,E[i].bo=0;
	sort(E+1,E+1+m,cmp);
	memset(hd,0,sizeof(hd));
	for (int i=1; i<=n; i++) fa[i]=i;
	for (int i=1; i<=m; i++)
	{
		if (ask(E[i].x)==ask(E[i].y)) continue;
		addedge(E[i].x,E[i].y,E[i].val);
		fa[ask(E[i].x)]=ask(E[i].y),E[i].bo=1;
	}
	memset(fa,0,sizeof(fa)),g[1][0]=0,dep[0]=ve[1]=0,dfs(1);
	for (int i=1; i<=n; i++) f[i][0]=fa[i];
	for (int j=1; j<=17; j++)
		for (int i=1; i<=n; i++) 
			f[i][j]=f[f[i][j-1]][j-1],
			g[i][j]=max(g[i][j-1],g[f[i][j-1]][j-1]);
	for (int i=1; i<=m; i++)
		if (!E[i].bo)
		{
			x=E[i].x,y=E[i].y,z=lca(x,y);
			v[x].push_back(E[i].val),v[y].push_back(E[i].val),V[z].push_back(E[i].val);
			int an=0;
			for (int j=17; j>=0; j--)
				if (dep[f[x][j]]>=dep[z]) an=max(an,g[x][j]),x=f[x][j];
			for (int j=17; j>=0; j--)
				if (dep[f[y][j]]>=dep[z]) an=max(an,g[y][j]),y=f[y][j];
			ans[E[i].po]=an-1;
		} else 
		{
			if (fa[E[i].x]==E[i].y) ve[E[i].x]=E[i].po;
			else ve[E[i].y]=E[i].po;
		}
	s.clear(),Dfs(1);
	for (int i=1; i<=m; i++) printf("%d ",ans[i]); puts("");
	return 0;
}