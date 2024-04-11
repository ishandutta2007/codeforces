#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 1e12;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
vector<vector<int>> g;
vector<ll> w;

int dfs(int v, int prev) {
	int rtn = 1;
	for (const auto &i : g[v])
		if (i != prev)
			rtn = max(rtn, 1 + dfs(i, v));
	return rtn;
}

void calc(int v) {
	int mx[2] = { 0, 0 };
	for (const auto &i : g[v])
		if (w[i] == 0) {
			int tmp = dfs(i, v);
			if (tmp > mx[1]) {
				mx[0] = mx[1];
				mx[1] = tmp;
			}
			else if (tmp > mx[0]) {
				mx[0] = tmp;
			}
		}
	w[v] += mx[0] + mx[1];
}

void trim(int v) {
	w[v] = 0;
	int prev = v;
	v = g[v][0];
	while (g[v].size() == 2) {
		w[v] = 0;
		if (prev != g[v][0]) {
			prev = v;
			v = g[v][0];
		}
		else {
			prev = v;
			v = g[v][1];
		}
	}
}

void farthest(int v, int prev, ll d, ll &mx, int &node) {
	if (mx < d) {
		mx = d;
		node = v;
	}
	for (const auto &i : g[v])
		if (i != prev)
			farthest(i, v, d + w[i], mx, node);
}

void dfs2(int v, int prev, int d, int &mx, int &node) {
	if (mx < d) {
		mx = d;
		node = v;
	}
	for (const auto &i : g[v])
		if (i != prev)
			dfs2(i, v, 1 + d, mx, node);
}

pair<int, int> calc2(int v) {
	int M, X;
	ll mx[2] = { 0, 0 }, node[2] = { 0, 0 };
	for (const auto &i : g[v])
		if (w[i] == 0) {
			M = -1;
			dfs2(i, v, 1, M, X);
			if (M > mx[1]) {
				mx[0] = mx[1];
				node[0] = node[1];
				mx[1] = M;
				node[1] = X;
			}
			else if (M > mx[0]) {
				mx[0] = M;
				node[0] = X;
			}
		}
	return{ node[0], node[1] };
}

int wadj(int v) {
	int rtn = 0;
	for (const auto &i : g[v])
		if (w[i] != 0) rtn++;
	return rtn;
}

int main() {
	fast;
	cin >> n;
	g.resize(n);
	w.resize(n, 1);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++)
		if (g[i].size() == 1) trim(i);
	for (int i = 0; i < n; i++)
		if (w[i] > 0 && wadj(i) == 1) {
			calc(i);
		}
	for (auto &i : w)
		if (i > 0) i += inf;

	int u, v;
	ll mx;
	mx = -1;
	farthest(0, -1, w[0], mx, u);
	mx = -1;
	farthest(u, -1, w[u], mx, v);

	pair<int, int> A = calc2(u), B = calc2(v);
	cout << 1 + A.first << " " << 1 + B.first << endl;
	cout << 1 + A.second << " " << 1 + B.second << endl;
}