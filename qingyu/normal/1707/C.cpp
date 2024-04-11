#include <bits/stdc++.h>

using namespace std; // i don't like it anyway...

const int N = 2e5 + 50;
int f[N], fa[N], top[N], dep[N], siz[N], son[N], tot, s[N], dfn[N], id[N];
vector<int> G[N];
int n, m;

void dfs1(int x, int ffa, int d) {
	dep[x] = d;
	fa[x] = ffa;
	siz[x] = 1;
	int mxson = -1;
	for (int y : G[x]) {
		if (y != ffa) {
			dfs1(y, x, d + 1);
			siz[x] += siz[y];
			if (siz[y] > mxson) {
				mxson = siz[y];
				son[x] = y;
			}
		}
	}
}

void dfs2(int x, int topf) {
	top[x] = topf;
	dfn[x] = ++tot;
	id[dfn[x]] = x;
	if (son[x]) {
		dfs2(son[x], topf);
		for (int y : G[x])
			if (y != fa[x] && y != son[x])
				dfs2(y, y);
	}
}

void dfs3(int x) {
	for (int y : G[x])
		if (y != fa[x]) {
			s[y] += s[x];
			dfs3(y);
		}
}

int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return dep[x] < dep[y] ? x : y;
}

int find(int x) {
	while (x != f[x])
		x = f[x] = f[f[x]];
	return x;
}

bool merge(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		f[x] = y;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	iota(f, f + n + 1, 0);
	vector<pair<int, int>> sp;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		if (merge(x, y)) {
			G[x].push_back(y);
			G[y].push_back(x);
		}
		else {
			sp.emplace_back(x, y);
		}
	}
	dfs1(1, 0, 1), dfs2(1, 1);
	auto getp = [&](int x, int y) {
		while (top[x] != top[y]) {
			if (fa[top[x]] == y) return top[x];
			x = fa[top[x]];
		}
		return id[dfn[y] + 1];
	};
	for (auto [x, y] : sp) {
		int g = lca(x, y);
		if (x != g && y != g) {
			++s[x];
			++s[y];
		}
		else {
			if (dep[x] < dep[y]) swap(x, y);
			++s[x];
			++s[1];
			int t = getp(x, y);
			--s[t];
		}
	}
	dfs3(1);
	for (int i = 1; i <= n; ++i)
		cout << (s[i] == sp.size() ? '1' : '0');
	cout << '\n';
}