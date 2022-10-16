#include <bits/stdc++.h>
using namespace std;

long long modpow(long long n, long long k, long long MOD);

#define int long long
const int MAXN = 150001;
const int M = 998244353;

struct johnwick_tree{
	int n;
	vector<long long> tree;
 
	johnwick_tree(int n) {
		this->n = n;
		tree.resize(n+1);
	}
 
	void update(int p, long long val){
		for (int i = p; i <= n; i += i & -i) {
			tree[i] += val;
		}
	}
 
	long long sum(int p) {
		if (p == 0) return 0;
		long long ans = 0;
		for (int i = p; i; i -= i & -i) {
			ans += tree[i];
		}
		return ans;
	}
} tr(MAXN+5);

int n, q;
vector<int> adj[MAXN];
vector<pair<int, int>> light_dads[MAXN];
vector<int> heavy_child(MAXN);

vector<int> subtr(MAXN, 1);
vector<int> tin(MAXN), tout(MAXN);

void dfs_light(int now, int prev, int par, int fi) {
	light_dads[now].emplace_back(par, fi);
	for (int u: adj[now]) {
		if (u != prev) dfs_light(u, now, par, fi);
	}
}

void dfs(int now, int prev, int &tm) {
	tin[now] = ++tm;
	int max_u = -1;
	for (int u: adj[now]) {
		if (u != prev) {
			dfs(u, now, tm);
			subtr[now] += subtr[u];

			if (max_u == -1 || subtr[u] > subtr[max_u]) {
				max_u = u;
			}
		}
	}
	tout[now] = tm;

	if (max_u == -1) return;

	for (int u: adj[now]) {
		if (u != prev) {
			if (u == max_u) {
				heavy_child[now] = u;
			} else {
				dfs_light(u, now, now, u);
			}
		}
	}
}

int invn;

vector<int> upd(MAXN);

void update(int v, int d) {
	upd[v] = (upd[v] + d) % M;
	
	int u = heavy_child[v];
	if (u) {
		int x = d*(n - subtr[u]) % M;
		tr.update(tin[u], x);
		tr.update(tout[u] + 1, -x);
	}

	if (v != 1) {
		int x = d*subtr[v] % M;
		tr.update(1, x);
		tr.update(n+1, -x);
		tr.update(tin[v], -x);
		tr.update(tout[v] + 1, x);
	}
}

int answer(int v) {
	int ans = tr.sum(tin[v]) % M;
	ans = (ans + n*upd[v]) % M;

	for (auto [u, fi]: light_dads[v]) {
		int x = (n - subtr[fi])*upd[u] % M;
		ans = (ans + x) % M;
	}

	return (ans*invn) % M;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	invn = modpow(n, M-2, M);
	for (int i = 1; i < n; i++) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int tm = 0;
	dfs(1, 0, tm);

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int v, d; cin >> v >> d;
			update(v, d);
		} else {
			int v; cin >> v;
			cout << answer(v) << '\n';
		}
	}

	return 0;
}

long long modpow(long long n, long long k, long long MOD) {
	long long ans = 1; n %= MOD;
	while (k > 0) {
		if (k & 1) ans = (ans*n) % MOD;
		k >>= 1; n = (n*n) % MOD;
	}
	return ans;
}