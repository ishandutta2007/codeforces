#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

struct graph {
	struct edge {
		int u, v;
		edge(int u, int v): u(u), v(v) {}
	};

	int n, m;
	std::vector<edge> edges;
	std::vector<std::vector<int>> adj;

	graph(): n(), m() {}
	graph(int n, int m = 0): n(n), m(), adj(n) {
		edges.reserve(m);
	}

	int add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.emplace_back(u, v);
		return m++;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;

	graph g(n, m);
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		g.add_edge(--u, --v);
	}

	vector<int> c(n, -1);

	array<int, 2> cnt;
	auto dfs = [&](int x, const auto &self) -> void {
		cnt[c[x]]++;
		for (int i : g.adj[x]) {
			if (c[i] == -1) {
				c[i] = c[x] ^ 1;
				self(i, self);
			}
		}
	};

	vector<int> l;
	vector<array<int, 2>> szs;

	for (int i = 0; i < n; i++) {
		if (c[i] == -1) {
			l.push_back(i);
			cnt.fill(0);
			c[i] = 0;
			dfs(i, dfs);
			szs.push_back(cnt);
		}
	}

	for (const auto &e : g.edges) {
		if (c[e.u] == c[e.v]) {
			cout << "NO\n";
			return 0;
		}
	}

	vector<bitset<5001>> dp(n);

	dp[0].set(szs[0][0]);
	dp[0].set(szs[0][1]);

	for (int i = 1; i < l.size(); i++) {
		dp[i] = (dp[i - 1] << szs[i][0]) | (dp[i - 1] << szs[i][1]);
	}

	string ans(n, 0);
	auto mark = [&](int x, bool same, const auto &self) -> void {
		ans[x] = same ? '1' + c[x] : '1' + (c[x] ^ 1);
		for (int i : g.adj[x]) {
			if (ans[i] == 0) {
				self(i, same, self);
			}
		}
	};

	int cur = n2;
	for (int i = int(l.size()) - 1; i > 0; i--) {
		if (cur >= szs[i][0] && dp[i - 1][cur - szs[i][0]]) {
			mark(l[i], false, mark);
			cur -= szs[i][0];
		} else if (cur >= szs[i][1] && dp[i - 1][cur - szs[i][1]]) {
			mark(l[i], true, mark);
			cur -= szs[i][1];
		} else {
			cout << "NO\n";
			return 0;
		}
	}

	if (cur == szs[0][0]) {
		mark(l[0], false, mark);
	} else if (cur == szs[0][1]) {
		mark(l[0], true, mark);
	} else {
		cout << "NO\n";
		return 0;
	}

	for (int i = 0; n3; i++) {
		if (ans[i] == '1') {
			ans[i] = '3';
			n3--;
		}
	}

	cout << "YES\n" << ans << '\n';
	return 0;
}