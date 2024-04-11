#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct edge
{
	int v,w,nxt;
}e[2000005];
struct pt
{
	int val,id;
	pt(int val=0,int id=0):val(val),id(id){}
	bool operator<(const pt p) const
	{
		return val>p.val;
	}
};
priority_queue<pt> pq;
int n,m,deg[500005],h[500005],t;
int vis[500005],dis[500005];
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
int main()
{
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,1);
		add(v,u,-1);
		deg[u]++;
	}
	dis[n]=0;
	pq.push(pt(dis[n],n));
	while(!pq.empty())
	{
		while(!pq.empty()&&dis[pq.top().id]!=pq.top().val) pq.pop();
		if(pq.empty()) break;
		int u=pq.top().id;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(w==-1)
			{
				deg[v]--;
				if(dis[v]>dis[u]+1+deg[v])
				{
					dis[v]=dis[u]+1+deg[v];
					pq.push(pt(dis[v],v));
				}
			}
		}
	}
	printf("%d\n",dis[1]);
	return 0;
}