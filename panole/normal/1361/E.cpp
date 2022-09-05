#include<bits/stdc++.h>
using namespace std;

bool bo[200010];
int n,m,T,hd[200010],cnt,siz[200010],x,y,rt,fa[200010],f[200010],dep[200010];
struct node{int to,next;}e[200010];

int ran() {return rand()%1000*1000+rand()%1000;}

bool dfs(int x)
{
	bo[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (e[i].to==rt||fa[e[i].to]) 
		{
			if (!bo[e[i].to]) return 0;
		} else
		{
			fa[e[i].to]=x;
			if (!dfs(e[i].to)) return 0;
		}
	bo[x]=0;
	return 1;
}

void Dfs(int x)
{
	for (int i=hd[x]; i; i=e[i].next)
		if (fa[e[i].to]==x) dep[e[i].to]=dep[x]+1,Dfs(e[i].to),siz[x]+=siz[e[i].to];
}

void getans(int x)
{
	for (int i=hd[x]; i; i=e[i].next)
		if (fa[e[i].to]==x) 
		{
			getans(e[i].to);
			if (dep[f[e[i].to]]<dep[f[x]]) f[x]=f[e[i].to];
		} else if (dep[e[i].to]<dep[f[x]]) f[x]=e[i].to;
}

void Getans(int x)
{
	if (siz[x]==1) bo[x]&=bo[f[x]];
	for (int i=hd[x]; i; i=e[i].next)
		if (fa[e[i].to]==x) Getans(e[i].to);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		bool boo=0;
		scanf("%d%d",&n,&m),cnt=0,dep[0]=n+1;
		for (int i=1; i<=n; i++) hd[i]=siz[i]=f[i]=0;
		for (int i=1; i<=m; i++) scanf("%d%d",&x,&y),e[++cnt]=(node){y,hd[x]},hd[x]=cnt;
		for (int c=1; c<=100; c++)
		{
			rt=ran()%n+1;
			for (int i=1; i<=n; i++) bo[i]=0,fa[i]=0;
			if (dfs(rt)) {boo=1; break;}
		}
		if (!boo) {puts("-1"); continue;}
		for (int i=1; i<=n; i++)
			for (int j=hd[i]; j; j=e[j].next)
				if (fa[e[j].to]!=i) siz[i]++,siz[e[j].to]--;
		dep[rt]=0,Dfs(rt);
		for (int i=1; i<=n; i++) bo[i]=(siz[i]<2);
		getans(rt),Getans(rt),cnt=0;
		for (int i=1; i<=n; i++) cnt+=bo[i];
		if (cnt*5<n) puts("-1"); else
		{
			for (int i=1; i<=n; i++) if (bo[i]) printf("%d ",i);puts("");
		}
	}
	return 0;
}