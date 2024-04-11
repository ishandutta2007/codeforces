#include <bits/stdc++.h>

using namespace std;

const int N = 100010, LOG = 20;

int n, q;
int root = 1;
int b[N];
vector<int> a[N];
int lv[N], in[N], out[N], cnt = 0, pa[LOG][N];
int pos[N];

struct IT {
	long long sum[N << 2], e[N << 2];

	void init(int node, int l, int r) {
		e[node] = 0;
		if (l == r) {
			sum[node] = b[pos[l]];
			return;
		}
		int m = (l + r) >> 1;
		init(node << 1, l, m);
		init(node << 1 | 1, m + 1, r);
		sum[node] = sum[node << 1] + sum[node << 1 | 1];
	}

	void add(int node, int l, int r, int x, int y, long long val) {
		if (x > r || y < l) {
			return;
		}
		if (x <= l && r <= y) {
			sum[node] += val * (r - l + 1);
			e[node] += val;
			return;
		}
		int m = (l + r) >> 1;
		add(node << 1, l, m, x, y, val);
		add(node << 1 | 1, m + 1, r, x, y, val);
		sum[node] = sum[node << 1] + sum[node << 1 | 1] + e[node] * (r - l + 1); 
	}


	long long get(int node, int l, int r, int x, int y) {
		if (x > r || y < l) {
			return 0ll;
		}
		if (x <= l && r <= y) {
			return sum[node];
		}
		int m = (l + r) >> 1;
		long long p1 = get(node << 1, l, m, x, y);
		long long p2 = get(node << 1 | 1, m + 1, r, x, y);
		return p1 + p2 + e[node] * (min(r, y) - max(x, l) + 1);
	}
} it;

void dfs(int u, int p) {
	in[u] = ++cnt;
	pos[cnt] = u;
	pa[0][u] = p;
	lv[u] = lv[p] + 1;
	for (int i = 1; i < LOG; i++) {
		pa[i][u] = pa[i - 1][pa[i - 1][u]];
	}
	for (int v : a[u]) {
		if (v == p) {
			continue;
		}
		dfs(v, u);
	}
	out[u] = cnt;
}

bool checkChildren(int u, int v) {
	return in[v] <= in[u] && out[u] <= out[v];
}

int getPar(int u, int h) {
	for (int i = LOG - 1; i >= 0; i--) {
		if (h & (1 << i)) {
			u = pa[i][u];
		}
	}
	return u;
}

int lca(int u, int v) {
	if (lv[u] < lv[v]) {
		swap(u, v);
	}
	int h = lv[u] - lv[v];
	u = getPar(u, h);
	if (u == v) {
		return u;
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (pa[i][u] != pa[i][v]) {
			u = pa[i][u];
			v = pa[i][v];
		}
	}
	return pa[0][u];
}

long long getVal(int u, int root) {
	if (u == root) {
		return 0ll;
	}
	int h = lv[root] - lv[u] - 1;
	int v = getPar(root, h);
	return it.get(1, 1, n, in[v], out[v]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(1, 0);
	it.init(1, 1, n);
	while (q--) {
		int op;
		cin >> op;
		if (op == 1) {
			cin >> root;
		} else if (op == 2) {
			int u, v, x;
			cin >> u >> v >> x;
			int w = lca(u, v);
			// cerr << w << " " << u << " " << v << " " << root << endl;
			if (!checkChildren(root, w)) {
				it.add(1, 1, n, in[w], out[w], x);
			} else {
				it.add(1, 1, n, 1, n, x);
				int w1 = lca(root, u);
				int w2 = lca(root, v);
				w = (lv[w1] < lv[w2]) ? w2 : w1;
				if (w != root) {
					int h = lv[root] - lv[w] - 1;
					int z = getPar(root, h);
					it.add(1, 1, n, in[z], out[z], -x);
				}
			}
		} else {
			int u;
			cin >> u;
			if (!checkChildren(root, u)) {
				cout << it.get(1, 1, n, in[u], out[u]) << '\n';
			} else {
				cout << it.sum[1] - getVal(u, root) << '\n';
			}
		}
	}
	return 0;
}