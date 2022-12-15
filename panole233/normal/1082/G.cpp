#include<bits/stdc++.h>
using namespace std;

const long long inf=1000000000000000ll;
struct node{int to,next; long long c;}e[1000001];
int n,m,q[3001],hd[3001],cnt,cur[3001],x,y,dis[3001],l,r;
long long ans,nw;

void addedge(int x,int y,long long v)
{
	e[++cnt]=(node){y,hd[x],v},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y],0},hd[y]=cnt;
}

bool bfs()
{
	for (int i=2; i<=n+m+2; i++) dis[i]=1000000000;
	q[l=r=1]=1,dis[1]=0;
	while (l<=r)
	{
		for (int i=hd[q[l]]; i; i=e[i].next)
			if (e[i].c&&dis[e[i].to]==1000000000)
				dis[e[i].to]=dis[q[l]]+1,q[++r]=e[i].to;
		l++;
	}
	return dis[n+m+2]!=1000000000;
}

long long dinic(int x,long long f)
{
	if (x==n+m+2) return f;
	for (int &i=cur[x]; i; i=e[i].next)
		if (e[i].c&&dis[e[i].to]==dis[x]+1)
		{
			long long nw=dinic(e[i].to,min(f,e[i].c));
			if (nw) return e[i].c-=nw,e[i^1].c+=nw,nw;
		}
	return 0;
}

int main()
{
	scanf("%d%d",&n,&m),cnt=1;
	memset(hd,0,sizeof(hd)),ans=0;
	for (int i=1; i<=n; i++) scanf("%lld",&nw),addedge(1,i+1,nw);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d",&x,&y,&nw);
		addedge(x+1,i+n+1,inf);
		addedge(y+1,i+n+1,inf);
		addedge(i+n+1,n+m+2,nw);
		ans+=nw;
	}
	while (bfs())
	{
		for (int i=1; i<=n+m+2; i++) cur[i]=hd[i];
		while (nw=dinic(1,inf)) ans-=nw;
	}
	printf("%lld\n",ans);
	return 0;
}