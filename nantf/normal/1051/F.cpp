#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=111111;
struct edge{
	int u,v,w;
	bool operator<(const edge &e)const{return w<e.w;}
}mste[maxn];
int n,m,q,cnt,u_fa[maxn],imp[44];
int el1,head1[maxn],to1[maxn*2],w1[maxn*2],nxt1[maxn*2];
int el2,head2[maxn],to2[maxn*2],w2[maxn*2],nxt2[maxn*2];
int fa[maxn],son[maxn],sz[maxn],dep[maxn],top[maxn];
ll rtdis[maxn];
ll dis[44][maxn];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > pq;
inline void add1(int u,int v,int w){
	to1[++el1]=v;w1[el1]=w;nxt1[el1]=head1[u];head1[u]=el1;
}
inline void add2(int u,int v,int w){
	to2[++el2]=v;w2[el2]=w;nxt2[el2]=head2[u];head2[u]=el2;
}
int getfa(int x){
	return x==u_fa[x] ? x : u_fa[x]=getfa(u_fa[x]);
}
void kruskal(){
	for(int i=1;i<=n;i++) u_fa[i]=i;
	sort(mste+1,mste+m+1);
	for(int i=1;i<=m;i++){
		int u=mste[i].u,v=mste[i].v,w=mste[i].w;
		int uf=getfa(u),vf=getfa(v);
		if(uf==vf){
			imp[++cnt]=u;imp[++cnt]=v;
			continue;
		}
		add2(u,v,w);add2(v,u,w);
		u_fa[uf]=vf;
	}
}
void dijkstra(int s,int id){
	memset(dis[id],0x3f,sizeof(dis[id]));
	while(!pq.empty()) pq.pop();
	pq.push(make_pair(dis[id][s]=0,s));
	while(!pq.empty()){
		int u=pq.top().second;ll d=pq.top().first;pq.pop();
		if(d>dis[id][u]) continue;
		for(int i=head1[u];i;i=nxt1[i]){
			int v=to1[i];
			if(dis[id][v]>dis[id][u]+w1[i]) pq.push(make_pair(dis[id][v]=dis[id][u]+w1[i],v));
		}
	}
}
void dfs1(int u){
	sz[u]=1;
	for(int i=head2[u];i;i=nxt2[i]){
		int v=to2[i];
		if(v==fa[u]) continue;
		dep[v]=dep[fa[v]=u]+1;
		rtdis[v]=rtdis[u]+w2[i];
		dfs1(v);sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(!son[u]) return;
	dfs2(son[u],topf);
	for(int i=head2[u];i;i=nxt2[i]){
		int v=to2[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add1(u,v,w);add1(v,u,w);
		mste[i]=(edge){u,v,w};
	}
	kruskal();
	for(int i=1;i<=cnt;i++) dijkstra(imp[i],i);
	dfs1(1);dfs2(1,1);
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		int l=lca(u,v);
		ll ans=rtdis[u]+rtdis[v]-2*rtdis[l];
		for(int i=1;i<=cnt;i++) ans=min(ans,dis[i][u]+dis[i][v]);
		printf("%lld\n",ans);
	}
}