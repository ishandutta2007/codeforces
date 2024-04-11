#include <stdio.h>
#include <assert.h>
#include <vector>
#define MN 300000

using std::vector;

struct Edge{
	int v,cnt;
};

int m;
vector<int> bp;
vector<Edge> e[MN+5];

int c[MN+5],cnt[MN+5];
int ans[MN+5];

void dfs(int u,int f){
	cnt[u] = (c[u]==1);
	int* fcnt = nullptr;
	for(Edge& edge:e[u]){
		if(edge.v==f){
			fcnt = &edge.cnt;
			continue;
		}
		dfs(edge.v,u);
		edge.cnt = cnt[edge.v];
		cnt[u] += cnt[edge.v];
	}
	if(fcnt!=nullptr)
		*fcnt = m-cnt[u];
}

void spread(int u,int f){
	if(ans[u]) return;
	ans[u] = 1;
	for(Edge edge:e[u]){
		if(edge.v==f) continue;
		if(m-edge.cnt<2) continue;
		spread(edge.v,u);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]==1) m++;
	}
	for(int i=2;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back({v,0});
		e[v].push_back({u,0});
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		if(c[i]==1){
			ans[i] = 1;
			for(Edge edge:e[i]){
				spread(edge.v,i);
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i]," \n"[i==n]);
}