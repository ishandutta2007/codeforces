#include <stdio.h>
#include <algorithm>
#define MN 3000
typedef long long LL;

int n;
int fa[MN+5][MN+5],sz[MN+5][MN+5];
//[x][y] : x is point, y is root
LL ans,dp[MN+5][MN+5];

struct edge{
	int to;
	edge* next;
};
edge e[MN*2+5],*hd[MN+5];

void add(int u,int v){
	static int rn=0;
	e[rn].to = v;
	e[rn].next = hd[u];
	hd[u] = &e[rn];
	rn++;
}

void getInfo(int u,int f,int rt){
	fa[rt][u] = f;
	sz[rt][u] = 1;
	for(edge *e = hd[u] ; e != nullptr ; e = e->next){
		if(e->to == f) continue;
		getInfo(e->to,u,rt);
		sz[rt][u] += sz[rt][e->to];
	}
}

LL getDP(int u,int v){
	if(dp[u][v]) return dp[u][v];
	if(u == v) return 0;
	return dp[u][v] = sz[v][u]*sz[u][v] + std::max(getDP(fa[v][u],v),getDP(fa[u][v],u));
}

int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<=n-1;i++){
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	for(int i=1;i<=n;i++){
		getInfo(i,0,i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=std::max(ans,getDP(i,j));
		}
	}
	printf("%lld\n",ans);
}