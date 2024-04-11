#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,nxt;
}e[2000005];
int T,n,m,h[500005],t,deg[500005],a[500005],q[500005],head,tail,vis[500005],pre[500005];
int dis[500005],tans[500005],tt,b[500005],c[500005];
void print()
{
	for(int i=1;i<=n;i++)
		c[i]=0;
	for(int i=1;i<=tt;i++)
		c[tans[i]]=1;
	/*printf("tans=");
	for(int i=1;i<=tt;i++)
		printf("%d ",tans[i]);
	printf("\n");*/
	printf("Yes\n%d\n",n-tt);
	for(int i=1;i<=n;i++)
		if(!c[i])
			printf("%d ",i);
	printf("\n");
}
void add(int u,int v)
{
	e[++t].v=v;
	e[t].nxt=h[u];
	h[u]=t;
}
void bfs()
{
	while(head<tail)
	{
		head++;
		int u=q[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(vis[v]) continue;
			a[v]=a[u];
			vis[v]=1;
			pre[v]=u;
			dis[v]=dis[u]+1;
			q[++tail]=v;
		}
	}
}
int solve(int rt)
{
	head=0,tail=1;
	vis[rt]=1,dis[rt]=0;
	q[1]=rt;
	pre[rt]=0;
	bfs();
	int mn=1e9,id=0;
	for(int i=1;i<=tail;i++)
	{
		int u=q[i];
		for(int j=h[u];j;j=e[j].nxt)
		{
			int v=e[j].v;
			if(pre[u]==v||pre[v]==u||pre[u]==-1||pre[v]==-1) continue;
			if(dis[u]+dis[v]<mn)
			{
				mn=dis[u]+dis[v];
				id=j;
			}
		}
	}
	if(!id) return 0;
	int u=e[id^1].v,v=e[id].v;
	/*printf("u=%d,v=%d\n",u,v);
	for(int i=1;i<=n;i++)
		printf("%d ",pre[i]);
	printf("\n");*/
	while(1)
	{
		if(dis[u]<dis[v]) swap(u,v);
		tans[++tt]=u;
		if(u==v) break;
		u=pre[u];
	}
	if(tt==n) return 0;
	else
	{
		print();
		return 1;
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n+1;i++)
			h[i]=deg[i]=vis[i]=pre[i]=0;
		t=1;
		tt=0;
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			deg[u]++,deg[v]++;
		}
		if(n==1)
		{
			printf("No\n");
			continue;
		}
		int ct=0,id=-1;
		for(int i=1;i<=n;i++)
		{
			if(deg[i]%3==0)
			{
				id=i;
				break;
			}
			if(deg[i]%3==1)
				ct++;
		}
		if(id!=-1)
		{
			tans[++tt]=id;
			print();
			continue;
		}
		if(ct>=2)
		{
			head=tail=0;
			for(int i=1;i<=n;i++)
				if(deg[i]%3==1)
				{
					q[++tail]=i;
					a[i]=i;
					vis[i]=1;
					dis[i]=0;
					pre[i]=0;
				}
			bfs();
			int mn=1e9,id=0;
			for(int i=2;i<=t;i+=2)
			{
				int u=e[i^1].v,v=e[i].v;
				if(a[u]!=a[v])
				{
					if(dis[u]+dis[v]<mn)
					{
						mn=dis[u]+dis[v];
						id=i;
					}
				}
			}
			int u=e[id^1].v,v=e[id].v;
			while(u)
			{
				tans[++tt]=u;
				u=pre[u];
			}
			while(v)
			{
				tans[++tt]=v;
				v=pre[v];
			}
			if(tt==n) printf("No\n");
			else print();
			continue;
		}
		if(ct==0)
		{
			if(!solve(1))
				printf("No\n");
			continue;
		}
		head=0,tail=1;
		int rt;
		for(int i=1;i<=n;i++)
			if(deg[i]%3==1)
				id=i;
		vis[id]=1;
		pre[id]=-1;
		for(int i=1;i<=n;i++)
			if(i!=id)
			{
				rt=i;
				break;
			}
		if(solve(rt)) continue;
		for(int i=0;i<=n+1;i++)
			vis[i]=0;
		vis[id]=1;
		int nww=0;
		for(int i=h[id];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(vis[v])
				continue;
			head=0,tail=1;
			q[1]=v;
			vis[v]=1;
			dis[v]=0;
			pre[v]=0;
			bfs();
			nww++;
			int ans=1e9,qq=0;
			for(int j=2;j<=tail;j++)
			{
				int u=q[j];
				for(int k=h[u];k;k=e[k].nxt)
				{
					int v=e[k].v;
					if(v==id)
					{
						if(dis[u]<ans)
						{
							ans=dis[u];
							qq=u;
						}
					}
				}
			}
			while(qq)
			{
				tans[++tt]=qq;
				qq=pre[qq];
			}
			if(nww==2) break;
		}
		tans[++tt]=id;
		if(nww<2||tt==n) printf("No\n");
		else print();
	}
	return 0;
}