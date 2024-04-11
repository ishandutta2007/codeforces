#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
const int LOG = 12;
const int INF = 1e9;

int n;
int dp[2][N][N];

struct Tree {
	int n;
	vector<int> adj[N];
	int par[LOG][N], lv[N];
	int id[N];

	void dfsInit(int u, int p) {
		lv[u] = lv[p] + 1;
		par[0][u] = p;
		for (int i = 1; i < LOG; i++) par[i][u] = par[i - 1][par[i - 1][u]];
		for (int v : adj[u]) dfsInit(v, u);
	}

	void init() {
		cin >> n;
		for (int i = 2; i <= n; i++) {
			int u; cin >> u;
			adj[u].push_back(i);
		}
		for (int i = 1; i <= ::n; i++) cin >> id[i];
		dfsInit(1, 0);
	}

	int getPar(int u, int k) {
		for (int i = 0; i < LOG; i++) if (k >> i & 1) u = par[i][u];
			return u;
	}

	int lca(int u, int v) {
		if (lv[u] < lv[v]) swap(u, v);
		u = getPar(u, lv[u] - lv[v]);
		if (u == v) return u;
		for (int i = LOG - 1; i >= 0; i--) {
			if (par[i][u] != par[i][v]) {
				u = par[i][u];
				v = par[i][v];
			}
		}
		return par[0][u];
	}

	int getLen(int u, int v) {
		if (u == 0) return lv[id[v]] - 1;
		int w = lca(id[u], id[v]);
		return lv[id[v]] - lv[w];
	}
} t[2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	t[0].init();
	t[1].init();
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int id = 0; id < 2; id++) {
				dp[id][i][j] = INF;		
			}
		}
	}
	dp[0][0][0] = dp[1][0][0] = 0;
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j <= i; j++) {
			for (int id = 0; id < 2; id++) {
				if (dp[id][i][j] >= INF) continue;
				// same with id
				int len = t[id].getLen(i, i + 1);
				dp[id][i + 1][j] = min(dp[id][i + 1][j], dp[id][i][j] + len);
				// diff to id
				len = t[id ^ 1].getLen(j, i + 1);
				dp[id ^ 1][i + 1][i] = min(dp[id ^ 1][i + 1][i], dp[id][i][j] + len);
			}
		}
	}
	int res = INF;
	for (int i = 0; i <= n; i++) {
		res = min(res, dp[0][n][i]);
		res = min(res, dp[1][n][i]);
	}
	cout << t[0].n + t[1].n - 2 - res << endl;
	return 0;
}