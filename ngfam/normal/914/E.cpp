#include <bits/stdc++.h>

using namespace std;

const int N = 200020;
const int M = 1 << 20;

int n, current;

int l[N];
int r[N];
int sz[N];
int ver[N];
char inp[N];
int value[N];
vector < int > g[N];
vector < int > adj[N];

 
void preDfs(int u, int p = 0){
	l[u] = ++current;
	ver[current] = u;

	value[u] ^= (1 << (inp[u] - 'a'));
	for(int v : adj[u]){
		if(v == p) continue;
		g[u].push_back(v);
		value[v] = value[u];
		preDfs(v, u);
	}

	r[u] = current;
}

void dfsCnt(int u){
	sz[u] = 1;
	for(int i = 0; i < g[u].size(); ++i){
		int v = g[u][i];
		dfsCnt(v);
		sz[u] += sz[v];
		if(sz[v] > sz[g[u][0]]) swap(g[u][0], g[u][i]);
	}
}

int st[1 << 20];
int cnt[1 << 20];
long long ans[N];
long long lca[N];
long long sumUp[N];


void dfs(int u, bool keep){
	sumUp[u] = 2;

	sumUp[u] += st[value[u]];
	for(int i = 0; i < 20; ++i){
		int mask = value[u] ^ (1 << i);
		sumUp[u] += st[mask];
	}


	if(g[u].size() == 0){
		if(keep) ++cnt[value[u]];
		return;
	}

	++st[value[u] ^ (1 << (inp[u] - 'a'))];


	for(int i = 1; i < g[u].size(); ++i){
		int v = g[u][i];
		dfs(v, 0);
	}

	dfs(g[u][0], 1);

	
	

	for(int i = 1; i < g[u].size(); ++i){
		int v = g[u][i];

		for(int x = l[v]; x <= r[v]; ++x){
			int t = ver[x];

			int mask = value[t] ^ (1 << (inp[u] - 'a'));

		
			lca[u] += cnt[mask];
			sumUp[t] += cnt[mask];

			for(int i = 0; i < 20; ++i){
				int newmask = mask ^ (1 << i);
				sumUp[t] += cnt[newmask];
				lca[u] += cnt[newmask];
			}
		}
		
		for(int x = l[v]; x <= r[v]; ++x){
			int t = ver[x];
			++cnt[value[t]];
		}
	}


	int mask = value[u] ^ (1 << (inp[u] - 'a'));
	
	sumUp[u] += cnt[mask];
	lca[u] += cnt[mask];

	for(int i = 0; i < 20; ++i){
		int newmask = mask ^ (1 << i);
		lca[u] += cnt[newmask];
		sumUp[u] += cnt[newmask];
	}

	++cnt[value[u]];

	if(!keep){
		for(int x = l[u]; x <= r[u]; ++x){
			int t = ver[x];
			--cnt[value[t]];
		}
	}	

	--st[value[u] ^  (1 << (inp[u] - 'a'))];
}

int need[1 << 20];

void calc(int u, bool keep){
	if(keep) sumUp[u] += need[value[u]];

	if(g[u].size() == 0){
		return;
	}


	for(int i = g[u].size() - 1; i > 0; --i){
		int v = g[u][i];
		calc(v, 1);

		for(int x = l[v]; x <= r[v]; ++x){
			int t = ver[x];

			int mask = value[t] ^ (1 << (inp[u] - 'a'));	
			++need[mask];

			for(int i = 0; i < 20; ++i){
				int newmask = mask ^ (1 << i);
				++need[newmask];
			}
		}
	}

	calc(g[u][0], 1);

	for(int i = 1; i < g[u].size(); ++i){
		int v = g[u][i];

		for(int x = l[v]; x <= r[v]; ++x){
			int t = ver[x];

			int mask = value[t] ^ (1 << (inp[u] - 'a'));	
			--need[mask];

			for(int i = 0; i < 20; ++i){
				int newmask = mask ^ (1 << i);
				--need[newmask];
			}
		}
	}
}

void final(int x){
	long long tot = 0;
	for(int v : g[x]){
		final(v);
		sumUp[x] += sumUp[v];
		tot += lca[v];
	}

	ans[x] = sumUp[x] - 2 * tot - lca[x];
	lca[x] += tot;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);
	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	scanf("%s", inp + 1);

  int root = rand() % n + 1;

	preDfs(root);
	dfsCnt(root);

	dfs(root, 0);

	calc(root, 1);

for(int i = 1; i <= n; ++i){
		++lca[i];
	}


	final(root);

		for(int i = 1; i <= n; ++i){
		printf("%lld ", ans	[i]);
	}

	return 0;
}