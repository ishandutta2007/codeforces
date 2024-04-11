#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>

using namespace std;

typedef pair<int,int> pii;
#define N 600000
#define P(x,y) make_pair(x,y)

int n,x,y,tot,xb,cnt,head[N],a[N],f[N],fa[N],vis[N],g[N];
long long ans;
struct edge{int v,nxt;}e[N];

void add(int x,int y){
	e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;
}

int gfa(int x){return x==fa[x]?x:fa[x]=gfa(fa[x]);}

void merge(int x,int y){
	x=gfa(x); y=gfa(y);
	if (x!=y) fa[x]=y;
}

void dfs(int u,int fa){
	f[u]=0; a[0]=-1;
	int t=0;
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa){
			dfs(v,u);
			if (a[f[v]]>a[f[t]]) t=v;
		}
	if (!t){ans+=a[u]; f[u]=u; return;}
	bool fl=0;
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa)
			if (v!=t&&a[f[v]]==a[f[t]]){fl=1; break;}
	if (fl){
		for (int i=head[u],v;i;i=e[i].nxt)
			if ((v=e[i].v)!=fa) g[++xb]=f[v];
		int o=++cnt; a[o]=a[f[t]]; f[u]=o;
		if (a[u]<a[f[u]]){ans+=a[u]-a[f[u]]; f[u]=u;}
		else if (a[u]==a[f[u]]) merge(u,f[u]);
	}
	else{
		for (int i=head[u],v;i;i=e[i].nxt)
			if ((v=e[i].v)!=fa&&v!=t) g[++xb]=f[v];
		f[u]=f[t];
		if (a[u]<a[f[u]]){ans+=a[u]-a[f[u]]; f[u]=u;}
		else if (a[u]==a[f[u]]) merge(u,f[u]);
	}
}

int main(){
	scanf("%d",&n); cnt=n;
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	for (int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	for (int i=1;i<=n*2;++i) fa[i]=i;
	dfs(1,0);
	g[++xb]=f[1];
	for (int i=1;i<=xb;++i) vis[gfa(g[i])]=1;
	xb=0;
	for (int i=1;i<=n;++i) if (vis[gfa(i)]) g[++xb]=i;
	printf("%lld %d\n",ans,xb);
	for (int i=1;i<=xb;++i) printf(i==xb?"%d\n":"%d ",g[i]);
	
	return 0;
}