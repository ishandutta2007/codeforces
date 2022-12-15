#include<bits/stdc++.h>
using namespace std;

const int inf=1000000000;
struct node{int to,next,c;}e[200001];
int n,m,h,l,r,c,ans,dis[3001],q[3001],hd[3001],cur[3001],tot,cnt,x;

void addedge(int x,int y,int c)
{
	e[++tot]=(node){y,hd[x],c},hd[x]=tot;
	e[++tot]=(node){x,hd[y],0},hd[y]=tot;
}

int calc(int x,int y) {return y*n+x+1;}

bool bfs()
{
	for (int i=2; i<=cnt; i++) dis[i]=inf;
	dis[1]=0,q[l=r=1]=1;
	while (l<=r)
	{
		for (int i=hd[q[l]]; i; i=e[i].next)
			if (e[i].c&&dis[e[i].to]==inf)
				dis[e[i].to]=dis[q[l]]+1,q[++r]=e[i].to;
		l++;
	}
	return dis[cnt]!=inf;
}

int dinic(int x,int f)
{
	if (x==cnt) return f;
	for (int &i=cur[x]; i; i=e[i].next)
		if (e[i].c&&dis[e[i].to]==dis[x]+1)
		{
			int nw=dinic(e[i].to,min(f,e[i].c));
			if (nw) return e[i].c-=nw,e[i^1].c+=nw,nw;
		}
	return 0;
}

int main()
{
	scanf("%d%d%d",&n,&h,&m),ans=n*h*h;
	tot=1,cnt=calc(n,h)+m+1;
	memset(hd,0,sizeof(hd));
	for (int i=1; i<=n; i++)
	{
		addedge(1,calc(i,0),inf);
		for (int j=1; j<=h; j++) addedge(calc(i,j-1),calc(i,j),h*h-(j-1)*(j-1));
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d%d",&l,&r,&x,&c);
		if (x>=h) continue;
		for (int j=l; j<=r; j++) addedge(calc(j,x+1),calc(n,h)+i,inf);
		addedge(calc(n,h)+i,cnt,c);
	}
	while (bfs())
	{
		for (int i=1; i<=cnt; i++) cur[i]=hd[i];
		while (c=dinic(1,inf)) ans-=c;
	}
	return printf("%d\n",ans),0;
}