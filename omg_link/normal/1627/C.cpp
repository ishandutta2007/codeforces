#include <stdio.h>
#include <algorithm>
#include <vector>
#define MN 100000

using std::sort;
using std::vector;

struct Edge{
	int v;
	int* col;
};

vector<Edge> e[MN+5];

int col[MN+5],id[MN+5];

void dfs(int u,int f,int type){
	for(Edge edge:e[u]){
		if(edge.v==f) continue;
		*(edge.col) = type;
		dfs(edge.v,u,type^1);
	}
}

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		id[i] = i;
	for(int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back({v,&col[i]});
		e[v].push_back({u,&col[i]});
	}
	sort(id+1,id+1+n,[](int a,int b)->bool{
		return e[a].size()<e[b].size();
	});
	if(e[id[n]].size()>2){
		puts("-1");
	}else{
		dfs(id[1],0,0);
		for(int i=1;i<=n-1;i++){
			printf("%d%c",col[i]?2:11," \n"[i==n-1]);
		}
	}
	for(int i=1;i<=n;i++)
		e[i].clear();
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}