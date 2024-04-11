#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int n;
int cnt[N];
int mark[N];
int depth[N];
int jump[N][20];
vector < int > g[N];

void dfs(int u, int p = 0){
	jump[u][0] = p;
	for(int i = 1; i < 20; ++i){
		jump[u][i] = jump[jump[u][i - 1]][i - 1];
	}

	depth[u] = depth[p] + 1;

	cnt[u] = 0;

	for(int v : g[u]){
		if(v == p) continue;
		dfs(v, u);
		++cnt[u];
	}
}

int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);
	for(int i = 19; i >= 0; --i){
		if(depth[jump[u][i]] >= depth[v]) u = jump[u][i];
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; --i){
		if(jump[u][i] != jump[v][i]){
			u = jump[u][i];
			v = jump[v][i];
		}
	}
	return jump[u][0];
}

int dist(int u, int v){
	int p = lca(u, v);
	return depth[u] + depth[v] - depth[p] - depth[p];
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);

	int node = 0;
	for(int i = 1; i <= n; ++i){
		if(depth[i] > depth[node]) node = i;
	}

	dfs(node);

	int tail = 0;

	for(int i = 1; i <= n; ++i){
		if(depth[i] > depth[tail]) tail = i;
	}

	for(int x = tail; x != 0; x = jump[x][0]) mark[x] = 1;

	queue < int > f;

	long long tot = 0;
	vector < pair < int, int > > ans;

	for(int i = 1; i <= n; ++i){
		if(cnt[i] == 0 && !mark[i]) f.push(i);
	}

	while(!f.empty()){
		int x = f.front();
		f.pop();

		int t = node;
		if(dist(t, x) < dist(x, tail)) t = tail;

		ans.emplace_back(x, t);

		tot += dist(t, x);

		--cnt[jump[x][0]];
		if(cnt[jump[x][0]] == 0 && !mark[jump[x][0]]) f.push(jump[x][0]);
	}

	while(tail != node){
		ans.emplace_back(tail, node);
		tot += dist(tail, node);
		tail = jump[tail][0];
	}

	printf("%lld\n", tot);

	for(auto p : ans){
		printf("%d %d %d\n", p.first, p.second, p.first);
	}

	return 0;
}