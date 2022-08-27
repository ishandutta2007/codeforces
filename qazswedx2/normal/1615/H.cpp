#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
#include<iostream>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
struct edge
{
	int v,nxt;
	int w;
}e[500005];
int n,m,val[100005],a[100005],b[100005],mx;
int f[105][105],g[105][105],mp[1005][1005],pre[1005][2];
int tans[1005],tot=1,h[1005],S,T,tvis[1005][2],qu[1000005],head,tail;
int dis[1005],vis[1005],cur[1005],viss[1005],vist[1005];
ull c[100005],d[100005],q[105];
ll ans;
void add2(int u,int v,int w)
{
//if(w<1e9&&w>1e6)	printf("add:u=%d,v=%d,w=%d\n",u,v,w);
//	if(w<1e9) printf("%d %d %d\n",u,v,w);
//	else printf("%d %d I\n",u,v);
	e[++tot].v=v;
	e[tot].w=w;
	e[tot].nxt=h[u];
	h[u]=tot;
	e[++tot].v=u;
	e[tot].w=0;
	e[tot].nxt=h[v];
	h[v]=tot;
}
int s[100005],s1[100005],s2[100005],st1,st2;
bool bfs(int l,int r)
{
	for(int i=l;i<=r;i++)
		vis[s[i]]=0;
	vis[T]=0;
	head=0,tail=1;
	dis[S]=0,vis[S]=1;
	qu[1]=S;
	while(head<tail)
	{
		head++;
		int u=qu[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(vis[v]||!w) continue;
			dis[v]=dis[u]+1;
			vis[v]=1;
			qu[++tail]=v;
		}
	}
	return vis[T];
}
int dfs(int u,int flow)
{
	if(u==T) return flow;
	ll ans=0,nw;
	for(int i=cur[u];i;i=e[i].nxt)
	{
		int v=e[i].v,w=e[i].w;
		if(ans==flow) return ans;
		cur[u]=i;
		if(dis[v]!=dis[u]+1||!w) continue;
		nw=dfs(v,min(flow-ans,(ll)w));
		ans+=nw;
		e[i].w-=nw;
		e[i^1].w+=nw;
	}
	return ans;
}
void dinic(int l,int r)
{
	while(bfs(l,r))
	{
	//	printf("---\n");
		for(int i=l;i<=r;i++)
			cur[s[i]]=h[s[i]];
		cur[S]=h[S],cur[T]=h[T];
		dfs(S,1e9);
	}
}
void bfss()
{
	head=0,tail=1;
	viss[S]=1;
	qu[1]=S;
	while(head<tail)
	{
		head++;
		int u=qu[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(viss[v]||!w) continue;
			viss[v]=1;
			qu[++tail]=v;
		}
	}
}
void bfst()
{
	head=0,tail=1;
	vist[T]=1;
	qu[1]=T;
	while(head<tail)
	{
		head++;
		int u=qu[head];
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i^1].w;
			if(vist[v]||!w) continue;
			vist[v]=1;
			qu[++tail]=v;
		}
	}
}
void solve(int l,int r,int tl,int tr)
{
	if(l>r) return;
/*	printf("solve:tl=%d,tr=%d\n",tl,tr);
	for(int i=l;i<=r;i++)
		printf("%d ",s[i]);
	printf("\n");*/
	if(tl==tr)
	{
		for(int i=l;i<=r;i++)
			tans[s[i]]=tl;
		return;
	}
	int tmid=(tl+tr)/2;
	tot=1;
	for(int i=l;i<=r;i++)
		h[s[i]]=0,viss[s[i]]=vist[s[i]]=0;
	h[S]=h[T]=0;
	viss[S]=vist[S]=0;
	viss[T]=vist[T]=0;
	for(int i=l;i<=r;i++)
		for(int j=l;j<=r;j++)
		{
			int u=s[i],v=s[j];
			if(mp[u][v])
				add2(u,v,2e9);
		}
	for(int i=l;i<=r;i++)
	{
		int nval=val[s[i]];
	//	int nw=1ll*(tmid+1-nval)*(tmid+1-nval)-1ll*(tmid-nval)*(tmid-nval);
	//	nw=-nw;
		int nw;
		if(nval<=tmid) nw=1;
		else nw=-1;
		nw=-nw;
		if(nw>0)
		{
			add2(S,s[i],nw);
			tvis[s[i]][0]=0;
			tvis[s[i]][1]=tot-1;
		}
		else
		{
			add2(s[i],T,-nw);
			tvis[s[i]][0]=1;
			tvis[s[i]][1]=tot-1;
		}
	}
	dinic(l,r);
	st1=st2=0;
	bfss();
	for(int i=2;i<=tot;i+=2)
	{
		int v=e[i].v,u=e[i^1].v;
		if(viss[u]&&!viss[v]&&e[i].w==0)
		{
		//	printf("u=%d,v=%d\n",u,v);
			if(u==S) vist[v]=1;
			if(v==T) vist[u]=1;
		/*	if(u!=S&&v!=T)
			{
				printf("ERROR\n");
			}*/
		}
	}
	for(int i=l;i<=r;i++)
		if(tvis[s[i]][0]^vist[s[i]]) s1[++st1]=s[i];
		else s2[++st2]=s[i];
	for(int i=l,j=1;j<=st1;i++,j++)
		s[i]=s1[j];
	for(int i=l+st1,j=1;j<=st2;i++,j++)
		s[i]=s2[j];
	int mid=l+st1-1;
	solve(l,mid,tl,tmid);
	solve(mid+1,r,tmid+1,tr);
}
int main()
{
	cin>>n>>m;
	S=n+1,T=n+2;
/*	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		ins(c[i]);
	}
	mx=0;
	for(int i=1;i<=n;i++)
	{
		cin>>val[i];
		mx=max(mx,val[i]);
	}
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	sort(a+1,a+m+1);
	sort(b+1,b+m+1);
	getans(a,0);
	getans(b,1);
	for(int i=1;i<=n;i++)
		mp[i][i]=0;*/
/*	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d",mp[i][j]);
		printf("\n");
	}*/
	for(int i=1;i<=n;i++)
		scanf("%d",&val[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		mp[u][v]=1;
	}
	for(int i=1;i<=n;i++)
		s[i]=i;
	solve(1,n,0,1e9);
/*	for(int i=1;i<=n;i++)
		printf("%d ",tans[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(mp[i][j]&&tans[i]>tans[j])
				printf("error on i=%d,j=%d\n",i,j);*/
	for(int i=1;i<=n;i++)
		printf("%d ",tans[i]);
	printf("\n");
	return 0;
}