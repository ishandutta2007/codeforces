#include <bits/stdc++.h>
using namespace std;

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

vector<pair<int, int>> adj[101][101];
bool vis[101][101];

void dfs(int x, int y, vector<pair<int, int>> &cc) {
	vis[x][y] = 1; cc.emplace_back(x, y);

	for (auto [nx, ny]: adj[x][y]) {
		if (vis[nx][ny]) continue;
		dfs(nx, ny, cc);
	}
}

bool is_tree(int n, vector<pair<int, int>> &cc) {
	if ((int)cc.size() != n-1) {
		return 0;
	} 

	DSU d(n);
	for (auto [u, v]: cc) {
		if (!d.merge(u, v)) {
			return 0;
		}
	}

	return 1;
}

int dist[101][101];

void dfstr(int now, int prv, int st, int ds, vector<vector<int>> &tr) {
	dist[st][now] = ds;
	for (int u: tr[now]) {
		if (u != prv) dfstr(u, now, st, ds+1, tr);
	}
}

bool checker(int n, vector<pair<int, int>> &cc, vector<tuple<int, int, int>> &triplets, vector<tuple<int, int, int>> &nontrips) {
	vector<vector<int>> tr(n);
	for (auto [u, v]: cc) {
		tr[u].push_back(v);
		tr[v].push_back(u);
	}

	for (int i = 0; i < n; i++) {
		dfstr(i, i, i, 0, tr);
	}

	for (auto [i, k, j]: triplets) {
		if (dist[i][k] != dist[j][k]) return 0;
	}
	for (auto [i, k, j]: nontrips) {
		if (dist[i][k] == dist[j][k]) return 0;
	}
	return 1;
}

void solve() {
	int n; cin >> n;
	vector<tuple<int, int, int>> triplets, nontrips;
	for (int i = 1; i <= n-1; i++) {
		for (int j = 1; j <= n-i; j++) {
			string s; cin >> s;
			for (int k = 1; k <= n; k++) {
				if (s[k-1] == '1') {
					// triplet: (i, k, i+j)
					triplets.emplace_back(i-1, k-1, i+j-1);
				} else {
					nontrips.emplace_back(i-1, k-1, i+j-1);
				}
			}
		}
	}

	// find connected components
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			adj[i][j].clear();
			vis[i][j] = 0;
		}
	}
	for (auto [i, k, j]: triplets) {
		if (i == k || k == j || i == j) {
			cout << "No\n";
			return;
		}

		pair<int, int> p1 = {i, k};
		pair<int, int> p2 = {k, j};
		if (p1.first > p1.second) swap(p1.first, p1.second); 
		if (p2.first > p2.second) swap(p2.first, p2.second); 

		adj[p1.first][p1.second].push_back(p2);
		adj[p2.first][p2.second].push_back(p1);
	}

	// yes
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (vis[i][j]) continue;

			vector<pair<int, int>> cc;
			dfs(i, j, cc);

			if (is_tree(n, cc) && checker(n, cc, triplets, nontrips)) {
				cout << "Yes\n";
				for (auto [u, v]: cc) {
					cout << u+1 << ' ' << v+1 << '\n';;
				}
				return;
			}
		}
	}

	// no
	cout << "No\n";
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}