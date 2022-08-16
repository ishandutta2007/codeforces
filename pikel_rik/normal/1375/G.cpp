#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, dp[2];
vector<int> g[N];

void dfs(int x, int p, int d) {
	dp[d]++;
	for (int i : g[x]) {
		if (i == p) continue;
		dfs(i, x, d ^ 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1, u, v; i < n; i++) {
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1, 0, 0);
	cout << min(dp[0], dp[1]) - 1 << '\n';
	return 0;
}