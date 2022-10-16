#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU {
	vector<int> P, S;
	DSU(int n) {
		P.resize(n+1);
		S.resize(n+1, 1);
		for (int i = 1; i <= n; i++) P[i] = i;
	}
	
	int find(int x) {
		if (x == P[x]) return x;
		return P[x] = find(P[x]);
	}
	
	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return 0;
		if (S[a] < S[b]) swap(a, b);
		
		S[a] += S[b];
		P[b] = a;
		return 1;
	}
	
	int same(int a, int b) {
		return find(a) == find(b);
	}
};

const int MAXN = 200005;

vector<int> adj[MAXN];

bool find_path(int now, int prv, int dest, vector<int> &path) {
	if (now == dest) {
		path.push_back(now);
		return 1;
	}

	for (auto u: adj[now]) {
		if (u != prv) {
			if (find_path(u, now, dest, path)) {
				path.push_back(now);
				return 1;
			}
		}
	}
	return 0;
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
	}

	vector<pair<int, int>> ed;
	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		ed.emplace_back(x, y);
	}
	
	string ans; DSU d(n);
	vector<pair<int, int>> nontr;
	vector<int> id;
	for (int i = 0; i < m; i++) {
		auto [u, v] = ed[i];
		if (!d.merge(u, v)) {
			ans.push_back('1');
			nontr.emplace_back(u, v);
			id.push_back(i);
		} else {
			adj[u].push_back(v);
			adj[v].push_back(u);
			ans.push_back('0');
		}
	}

	if (nontr.size() < 3) {
		cout << ans << '\n';
		return;
	}

	set<int> st;
	for (auto [u, v]: nontr) {
		st.insert(u);
		st.insert(v);
	}

	if (st.size() > 3) {
		cout << ans << '\n';
		return;
	}

	auto [uu, vv] = nontr[0];
	int eid = id[0];

	ans[eid] = '0';
	vector<int> sv;
	find_path(uu, uu, vv, sv);
	reverse(sv.begin(), sv.end());

	int e1 = sv[0], e2 = sv[1];
	for (int i = 0; i < m; i++) {
		auto [u, v] = ed[i];
		if (e1 == u && e2 == v) {
			ans[i] = '1';
		} else if (e2 == u && e1 == v) {
			ans[i] = '1';
		}
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}