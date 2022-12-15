#include<bits/stdc++.h>
using namespace std;

bool bo[1000010];
int bel[1000010],hd[1000010],sta[1000010],dfn[1000010],low[1000010],tp,n,m,x,y,cnt,siz[1000010];
struct node{int to,next,fro;}e[2000010];

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x],x},hd[x]=cnt;
}

void tarjan(int x)
{
	sta[++tp]=x,bo[x]=1,dfn[x]=low[x]=(++cnt);
	for (int i=hd[x]; i ;i=e[i].next)
		if (dfn[e[i].to])
		{
			if (bo[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
		} else tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
	if (dfn[x]==low[x])
	{
		bel[x]=x,siz[x]=1,bo[x]=0;
		while (sta[tp]!=x)
		{
			bo[sta[tp]]=0,bel[sta[tp]]=x,siz[x]++;
			tp--;
		}
		tp--;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m),cnt=0;
		for (int i=1; i<=n; i++) hd[i]=dfn[i]=0,bo[i]=0;
		for (int i=1; i<=m; i++)
		{
			scanf("%d%d",&x,&y);
			if (x==y) continue;
			addedge(x,y);
		}
		int Cnt=cnt;
		tp=cnt=0;
		for (int i=1; i<=n; i++) if (!dfn[i]) tarjan(i);
		if (siz[bel[1]]==n) {puts("No"); continue;}
		for (int i=1; i<=n; i++) if (bel[i]==i) bo[i]=1; else bo[i]=0;
		for (int i=1; i<=Cnt; i++)
			if (bel[e[i].fro]!=bel[e[i].to]) bo[bel[e[i].fro]]=0;
		for (int i=1; i<=n; i++) if (bo[i])
		{
			puts("Yes");
			printf("%d %d\n",siz[i],n-siz[i]);
			for (int j=1; j<=n; j++) if (bel[j]==i)printf("%d ",j); puts("");
			for (int j=1; j<=n; j++) if (bel[j]!=i)printf("%d ",j); puts("");
			break;
		}
	}
	return 0;
}