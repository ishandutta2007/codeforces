#include<bits/stdc++.h>
using namespace std;

bool bo[100001][51],inst[100010],Bo[100001];
int n,m,d,hd[100001],cnt,bel[100001],dis[100001],gc[100001],f[100001][51],x,y,dfn[1000001],low[100001],sta[100001],tp,q[100001],l,r,D[100001],Hd[100001],fr[100001],ft[100001],Cnt[100001][51];
struct node{int to,next;}e[100001],E[100001];
char s[100001][51];

void Addedge(int x,int y)
{
	E[++cnt]=(node){y,Hd[x]};
	Hd[x]=cnt;
}

void addedge(int x,int y)
{
	e[++cnt]=(node){y,hd[x]};
	hd[x]=cnt;
}

void tarjan(int x)
{
	dfn[x]=low[x]=(++cnt); sta[++tp]=x,inst[x]=1;
	for (int i=hd[x]; i; i=e[i].next)
		if (!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if (inst[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	if (dfn[x]==low[x])
	{
		bel[x]=x,inst[x]=0;
		while (sta[tp]!=x) inst[sta[tp]]=0,bel[sta[tp]]=x,tp--;
		tp--;
	}
}

int nxt(int x) {return (x==d-1?0:x+1);}
int nxt(int x,int y) {return (x+y>=d?x+y-d:x+y);}

void dfs(int x,int t,int b)
{
	for (int i=hd[x]; i; i=e[i].next)
		if (bel[e[i].to]==b&&!bo[e[i].to][nxt(t)])
			bo[e[i].to][nxt(t)]=1,dfs(e[i].to,nxt(t),b);
}

void getd(int x)
{
	for (int i=Hd[x]; i; i=E[i].next)
	{
		if (!D[E[i].to]) getd(E[i].to);
		D[E[i].to]++;
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&d),cnt=0;
	memset(hd,0,sizeof(hd));
	for (int i=1; i<=m; i++) scanf("%d%d",&x,&y),addedge(x,y);
	for (int i=1; i<=n; i++) scanf("%s",s[i]);
	memset(dfn,0,sizeof(dfn)),cnt=0;
	memset(inst,0,sizeof(inst));
	for (int i=1; i<=n; i++) if (!dfn[i]) tp=0,tarjan(i);
	memset(bo,0,sizeof(bo));
	for (int i=1; i<=n; i++)
		if (bel[i]==i)
		{
			bo[i][0]=1;
			dfs(i,0,i);
			gc[i]=d;
			for (int j=1; j<d; j++) 
				if (bo[i][j]) {gc[i]=j; break;}
		}
	memset(Cnt,0,sizeof(Cnt));
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<d; j++) if (bo[i][j]) {dis[i]=j; break;}
		for (int j=0; j<d; j++) 
		{
			int Di=nxt(dis[i],j);
			for (int k=Di,bo=0; k!=Di||!bo; bo=1,k=nxt(k,gc[bel[i]]))
				if (s[i][k]=='1') {Cnt[bel[i]][j]++; break;}
		}
	}
	memset(bo,0,sizeof(bo));
	cnt=0;
	memset(Hd,0,sizeof(Hd));
	memset(f,0,sizeof(f));
	for (int i=1; i<=n; i++)
		for (int j=hd[i]; j; j=e[j].next)
			if (bel[e[j].to]!=bel[i]) Addedge(bel[i],bel[e[j].to]),fr[cnt]=i,ft[cnt]=e[j].to;
	D[bel[1]]=0,getd(bel[1]);
	q[l=r=1]=bel[1];
	f[bel[1]][(dis[1]?d-dis[1]:0)%gc[bel[1]]]=Cnt[bel[1]][(dis[1]?d-dis[1]:0)%gc[bel[1]]];
	bo[bel[1]][(dis[1]?d-dis[1]:0)%gc[bel[1]]]=1;
	while (l<=r)
	{
		x=q[l];
		for (int k=0; k<gc[x]; k++)
			for (int j=nxt(k,gc[x]); j!=k; j=nxt(j,gc[x]))
				bo[x][k]|=bo[x][j],f[x][k]=max(f[x][k],f[x][j]);
		for (int i=Hd[x]; i; i=E[i].next)
		{
			int Di=nxt(dis[fr[i]],d-dis[ft[i]]);
			for (int k=0; k<gc[x]; k++)
			{
				Di=nxt(Di);
				if (bo[x][k])
				{
					for (int j=Di,boo=0; !boo||j!=Di; boo=1,j=nxt(j,gc[x]))
						f[E[i].to][j]=max(f[E[i].to][j],f[x][k]+Cnt[E[i].to][j]),bo[E[i].to][j]=1;
				}
			}
			D[E[i].to]--;
			if (!D[E[i].to]) q[++r]=E[i].to;
		}
		l++;
	}
	int ans=0;
	for (int i=1; i<=n; i++)
		for (int j=0; j<d; j++) ans=max(ans,f[i][j]);
	printf("%d\n",ans);
	return 0;
}