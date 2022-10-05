#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m;
vector<vector<int>> g, t;
vector<int> dp;

void solve() {
	cin >> n >> m;
	g.clear(), t.clear();
	g.resize(n), t.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++) dp[i] = 0;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		t[v].push_back(u);
	}
	vector<int> close;
	for (int i = 0; i < n; i++) {
		for (const auto &j : t[i]) {
			if (dp[j] != -1) dp[i] = max(dp[i], 1 + dp[j]);
		}
		if (dp[i] >= 2) {
			dp[i] = -1;
			close.push_back(i);
		}
	}
	cout << close.size() << endl;
	for (const auto &i : close) cout << 1 + i << " "; cout << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst;
	cin >> tst;
	while (tst--) solve();
}