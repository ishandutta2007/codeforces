#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int mod=998244353;
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
int fl;
struct value
{
	int v1,v2;
	value(int v1=0,int v2=0):v1(v1),v2(v2){}
	bool operator<(const value x) const
	{
		if(!fl||v1>60||x.v1>60)
		{
			if(v1!=x.v1) return v1<x.v1;
			return v2<x.v2;
		}
		return (1ll<<v1)+v2<(1ll<<x.v1)+x.v2;
	}
	bool operator!=(const value x) const
	{
		return ((*this)<x)||(x<(*this));
	}
	bool operator<=(const value x) const
	{
		return !(x<(*this));
	}
	value operator+(const value x) const
	{
		return value(x.v1+v1,x.v2+v2);
	}
};
struct pt
{
	int id,id2;
	value val;
	pt(int id=0,value val=0,int id2=0):id(id),val(val),id2(id2){}
	bool operator<(const pt x) const
	{
		return x.val<val;
	}
};
struct edge
{
	int v,nxt;
	value w;
}e[3000005];
int n,m,h[500005],t;
int vis[500005];
value dis[500005],dis2[500005][22];
priority_queue<pt> pq;
void add(int u,int v,value w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
#define id(x,y) (y*n+x)
void dij()
{
	for(int i=1;i<=n*2;i++)
		dis[i]=value(1e9,0);
	dis[1]=value(0,0);
	pq.push(pt(1,dis[1]));
	while(!pq.empty())
	{
		while(!pq.empty()&&pq.top().val!=dis[pq.top().id]) pq.pop();
		if(pq.empty()) break;
		int u=pq.top().id;
		pq.pop();
		vis[u]=1;
		//printf("u=%d\n",u);
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			value w=e[i].w;
			if(vis[v]||dis[v]<=dis[u]+w) continue;
		//	printf("u=%d,v=%d,dis=%d,%d,%d,%d\n",u,v,dis[v].v1,dis[v].v2,(dis[u]+w).v1,(dis[u]+w).v2);
			dis[v]=dis[u]+w;
			pq.push(pt(v,dis[v]));
		}
	}
}
void dij2()
{
//	memset(vis2,0,sizeof(vis2));
	for(int i=1;i<=n*2;i++)
		for(int j=0;j<=19;j++)
			dis2[i][j]=value(1e9,0);
	dis2[1][0]=value(0,0);
	pq.push(pt(1,dis2[1][0],0));
	while(!pq.empty())
	{
		while(!pq.empty()&&pq.top().val!=dis2[pq.top().id][pq.top().id2]) pq.pop();
		if(pq.empty()) break;
		int u=pq.top().id,u2=pq.top().id2;
		pq.pop();
	//	vis2[u]=1;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			value w=e[i].w;
			int vv2=(w+dis2[u][u2]).v1-dis[v].v1;
			if(vv2>19) continue;
		//	printf("u=%d,u2=%d,v=%d,vv2=%d,%d,%d\n",u,u2,v,vv2,(w+dis2[u][u2]).v1,dis[v].v1);
			if(dis2[v][vv2]<=dis2[u][u2]+w) continue;
			dis2[v][vv2]=dis2[u][u2]+w;
			pq.push(pt(v,dis2[v][vv2],vv2));
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(id(u,0),id(v,0),value(0,1));
		add(id(v,1),id(u,1),value(0,1));
	}
	for(int i=1;i<=n;i++)
	{
		add(id(i,0),id(i,1),value(1,0));
		add(id(i,1),id(i,0),value(1,0));
	}
	dij();
	fl=1;
	dij2();
/*	for(int i=1;i<=2*n;i++)
		printf("%d,%d ",dis[i].v1,dis[i].v2);
	printf("\n");*/
	value ans=value(1e9,0);
	for(int i=0;i<=19;i++)
	{
	//	printf("i=%d,dis2=%d,%d\n",i,dis2[n][i].v1,dis2[n][i].v2);
		if(dis2[n][i]<ans) ans=dis2[n][i];
		if(dis2[n*2][i]<ans) ans=dis2[n*2][i];
	}
	int tans=(1ll*fpow(2,ans.v1)+ans.v2-1+mod)%mod;
	printf("%d\n",tans);
	return 0;
}