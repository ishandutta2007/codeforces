#include<bits/stdc++.h>
using namespace std;

bool bo[200010];
int n,dfn[200010],low[200010],q,m,hd[200010],cnt,x,y,f[18][200010],fa[200010],Hd[200010],bel[200010],tp,sta[200010],dep[200010],vx[200010],vy[200010],Fa[200010];
struct node{int to,next;}e[400010],E[400010];

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y]},hd[y]=cnt;
}

void Addedge(int x,int y) {E[++cnt]=(node){y,Hd[x]},Hd[x]=cnt;}
int ask(int x) {return Fa[x]==x?x:Fa[x]=ask(Fa[x]);}

void tarjan(int x,int la)
{
	dfn[x]=low[x]=(++cnt),sta[++tp]=x,bo[x]=1;
	for (int i=hd[x]; i; i=e[i].next) if (i!=(la^1))
	{
		if (!dfn[e[i].to]) tarjan(e[i].to,i),low[x]=min(low[x],low[e[i].to]);
		else if (bo[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	}
	if (dfn[x]==low[x])
	{
		bel[x]=x;
		while (sta[tp]!=x) bel[sta[tp]]=x,tp--;
		tp--;
	}
}

void dfs(int x)
{
	dep[x]=dep[fa[x]]+1;
	for (int i=Hd[x]; i; i=E[i].next)
		if (E[i].to!=fa[x]) fa[E[i].to]=x,dfs(E[i].to);
}

void Dfs(int x)
{
	for (int i=Hd[x]; i; i=E[i].next)
		if (E[i].to!=fa[x]) Dfs(E[i].to),vx[x]+=vx[E[i].to],vy[x]+=vy[E[i].to];
	if (vx[x]>0&&vy[x]>0) puts("No"),exit(0);
}

int main()
{
	scanf("%d%d%d",&n,&m,&q),cnt=1;
	for (int i=1; i<=n; i++) Fa[i]=i;
	for (int i=1; i<=m; i++) scanf("%d%d",&x,&y),addedge(x,y),Fa[ask(x)]=ask(y);
	cnt=tp=0,memset(bo,0,sizeof(bo));
	for (int i=1; i<=n; i++) if (!dfn[i]) tarjan(i,0);
	cnt=0;
	for (int i=1; i<=n; i++)
		for (int j=hd[i]; j; j=e[j].next)
			if (bel[i]!=bel[e[j].to]) Addedge(bel[i],bel[e[j].to]);
	dep[0]=fa[1]=0;
	for (int i=1; i<=n; i++) if (bel[i]==i&&!fa[i]) dfs(i);
	for (int i=1; i<=n; i++) f[0][i]=fa[i];
	for (int j=1; j<=17; j++)
		for (int i=1; i<=n; i++) f[j][i]=f[j-1][f[j-1][i]];
	while (q--)
	{
		scanf("%d%d",&x,&y);
		if (ask(x)!=ask(y)) return puts("No"),0;
		x=bel[x],y=bel[y],vx[x]++,vy[y]++;
		if (dep[x]<dep[y]) swap(x,y);
		for (int j=17; j>=0; j--)
			if (dep[f[j][x]]>=dep[y]) x=f[j][x];
		if (x==y) vx[x]--,vy[x]--; else
		{
			for (int j=17; j>=0; j--)
				if (f[j][x]!=f[j][y]) x=f[j][x],y=f[j][y];
			vx[fa[x]]--,vy[fa[x]]--;
		}
	}
	for (int i=1; i<=n; i++) if (bel[i]==i&&!fa[i]) Dfs(i);
	puts("Yes");
	return 0;
}