#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,w,nxt;
}e[2000005];
struct pt
{
	int x,id,p;
	pt(int x=0,int id=0,int p=0):x(x),id(id),p(p){}
	bool operator<(const pt p) const
	{
		return x<p.x;
	}
}q[2000005];
int n,m,h[500005],t,e2[500005][4],f[500005][2],vis[500005],ct,tans[500005],qt;
int b[500005],bt;
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
/*void upd(int x,int y)
{
	if(e2[y][0]==e2[x][0]||e2[y][1]==e2[x][0])
		e2[y][2]=x,e2[y][3]=e2[x][0],e2[x][3]=1;
	else e2[y][2]=x,e2[y][3]=e2[x][1],e2[x][3]=0;
}*/
int getans(int x,int y)
{
	if(e2[y][0]==e2[x][0]||e2[y][0]==e2[x][1])
		return e2[y][0];
	return e2[y][1];
}
void dfs(int u,int fa)
{
	vis[u]=++ct;
	//printf("u=%d,fa=%d\n",u,fa);
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(vis[v])
		{
			if(vis[v]>vis[u]) continue;
			bt=1;
			b[1]=e[i].w;
			int nw=u;
			while(nw!=v)
			{
			//	printf("nw=%d\n",nw);
				b[++bt]=f[nw][1];
				nw=f[nw][0];
			}
			int mn=1e9,id=-1,mx=0,id2=-1;
			for(int i=1;i<=bt;i++)
				if(b[i]<mn)
				{
					mn=b[i];
					id=i;
				}
			for(int i=1;i<=bt;i++)
				if(b[i]>mx)
				{
					mx=b[i];
					id2=i;
				}
			int fl=1;
			for(int i=id;i!=id2;i=i%bt+1)
				if(b[i]>b[i%bt+1])
					fl=0;
			for(int i=id2;i!=id;i=i%bt+1)
				if(b[i]<b[i%bt+1])
					fl=0;
			if(fl)
			{
				//int nw=(id2==1?bt:id2-1);
				q[++qt]=pt(mx,mn,e2[mx][0]);
				q[++qt]=pt(mx,mn,e2[mx][1]);
				//q[++qt]=pt(nw,id,getans(nw,id2),1);
			//	printf("fl=%d,u=%d,v=%d,id=%d,id2=%d\n",fl,u,v,id,id2);
			}
			continue;
		}
		f[v][0]=u,f[v][1]=e[i].w;
		dfs(v,u);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,i);
		add(v,u,i);
		e2[i][0]=u,e2[i][1]=v;
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		tans[i]=1;
	sort(q+1,q+qt+1);
	int qnw=qt;
	for(int i=m;i>0;i--)
	{
		while(qnw&&q[qnw].x==i)
		{
			e2[q[qnw].id][2]+=tans[q[qnw].p];
			qnw--;
		}
		int nw=tans[e2[i][0]]+tans[e2[i][1]]-e2[i][2];
		tans[e2[i][0]]=nw;
		tans[e2[i][1]]=nw;
	/*	printf("i=%d,nw=%d\n",i,nw);
		for(int j=1;j<=n;j++)
			printf("%d ",tans[j]);
		printf("\n");*/
	}
	for(int i=1;i<=n;i++)
		printf("%d ",tans[i]-1);
	return 0;
}