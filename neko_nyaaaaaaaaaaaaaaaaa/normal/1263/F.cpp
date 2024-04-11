#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

struct tree{
	int n;
	vector<int> adj[N];
	int lca[N][N];
	int depth[N];

	tree(int n) {
		this->n = n;
	}

	tree() {}

	void add_edge(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> dfs(int now, int prev, int dep) {
		depth[now] = dep;
		vector<int> nd(1, now);
		for (int u: adj[now]) {
			if (u != prev) {
				vector<int> nxt = dfs(u, now, dep + 1);
				for (int i: nxt) {
					for (int j: nd) {
						lca[i][j] = lca[j][i] = now;
					}
				}
				for (int i: nxt) {
					nd.push_back(i);
				}
			}
		}
		return nd;
	}

	void init() {
		dfs(1, 0, 0);
	}

	int LCA(int u, int v) {
		return lca[u][v];
	}

	int ext(int pr, int u) {
		if (pr == 0) return depth[u];
		return depth[u] - depth[LCA(pr, u)];
	}
};

tree t[2];
vector<int> gen[2];

int n, w; 

int dp[N][N][2];
// i: i-th device
// g: the previous device is from generator g
// j: the previous not-g device is j

int solve(int i, int j, int g) {
	if (i == n+1) return 0;
	if (dp[i][j][g] != -1) return dp[i][j][g];

	// get this generator into the g-th 
	int ans = solve(i+1, j, g) + t[g].ext(gen[g][i-1], gen[g][i]);

	// get this generator into the not-g-th
	ans = min(ans, solve(i+1, i-1, 1-g) + t[1-g].ext(gen[1-g][j], gen[1-g][i]));

	return dp[i][j][g] = ans;
}

signed main() {

	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < 2; i++) {
		int k; cin >> k; w += k-1;
		t[i] = tree(k);
		for (int j = 2; j <= k; j++) {
			int x; cin >> x;
			t[i].add_edge(x, j);
		}
		t[i].init();

		gen[i].resize(n+1);
		for (int j = 1; j <= n; j++) {
			cin >> gen[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	cout << w - solve(1, 0, 0) << '\n';
 
	return 0;
}