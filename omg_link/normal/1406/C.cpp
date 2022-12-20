#include <stdio.h>
#include <vector>
#define MN 100000

int n,target0,leaf0,leaf1;

std::vector<int> e[MN+5];

void add(int u,int v){
	e[u].push_back(v);
}

int getleaf(int u,int f){
	int ret = 1;
	for(auto to:e[u]){
		if(to==f) continue;
		ret += getleaf(to,u);
	}
	if(ret == 1){
		leaf0 = f;
		leaf1 = u;
	}
	return ret;
}

int dfs(int u,int f){
	int ret = 1;
	for(auto to:e[u]){
		if(to==f) continue;
		int a = dfs(to,u);
		if((a<<1)==n){
			target0 = u;
			getleaf(to,u);
		}
		ret += a;
	}
	return ret;
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=2,u,v;i<=n;i++){
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	target0 = -1;
	leaf0 = leaf1 = -1;
	dfs(1,0);
	if(target0==-1){
		printf("%d %d\n",1,e[1][0]);
		printf("%d %d\n",1,e[1][0]);
	}else{
		printf("%d %d\n",leaf0,leaf1);
		printf("%d %d\n",target0,leaf1);
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}