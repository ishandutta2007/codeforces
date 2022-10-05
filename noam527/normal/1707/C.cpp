#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

const int L = 18;
const int N = 100005;

int n, m;
vector<vector<int>> g;
vector<pair<int, int>> e;

int par[N];
int r[N];

int up[L][N];
int depth[N];
int st[N], en[N];
int tim = 0;

int sum[N];

int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

bool unite(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return false;
	if (r[x] < r[y]) {
		par[x] = y;
	}
	else {
		par[y] = x;
		if (r[x] == r[y]) r[x]++;
	}
	return true;
}

void dfs(int v, int prev, int d) {
	depth[v] = d;
	up[0][v] = prev;
	st[v] = tim++;
	for (const auto &i : g[v])
		if (i != prev)
			dfs(i, v, 1 + d);
	en[v] = tim++;
}

void prep() {
	for (int i = 1; i < L; i++) for (int j = 0; j < n; j++) {
		up[i][j] = up[i - 1][up[i - 1][j]];
	}
}

int jmp(int u, int j) {
	for (int i = 0; i < L; i++)
		if (j & (1 << i))
			u = up[i][u];
	return u;
}

void dfs2(int v, int prev) {
	for (const auto &i : g[v])
		if (i != prev) {
			sum[i] += sum[v];
			dfs2(i, v);
		}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) par[i] = i, r[i] = 0;
	g.resize(n);
	e.resize(m);
	for (auto &i : e) {
		cin >> i.first >> i.second;
		--i.first, --i.second;
	}
	vector<pair<int, int>> bad;
	for (auto &i : e) {
		if (unite(i.first, i.second)) {
			g[i.first].push_back(i.second);
			g[i.second].push_back(i.first);
		}
		else {
			bad.push_back(i);
		}
	}
	dfs(0, 0, 0);
	prep();
	for (auto &i : bad) {
		int u = i.first, v = i.second;
		if (depth[u] > depth[v]) swap(u, v);
		if (depth[u] < depth[v] && st[u] < st[v] && en[v] < en[u]) {
			// ancestor
			int below = jmp(v, depth[v] - depth[u] - 1);
			sum[0]++;
			sum[below]--;
			sum[v]++;
		}
		else {
			sum[u]++;
			sum[v]++;
		}
	}
	dfs2(0, 0);
	int need = bad.size();
	for (int i = 0; i < n; i++) {
		if (sum[i] == need) cout << 1;
		else cout << 0;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}