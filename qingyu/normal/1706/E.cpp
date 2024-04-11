#include <bits/stdc++.h>

using namespace std; // I don't like this anyway...

const int N = 3e5 + 50;

int f[N], fa[N], weight[N], dep[N], siz[N];
vector<int> G[N];

int find(int x) {
	while (x != f[x])
		x = f[x] = f[f[x]];
	return x;
}

bool unite(int x, int y, int e) {
	x = find(x);
	y = find(y);
	if (x == y)
		return false;
	if (siz[x] > siz[y]) swap(x, y);
	f[x] = y;
	fa[x] = y;
	G[y].emplace_back(x);
	weight[x] = e;
	siz[y] += siz[x];
	siz[x] = 0;
	return true;
}
void dfs(int x, int d) {
	dep[x] = d;
	for (auto y : G[x])
		dfs(y, d + 1);
}

int ans[N], g[N];
struct query_t {
	int l, r, id;
	query_t(int l, int r, int id) : l(l), r(r), id(id) {
	}
	bool operator<(const query_t &rhs) {
		return r < rhs.r;
	}
};

int calc(int x, int y) {
	int ans = -1;
	if (dep[x] < dep[y]) swap(x, y);
	while (dep[x] > dep[y]) {
		ans = max(ans, weight[x]);
		x = fa[x];
	}
	while (x != y) {
		ans = max(ans, max(weight[x], weight[y]));
		x = fa[x], y = fa[y];
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;
		for (int i = 0; i <= n; ++i) G[i].clear();
		iota(f, f + n + 1, 0);
		fill(siz, siz + n + 1, 1);
		fill(fa, fa + n + 1, 0);
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			unite(u, v, i + 1);	
		}
		int rt = find(1);
		dfs(rt, 0);
		vector<query_t> qu;
		for (int i = 0; i < q; ++i) {
			int l, r;
			cin >> l >> r;
			if (l == r) ans[i] = 0;
			else qu.emplace_back(l, r - 1, i);
		}
		sort(qu.begin(), qu.end());
		vector<pair<int, int>> stk;
		int p = 0;
		for (int i = 1; i < n; ++i) {
			g[i] = calc(i, i + 1);
			while (!stk.empty() && stk.back().second <= g[i]) stk.pop_back();
			stk.emplace_back(i, g[i]);
			while (p < qu.size() && qu[p].r <= i) {
				auto it = std::lower_bound(stk.begin(), stk.end(), std::make_pair(qu[p].l, -1));
				ans[qu[p].id] = it->second;
				++p;
			}
		}
		for (int i = 0; i < q; ++i)
			cout << ans[i] << " ";
		cout << "\n";
	}
}