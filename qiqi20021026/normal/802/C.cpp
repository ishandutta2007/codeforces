#include<bits/stdc++.h>

using namespace std;

#define N 300
#define INF 0x3f3f3f3f

int n,m,tot,S,T,head[N],a[N],c[N],pre[N],dist[N],pe[N],pf[N],pv[N],q[N*N];
bool vis[N];
struct edge{int v,l,c,rev,nxt;}e[N*N];

void add(int x,int y,int l,int c){
	e[++tot].v=y; e[tot].l=l; e[tot].c=c;
	e[tot].rev=tot+1; e[tot].nxt=head[x]; head[x]=tot;
	e[++tot].v=x; e[tot].l=-l; e[tot].c=0;
	e[tot].rev=tot-1; e[tot].nxt=head[y]; head[y]=tot;
}

int mcflow(int S,int T){
	int cost=0;
	while (1){
		memset(dist,0x3f,sizeof dist);
		memset(vis,0,sizeof vis);
		memset(pe,0,sizeof pe);
		memset(pf,0,sizeof pf);
		memset(pv,0,sizeof pv);
		int tt=0,ww=1; dist[S]=0; vis[S]=1; q[ww]=S; pf[S]=INF;
		while (tt<ww){
			int u=q[++tt]; vis[u]=0;
			for (int i=head[u],v;i;i=e[i].nxt)
				if (e[i].c&&dist[v=e[i].v]>dist[u]+e[i].l){
					dist[v]=dist[u]+e[i].l;
					pe[v]=i; pf[v]=min(pf[u],e[i].c); pv[v]=u;
					if (!vis[v]){vis[v]=1; q[++ww]=v;}
				}
		}
		if (dist[T]>=INF) break;
		int ff=pf[T];
		cost+=ff*dist[T];
		for (int u=T;u;u=pv[u]){
			e[pe[u]].c-=ff; e[e[pe[u]].rev].c+=ff;
		}
	}
	return cost;
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<=n;++i) scanf("%d",&c[i]);
	S=0; T=n*2+1;
	for (int i=1;i<n;++i) add(i,i+1,0,m-1);
	for (int i=1;i<=n;++i){
		add(S,i,c[a[i]],1);
		add(i,n+i,0,1);
		add(n+i,T,0,1);
		if (pre[a[i]]) add(i-1,n+pre[a[i]],-c[a[i]],1);
		pre[a[i]]=i;
	}
	printf("%d\n",mcflow(S,T));
	
	return 0;
}