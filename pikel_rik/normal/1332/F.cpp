#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 3e5 + 5;

int n;
ll dp[N][3];
vector<int> g[N];

void dfs(int x, int p) {
	dp[x][0] = dp[x][1] = dp[x][2] = 1;
	for (int i : g[x]) {
		if (i == p) continue;
		dfs(i, x);
		dp[x][0] = dp[x][0] * (2 * dp[i][0] + 2 * dp[i][1] + mod - dp[i][2]) % mod;
		dp[x][1] = dp[x][1] * (2 * dp[i][0] + dp[i][1] + mod - dp[i][2]) % mod;
		dp[x][2] = dp[x][2] * (dp[i][0] + dp[i][1] + mod - dp[i][2]) % mod;
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

	dfs(1, 0);
	cout << (dp[1][0] + dp[1][1] + mod - dp[1][2] - 1) % mod << '\n';
	return 0;
}