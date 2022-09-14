#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (ll i = 0; i < (n); i++)
 
typedef long long ll;
typedef long double ld;
using namespace std;

const int N = 300001;
ll ans = 0;
vector<pair<ll, ll>> g[N];
ll ww[N], dp[N];

void dfs(int v, int p) {
	ll cm = 0;
	ans = max(ans, ww[v]);
	for (auto &w : g[v]) {
		int u = w.first;
		if (u == p)
			continue;
		dfs(u, v);
		dp[v] = max(dp[v], dp[u] - w.second);
		ans = max(ans, ww[v] + cm + dp[u] - w.second);
		cm = max(cm, dp[u] - w.second);
	}
	dp[v] += ww[v];
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, u, v, c;
	cin >> n;
	rep(i, n)
		cin >> ww[i];
	rep(i, n - 1) {
		cin >> u >> v >> c;
		u--; v--;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	dfs(0, -1);
	cout << ans;
}