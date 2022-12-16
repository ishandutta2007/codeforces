#include <stdio.h>
#include <string.h>
#include <queue>
#define MN 200000
#define MM 300000
typedef long long LL;
int n,m,S,ans;
int d[MN+5],r[MN+5],rk=0,fa[MN+5][20],dep[MN+5],sz[MN+5];
int hd[MN+5],to[MM*2+5],val[MM*2+5],nxt[MM*2+5],rn;
LL dis[MN+5];
std::vector<int> v[MN+5];
struct edge{int u,v,w;}e[MM+5];
void add(int u,int v,int w){
	to[rn]=v,nxt[rn]=hd[u],val[rn]=w;
	hd[u]=rn++;
}
void dijkstra(int S){
	struct state{
		int u;LL d;
		state()=default;
		state(int _u){u=_u,d=dis[_u];}
		bool operator<(state b)const{return d>b.d;}
	};
	std::priority_queue<state> pq;
	memset(dis,0x7f,sizeof(dis));
	dis[S]=0; pq.push(state(S));
	while(!pq.empty()){
		int u=pq.top().u;
		LL d=pq.top().d;
		pq.pop();
		if(d!=dis[u]) continue;
		for(int i=hd[u];~i;i=nxt[i])
			if(d+val[i]<dis[to[i]]){
				dis[to[i]]=d+val[i];
				pq.push(state(to[i]));
			}
	}
}
void topo_sort(){
	std::queue<int> q;
	q.push(S);
	while(!q.empty()){
		int u=q.front(); q.pop();
		r[++rk]=u;
		for(int i=hd[u];~i;i=nxt[i])
			if((--d[to[i]])==0) q.push(to[i]);
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])
		std::swap(x,y);
	for(int i=19;i>=0;i--)
		if(dep[x]-dep[y]>=(1<<i))
			x=fa[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
void dominator_tree(){
	for(int rk=2;rk<=n;rk++){
		int i=r[rk];
		for(auto j:v[i]){
			if(fa[i][0]==0) fa[i][0]=j;
			else fa[i][0]=lca(fa[i][0],j);
		}
		dep[i]=dep[fa[i][0]]+1;
		for(int j=0;j<19;j++){
			if(fa[i][j]) fa[i][j+1]=fa[fa[i][j]][j];
			else break;
		}
	}
}
void dfs(int u){
	sz[u]=1;
	for(int i=hd[u];~i;i=nxt[i]){
		dfs(to[i]);
		sz[u]+=sz[to[i]];
	}
}
int main(){
	memset(hd,0xff,sizeof(hd)); rn=0;
	scanf("%d%d%d",&n,&m,&S);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		add(e[i].u,e[i].v,e[i].w);
		add(e[i].v,e[i].u,e[i].w);
	}
	dijkstra(S);
	memset(hd,0xff,sizeof(hd)); rn=0;
	for(int i=1;i<=m;i++){
		if(dis[e[i].v]-dis[e[i].u]==e[i].w){
			add(e[i].u,e[i].v,0),++d[e[i].v];
			v[e[i].v].push_back(e[i].u);
		}
		if(dis[e[i].u]-dis[e[i].v]==e[i].w){
			add(e[i].v,e[i].u,0),++d[e[i].u];
			v[e[i].u].push_back(e[i].v);
		}
	}
	topo_sort();
	dominator_tree();
	memset(hd,0xff,sizeof(hd)); rn=0;
	for(int i=1;i<=n;i++){
		if(i==S) continue;
		add(fa[i][0],i,0);
	}
	dfs(S);
	for(int i=hd[S];~i;i=nxt[i])
		ans=std::max(ans,sz[to[i]]);
	printf("%d\n",ans);
}