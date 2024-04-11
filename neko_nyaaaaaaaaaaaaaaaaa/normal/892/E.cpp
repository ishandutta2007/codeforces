#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> P, S;
	set<int> st;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}

	int find(int x) {
		while (x != P[x]) x = P[x];
		return x;
	}

	void reset() {
		for (int i: st) {
			P[i] = i;
			S[i] = 1;
		}
		st.clear();
	}

	void merge(int a, int b) {
		st.insert(a); st.insert(b);

		a = find(a); b = find(b);
		if (a == b) return;
		if (S[a] < S[b]) swap(a, b);

		S[a] += S[b];
		P[b] = a;
	}

	int same(int a, int b) {
		return find(a) == find(b);
	}
} d1(500005), d2(500005);

int n, m, q;
vector<tuple<int, int, int>> edge;
map<int, vector<tuple<int, int, int>>> queries;
map<int, vector<tuple<int, int>>> mst;
vector<int> ans(500005, 1);

void solve(vector<tuple<int, int, int>> &edges) {
	map<int, vector<tuple<int, int>>> tmp;
	for (auto &[i, x, y]: edges) {
		tmp[i].emplace_back(x, y);
	}

	for (auto &[i, e]: tmp) {
		d2.reset();

		for (auto &[x, y]: e) {
			x = d1.find(x); y = d1.find(y);

			if (d2.same(x, y)) {
				ans[i] = 0; break;
			}
			d2.merge(x, y);
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w; cin >> x >> y >> w;
		edge.emplace_back(w, x, y);
		mst[w].emplace_back(x, y);
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		int k; cin >> k;
		while (k--) {
			int u; cin >> u; u--;

			auto [w, x, y] = edge[u];
			queries[w].emplace_back(i, x, y);
		}
	}

	for (auto &[w, edges]: mst) {
		solve(queries[w]);

		for (auto &[x, y]: edges) {
			d1.merge(x, y);
		}
	}

	for (int i = 0; i < q; i++) {
		cout << (ans[i] ? "YES\n" : "NO\n");
	}

	return 0;
}