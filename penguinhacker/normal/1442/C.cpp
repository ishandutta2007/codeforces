#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

// ar<int, 3> {distance, number changes, node}
// total distance = distance + (1 << number changes) - 1;

struct Comp {
	bool operator() (ar<int, 4> a, ar<int, 4> b) const {
		return make_pair(a[0], a[1]) > make_pair(b[0], b[1]);
	};
};

const int mxN = 200000, MOD = 998244353, INF = 1000000000;
int n, m;
vector<pair<int, int>> adj[mxN];
int dp[mxN][20];
bool vis[mxN][20];
ar<int, 2> dp2[mxN][2]; //changes, path
bool vis2[mxN][2];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		adj[a].emplace_back(b, 0);
		adj[b].emplace_back(a, 1);
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	priority_queue<ar<int, 3>, vector<ar<int, 3>>, greater<ar<int, 3>>> pq; //total distance, node, changes
	pq.push({0, 0, 0});
	while(!pq.empty()) {
		ar<int, 3> t = pq.top(); pq.pop();
		int u = t[1], c = t[2];
		if (vis[u][c]) continue;
		vis[u][c] = 1;
		for (auto& x : adj[u]) {
			int v = x.first, type = x.second;
			if ((c & 1) != type) { //do have to change
				if (c < 19 && dp[u][c] + 1 < dp[v][c + 1]) {
					dp[v][c + 1] = dp[u][c] + 1;
					pq.push({dp[v][c + 1] + (1 << (c + 1)) - 1, v, c + 1});
				}
			}
			else {
				if (dp[u][c] + 1 < dp[v][c] + 1) {
					dp[v][c] = dp[u][c] + 1;
					pq.push({dp[v][c] + (1 << c) - 1, v, c});
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < 20; ++i) {
		int cur = dp[n - 1][i] + (1 << i) - 1;
		ans = min(ans, cur);
	}
	if (ans < INF) {cout << ans; return 0;}

	for (int i = 0; i < n; ++i) dp2[i][0] = dp2[i][1] = {INF, INF};
	dp2[0][0] = {0, 0};
	priority_queue<ar<int, 4>, vector<ar<int, 4>>, Comp> pq2;
	pq2.push({0, 0, 0, 0});
	auto Consider = [&](int u, int par, int new_c, int new_d) {
		assert(new_c % 2 == par);
		if (ar<int, 2>{new_c, new_d} < dp2[u][par]) {
			dp2[u][par] = {new_c, new_d};
			pq2.push({new_c, new_d, u, par});
		}
	};
	while(!pq2.empty()) {
		ar<int, 4> te = pq2.top(); pq2.pop();
		int u = te[2], par = te[3];
		int c = te[0], d = te[1];
		if (vis2[u][par]) continue;
		vis2[u][par] = 1;
		for (auto x : adj[u]) {
			int v = x.first, type = x.second;
			if (par == type) { //no change
				Consider(v, par, c, d + 1);
			}
			else {
				Consider(v, par ^ 1, c + 1, d + 1);
			}
		}
	}
	ar<int, 2> x = min(dp2[n - 1][0], dp2[n - 1][1]);
	assert(x[0] >= 20);
	//cout << x[0] << " " << x[1] << "\n";
	ans = 1;
	for (int i = 0; i < x[0]; ++i) ans = ans * 2 % MOD;
	ans = (ans + x[1]) % MOD;
	ans = (ans + MOD - 1) % MOD;
	cout << ans;
	return 0;
}