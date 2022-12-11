#include <stdio.h>
#include <stack>
#include <vector>

#define N 100010
#define MOD 1000000007

using namespace std;

vector<int> adj[N],next[N];
stack<int> topo;

int pass[N];
int arr[N];
int n,m;
int mn,cnt;

void dfs(int u) {
	if(pass[u]) return;
	pass[u] = 1;
	for(int i = 0;i < adj[u].size();i++) {
		dfs(adj[u][i]);
	}
	topo.push(u);
}
void dfs2(int u) {
	if(pass[u]) return;
	pass[u] = 1;
	if(arr[u] < mn) {
		mn = arr[u];
		cnt = 1;
	}else if(arr[u] == mn) {
		cnt++;
	}
	for(int i = 0;i < next[u].size();i++) {
		dfs2(next[u][i]);
	}
}
int main() {
	scanf("%d",&n);
	for(int i = 1;i<=n;i++) {
		scanf("%d",&arr[i]);
		pass[i] = 0;
	}
	scanf("%d",&m);
	for(int i = 0;i < m;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
	}
	for(int i = 1;i <= n;i++) {
		if(!pass[i]) {
			dfs(i);
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 0;j < adj[i].size();j++) {
			next[adj[i][j]].push_back(i);
		}
		pass[i] = 0;
	}
	long long ans = 0,ways = 1;
	while(!topo.empty()) {
		int t = topo.top();
		topo.pop();
		if(pass[t]) continue;
		mn = (-1u/2);
		cnt = 1;
		dfs2(t);
		ans += mn;
		ways = (ways * cnt)%MOD;
	}
	// output
	printf("%I64d %I64d\n",ans,ways);
	return 0;
}