#include <stdio.h>
#include <vector>

#define N 100010
#define PB push_back

using namespace std;

vector<int> adj[N],ans;

int dp[N][3];
int init[N],goal[N],swp[N];
int n;

void dfs(int u,int p,int a,int b) {
	if(swp[u] ^ a) {
		ans.PB(u);
		a ^= 1;
	}
	for(int i = 0 ; i < adj[u].size() ; i++) {
		int v = adj[u][i];
		if(v == p) continue;
		dfs(v,u,b,a);
	}
}
int main() {
	scanf("%d",&n);
	for(int i = 0;i < n-1;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].PB(v);
		adj[v].PB(u);
	}
	for(int i = 1; i <= n ;i++) {
		scanf("%d",&init[i]);
	}
	for(int i = 1; i <= n ;i++) {
		scanf("%d",&goal[i]);
	}
	for(int i = 1; i <= n ;i++) {
		swp[i] = init[i] ^ goal[i];
	}
	dfs(1,-1,0,0);
	printf("%d\n",ans.size());
	for(int i = 0 ; i < ans.size() ; i++) {
		printf("%d\n",ans[i]);
	}
	return 0;
}