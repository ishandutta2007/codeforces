#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
struct qt
{
	int x,fl;
	ll v;
	qt(int x=0,ll v=0,int fl=0):x(x),v(v),fl(fl){}
	bool operator<(const qt q) const
	{
		return x<q.x;
	}
}q[2000005];
struct edge
{
	int v,w,nxt;
};
struct pt
{
	int id;
	ll val;
	pt(int id=0,ll val=0):id(id),val(val){}
	bool operator<(const pt x) const
	{
		return val>x.val;
	}
};
int n,m,k,vis[200005],f[200005],g[200005],vise[200005],qq;
ll dis[200005],dis2[200005],qans[200005];
int st[200005],tp;
multiset<ll> mst;
priority_queue<pt> pq;
struct gr
{
	int h[200005],t,c[200005];
	edge e[500005];
	void add(int u,int v,int w)
	{
		e[++t].v=v;
		e[t].w=w;
		e[t].nxt=h[u];
		h[u]=t;
	}
	void dij(int s)
	{
		memset(dis,0x3f,sizeof(dis));
		memset(vis,0,sizeof(vis));
		dis[s]=0;
		pq.push(pt(s,dis[s]));
		while(!pq.empty())
		{
			while(!pq.empty()&&dis[pq.top().id]!=pq.top().val) pq.pop();
			if(pq.empty()) break;
			int u=pq.top().id;
			pq.pop();
			vis[u]=1;
			for(int i=h[u];i;i=e[i].nxt)
			{
				int v=e[i].v,w=e[i].w;
				if(dis[v]<=dis[u]+w||vis[v]) continue;
				dis[v]=dis[u]+w;
				f[v]=i;
				pq.push(pt(v,dis[v]));
			}
		}
	}
	void dfs(int u,int nwc)
	{
		c[u]=nwc;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(c[v]) continue;
			dfs(v,nwc);
		}
	}
}G[3];
int main()
{
	G[0].t=1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[0].add(u,v,w);
		G[0].add(v,u,w);
	}
	G[0].dij(n);
	memcpy(g,f,sizeof(g));
	memset(f,0,sizeof(f));
	memcpy(dis2,dis,sizeof(dis2));
	G[0].dij(1);
	int nw=n;
	while(nw)
	{
		st[++tp]=nw;
		nw=G[0].e[f[nw]^1].v;
	}
	for(int i=1;i<tp;i++)
	{
		g[st[i+1]]=f[st[i]]^1;
		vise[f[st[i]]/2]=i;
	}
	for(int i=2;i<=n;i++)
	{
		int u=G[0].e[f[i]^1].v,w=G[0].e[f[i]].w;
		G[1].add(u,i,w);
		G[1].add(i,u,w);
	//	printf("G1:u=%d,v=%d,w=%d\n",u,i,w);
	}
	for(int i=1;i<n;i++)
	{
		int u=G[0].e[g[i]^1].v,w=G[0].e[g[i]].w;
		G[2].add(u,i,w);
		G[2].add(i,u,w);
	//	printf("G2:u=%d,v=%d,w=%d,g=%d\n",u,i,w,g[i]);
	}
	for(int i=1;i<=tp;i++)
		G[1].c[st[i]]=G[2].c[st[i]]=i;
	for(int i=1;i<=tp;i++)
	{
		G[1].dfs(st[i],i);
		G[2].dfs(st[i],i);
	}
/*	printf("dis=");
	for(int i=1;i<=n;i++)
		printf("%lld ",dis[i]);
	printf("\n");
	printf("dis2=");
	for(int i=1;i<=n;i++)
		printf("%lld ",dis2[i]);
	printf("\n");
	for(int i=1;i<=tp;i++)
		printf("%d ",st[i]);
	printf("\n");*/
	for(int i=1;i<=m;i++)
		if(!vise[i])
		{
			int u=G[0].e[i*2].v,v=G[0].e[i*2+1].v,w=G[0].e[i*2].w;
			int l=G[1].c[u],r=G[2].c[v];
			ll ans;
			if(l>r)
			{
				ans=dis[u]+dis2[v]+w-dis[n];
			//	printf("i=%d,u=%d,v=%d,w=%d,l=%d,r=%d,ans=%d\n",i,u,v,w,l,r,ans);
				q[++qq]=qt(r,ans,1);
				q[++qq]=qt(l,ans,-1);
			}
			swap(u,v);
			l=G[1].c[u],r=G[2].c[v];
			if(l>r)
			{
				ans=dis[u]+dis2[v]+w-dis[n];
		//		printf("i=%d,u=%d,v=%d,w=%d,l=%d,r=%d,ans=%d\n",i,u,v,w,l,r,ans);
				q[++qq]=qt(r,ans,1);
				q[++qq]=qt(l,ans,-1);
			}
		}
	sort(q+1,q+qq+1);
	int nwq=1;
	for(int i=1;i<tp;i++)
	{
		while(nwq<=qq&&q[nwq].x==i)
		{
			if(q[nwq].fl==1) mst.insert(q[nwq].v);
			else mst.erase(mst.lower_bound(q[nwq].v));
			nwq++;
		}
		if(mst.empty()) qans[i]=1e18;
		else qans[i]=*mst.begin();
	//	printf("i=%d,qans=%d\n",i,qans[i]);
	}
	for(int i=1;i<=k;i++)
	{
		int x,val;
		scanf("%d%d",&x,&val);
		int u=G[0].e[x*2].v,v=G[0].e[x*2+1].v,w=G[0].e[x*2].w;
		if(w>=val) printf("%lld\n",min(dis[n],min(dis[u]+dis2[v],dis2[u]+dis[v])+val));
		else
		{
			if(!vise[x]) printf("%lld\n",dis[n]);
			else printf("%lld\n",min(dis[n]+qans[vise[x]],
								 min(dis[u]+dis2[v],dis2[u]+dis[v])+val));
		}
	}
	return 0;
}