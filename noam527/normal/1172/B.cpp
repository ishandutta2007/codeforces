#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 1e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

ll f[200005];
int n;
vector<vector<int>> g;
ll dp[200005][2];

void dfs(int v, int prev) {
	int cnt = 0;
	dp[v][0] = dp[v][1] = 1;
	for (const auto &i : g[v])
		if (i != prev) {
			cnt++;
			dfs(i, v);
			dp[v][0] = dp[v][0] * dp[i][1] % md;
			dp[v][1] = dp[v][1] * dp[i][1] % md;
		}
	dp[v][0] = dp[v][0] * f[cnt] % md;
	dp[v][1] = dp[v][1] * f[cnt + 1] % md;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	f[0] = f[1] = 1;
	for (int i = 2; i < 200005; i++)
		f[i] = f[i - 1] * i % md;
	cin >> n;
	g.resize(n);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 0);
	ll ans = dp[0][0] * n % md;
	finish(ans);
}