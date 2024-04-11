#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct SegmentTreeSum{
	long long it[N << 2];
	long long lazy[N << 3];

	#define mid ((l + r) >> 1)

	void Init(){
		memset(it, 0, sizeof it);
		memset(lazy, 0, sizeof lazy);
	}

	void push(int x, int l, int r){
		it[x] += lazy[x] * (r - l + 1);
		lazy[x + x] += lazy[x];
		lazy[x + x + 1] += lazy[x];
		lazy[x] = 0;
	}

	void update(int x, int l, int r, int u, int v, long long val){
		if(v < u) return;
		push(x, l, r);
		if(l > v || r < u) return;
		if(l >= u && r <= v){
			lazy[x] += val;
			push(x, l, r);
			return;
		}
		update(x + x, l, mid, u, v, val);
		update(x + x + 1, mid + 1, r, u, v, val);
		it[x] = it[x + x] + it[x + x + 1];	
	}

	void modify(int x, int l, int r, int pos, long long val){
		push(x, l, r);
		if(l > pos || r < pos) return;
		if(l == r) {
			it[x] = val;
			return;
		}
		modify(x + x, l, mid, pos, val);
		modify(x + x + 1, mid + 1, r, pos, val);
		it[x] = it[x + x] + it[x + x + 1];
	}


	long long query(int x, int l, int r, int u, int v){
		push(x, l, r);
		if(u > v) return 0;
		if(l > v || r < u) return 0;
		if(l >= u && r <= v) return it[x];
		long long ret = query(x + x, l, mid, u, v) + query(x + x + 1, mid + 1, r, u, v);
		it[x] = it[x + x] + it[x + x + 1];
		return ret;
	}
}smt;

int n, q, cnt;
int a[N];
int l[N];
int r[N];
int level[N];
int jump[N][20];
vector < int > g[N];

void dfs(int u, int p = 0){
	l[u] = ++cnt;
	level[u] = level[p] + 1;

	jump[u][0] = p;
	for(int i = 1; i < 20; ++i){
		jump[u][i] = jump[jump[u][i - 1]][i - 1];
	}

	for(int v : g[u]){
		if(v != p) dfs(v, u);
	}
	r[u] = cnt;
}

int lca(int u, int v){
	if(level[u] < level[v]) swap(u, v);
	for(int i = 19; i >= 0; --i){
		if(level[jump[u][i]] >= level[v]) u = jump[u][i];
	}
	if(u == v) return u;
	for(int i = 19; i >= 0; --i){
		if(jump[u][i] != jump[v][i]) {
			u = jump[u][i];
			v = jump[v][i];
		}
	}
	return jump[u][0];
}

int currentRoot = 1;

int dist(int u, int v){
	int p = lca(u, v);
	return level[u] + level[v] - level[p] * 2;
}

int calc(int u, int v, int x){
	return dist(u, x) + dist(v, x) + dist(currentRoot, x);
}

int lcaRoot(int u, int v){
	int x, ans = lca(u, v), now = calc(u, v, ans);

	if((x = calc(u, v, currentRoot)) < now) {
		now = x;
		ans = currentRoot;
	}

	if((x = calc(u, v, u)) < now){
		now = x;
		ans = u;
	}

	if((x = calc(u, v, v)) < now){
		now = x;
		ans = v;
	}

	int t;

	if((x = calc(u, v, t = lca(u, currentRoot))) < now){
		now = x;
		ans = t;
	}

	if((x = calc(u, v, t = lca(v, currentRoot))) < now){
		now = x;
		ans = t;
	}

	return ans;
}

int isPar(int u, int p){
	return (l[u] >= l[p] && r[u] <= r[p]);
}

int subtree(int x, int p){
	for(int i = 19; i >= 0; --i){
		if(level[jump[x][i]] > level[p]) x = jump[x][i];
	}
	return x;
}

long long solve(int x){
	return smt.query(1, 1, n, l[x], r[x]);
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &q);

	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}

	for(int i = 1; i < n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);

		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0);


	for(int i = 1; i <= n; ++i) {
		smt.modify(1, 1, n, l[i], a[i]);
	}


	while(q--){
		int t;
		scanf("%d", &t);
		if(t == 1){
			scanf("%d", &currentRoot);
			continue;
		}

		if(t == 3){
			int x;
			scanf("%d", &x);

			if(x == currentRoot){
				printf("%lld\n", solve(1));
				continue;
			}

			if(isPar(currentRoot, x)){
				printf("%lld\n", solve(1) - solve(subtree(currentRoot, x)));
			
			}
			else{
				printf("%lld\n", solve(x));
			}
			continue;
		}

		int u, v, val;
		scanf("%d%d%d", &u, &v, &val);

		int curr = lcaRoot(u, v);


		if(curr == currentRoot){
			smt.update(1, 1, n, 1, n, val);
			continue;
		}

		if(isPar(currentRoot, curr)){
			int x = subtree(currentRoot, curr);
			smt.update(1, 1, n, l[x], r[x], -val);
			smt.update(1, 1, n, 1, n, val);
		}
		else smt.update(1, 1, n, l[curr], r[curr], val);

	}

	return 0;
}