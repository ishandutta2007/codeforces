#include<bits/stdc++.h>
using namespace std;

const int inf=1000000000;
int n,m,ans,d[110],x,y,c,f;

namespace Flow
{
	bool inq[110];
	int hd[110],n,cnt,q[200010],l,r,dis[110],la[110],x,mi,nw;
	struct node{int to,next,c,val;}e[2010];
	void addedge(int x,int y,int c,int val)
	{
		e[++cnt]=(node){y,hd[x],c,val},hd[x]=cnt;
		e[++cnt]=(node){x,hd[y],0,-val},hd[y]=cnt;
	}
	int solve()
	{
		int ans=0;
		while (1)
		{
			q[l=r=1]=1,dis[1]=0,inq[1]=1,la[1]=0;
			for (int i=2; i<=n; i++) dis[i]=inf,inq[i]=0;
			while (l<=r)
			{
				x=q[l++],inq[x]=0;
				for (int i=hd[x]; i; i=e[i].next)
					if (e[i].c>0&&dis[e[i].to]>dis[x]+e[i].val) 
					{
						dis[e[i].to]=dis[x]+e[i].val,la[e[i].to]=i;
						if (!inq[e[i].to]) inq[e[i].to]=1,q[++r]=e[i].to;
					}
			}
			if (dis[n]==inf) return ans;
			x=n,mi=inf,nw=0;
			while (x!=1) nw+=e[la[x]].val,mi=min(e[la[x]].c,mi),x=e[la[x]^1].to;
			ans+=nw*mi,x=n;
			while (x!=1) e[la[x]].c-=mi,e[la[x]^1].c+=mi,x=e[la[x]^1].to;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m),ans=0;
	Flow::n=n+2,Flow::cnt=1,Flow::addedge(2,n+1,inf,0),Flow::addedge(n+1,2,inf,0);
	while (m--)
	{
		scanf("%d%d%d%d",&x,&y,&c,&f),d[x]+=f,d[y]-=f,x++,y++;
		if (c<f) Flow::addedge(y,x,f-c,0),Flow::addedge(y,x,c,1),Flow::addedge(x,y,inf,2),ans+=f-c;
		else Flow::addedge(x,y,c-f,1),Flow::addedge(x,y,inf,2),Flow::addedge(y,x,f,1);
	}
	for (int i=1; i<=n; i++)
		if (d[i]>0) Flow::addedge(i+1,n+2,d[i],0);
		else if (d[i]<0) Flow::addedge(1,i+1,-d[i],0);
	printf("%d\n",ans+Flow::solve());
	return 0;
}