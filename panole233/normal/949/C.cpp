#include<cstdio>
#include<cstring>

int bel[100001],hd[100001],cnt,a[100001],h,n,m,x,y,num[100001],mi,sta[100001],tp,dfn[100001],low[100001],mii;
bool b[100001],bo[100001];

struct node
{
	int to,next;
}e[200001];

void addedge(int x,int y)
{
	e[++cnt].next=hd[x];
	hd[x]=cnt;
	e[cnt].to=y;
}

int getmin(int a,int b) {return a<b?a:b;}

void dfs(int x)
{
	dfn[x]=++cnt; low[x]=cnt;
	bo[x]=1; sta[++tp]=x;
	for (int i=hd[x]; i; i=e[i].next)
		if (!dfn[e[i].to]) dfs(e[i].to),low[x]=getmin(low[x],low[e[i].to]);
		else if (bo[e[i].to]) low[x]=getmin(low[x],dfn[e[i].to]);
	if (dfn[x]==low[x])
	{
		bo[x]=0; bel[x]=x; num[x]=1;
		while (sta[tp]!=x) bel[sta[tp]]=x,bo[sta[tp]]=0,tp--,num[x]++;
		tp--;
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&h);
	cnt=0;
	memset(hd,0,sizeof(hd));
	for (int i=1; i<=n; i++) scanf("%d",&a[i]);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d",&x,&y);
		if ((a[x]+1)%h==a[y]) addedge(x,y);
		if ((a[y]+1)%h==a[x]) addedge(y,x);
	}
	memset(bo,0,sizeof(bo));
	memset(dfn,0,sizeof(dfn));
	cnt=0;
	for (int i=1; i<=n; i++)
		if (!dfn[i]) tp=0,dfs(i);
	memset(b,1,sizeof(b));
	for (int i=1; i<=n; i++)
		for (int j=hd[i]; j; j=e[j].next)
			if (bel[e[j].to]!=bel[i]) b[bel[i]]=0;
	mi=n+1;
	for (int i=1; i<=n; i++)
		if (bel[i]==i&&b[i])
			if (num[i]<mi) mi=num[i],mii=i;
	printf("%d\n",mi);
	for (int i=1; i<=n; i++) if (bel[i]==mii) printf("%d ",i); printf("\n");
	return 0;
}