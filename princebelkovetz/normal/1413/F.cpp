#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;
int n;
vector <vector <pair <int, int>>> g;

int far(int v) {
	vector <int> d(n + 1, -1);
	d[v] = 0;
	queue <int> q;
	q.push(v);
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		for (auto x : g[s]) {
			int u = x.first;
			if (d[u] == -1) {
				d[u] = d[s] + 1;
				q.push(u);
			}
		}
	}
	int id = 1;
	for (int i = 2; i <= n; ++i) {
		if (d[i] > d[id]) id = i;
	}
	return id;
}

void dfs(int v, int p, vector <int>& tin, vector <int>& tout, 
	vector <int>& d, vector <int>& h, vector <int>& e, int &timer) {
	tin[v] = timer++;
	e.push_back(v);
	for (auto x : g[v]) {
		int u = x.first, w = x.second;
		if (u == p) continue;
		d[u] = (d[v] + w) % 2;
		h[u] = h[v] + 1;
		dfs(u, v, tin, tout, d, h, e, timer);
	}
	tout[v] = timer;
}

struct segtree {
	int size;
	vector <vector <int>> tree;
	vector <int> modify;
	segtree(int n) {
		size = 1;
		while (size < n) size <<= 1;
		tree.resize(2 * size - 1, vector <int>(2));
		modify.resize(2 * size - 1);
	}
	void get(int v) {
		tree[v][0] = max(tree[2 * v + 1][0], tree[2 * v + 2][0]);
		tree[v][1] = max(tree[2 * v + 1][1], tree[2 * v + 2][1]);
	}
	void push(int v) {
		if (modify[v]) {
			modify[2 * v + 1] ^= 1;
			modify[2 * v + 2] ^= 1;
			swap(tree[2 * v + 1][0], tree[2 * v + 1][1]);
			swap(tree[2 * v + 2][0], tree[2 * v + 2][1]);
		}
		modify[v] = 0;
	}
	void upd(int v, int lx, int rx, int l, int h, int d) {
		if (lx + 1 == rx) {
			tree[v][d] = h;
			return;
		}
		int m = (lx + rx) / 2;
		if (l < m)
			upd(2 * v + 1, lx, m, l, h, d);
		else
			upd(2 * v + 2, m, rx, l, h, d);
		get(v);
	}
	void upd(int l, int h, int d) {
		upd(0, 0, size, l, h, d);
	}
	void rev(int v, int lx, int rx, int l, int r) {
		if (l <= lx and rx <= r) {
			modify[v] ^= 1;
			swap(tree[v][0], tree[v][1]);
			return;
		}
		if (rx <= l or r <= lx) {
			return;
		}
		push(v);
		int m = (lx + rx) / 2;
		rev(2 * v + 1, lx, m, l, r);
		rev(2 * v + 2, m, rx, l, r);
		get(v);
	}
	void rev(int l, int r) {
		rev(0, 0, size, l, r);
	}
	int ans() {
		return tree[0][0];
	}
};

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	g.resize(n + 1);
	vector <vector <int>> edges;
	for (int i = 0, u, v, w; i < n - 1; ++i) {
		cin >> u >> v >> w;
		g[u].push_back({ v, w });
		g[v].push_back({ u, w });
		edges.push_back({ u, v });
	}
	int S = far(1), T = far(S);
	vector <int> tin1(n + 1), tin2(n + 1), h1(n + 1), h2(n + 1), 
		tout1(n + 1), tout2(n + 1), d1(n + 1), d2(n + 1), e1, e2;
	int timer = 0;
	dfs(S, -1, tin1, tout1, d1, h1, e1, timer);
	timer = 0;
	dfs(T, -1, tin2, tout2, d2, h2, e2, timer);

	segtree ST1(n), ST2(n);
	for (int i = 0; i < n; ++i) {
		ST1.upd(i, h1[e1[i]], d1[e1[i]]);
		ST2.upd(i, h2[e2[i]], d2[e2[i]]);
	}
	int q; cin >> q;
	while (q --> 0) {
		int id; cin >> id;
		id--;
		int u = edges[id][0], v = edges[id][1];
		if (h1[u] > h1[v]) 
			ST1.rev(tin1[u], tout1[u]);
		else 
			ST1.rev(tin1[v], tout1[v]);
		if (h2[u] > h2[v])
			ST2.rev(tin2[u], tout2[u]);
		else
			ST2.rev(tin2[v], tout2[v]);
		cout << max(ST1.ans(), ST2.ans()) << '\n';
	}
	return 0;
}