#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

struct edge {
	int to, w;
	edge() {}
	edge(int tt, int ww) {
		to = tt;
		w = ww;
	}
};

int n, k;
vector<vector<edge>> g;
ll dp[2][500005];

void dfs(int v, int prev) {
	dp[0][v] = dp[1][v] = 0;
	vector<pair<ll, ll>> a;
	for (const auto &i : g[v])
		if (i.to != prev) {
			dfs(i.to, v);
			a.emplace_back(max(dp[0][i.to], dp[1][i.to]), dp[1][i.to] + i.w);
		}
	sort(a.begin(), a.end(), [](pair<ll, ll> &aa, pair<ll, ll> &bb) {
		return aa.second - aa.first > bb.second - bb.first;
	});
	for (int i = 0; i < a.size(); i++) {
		if (i < k)
			dp[0][v] += max(a[i].first, a[i].second);
		else
			dp[0][v] += a[i].first;

		if (i < k - 1)
			dp[1][v] += max(a[i].first, a[i].second);
		else
			dp[1][v] += a[i].first;
	}
	dp[0][v] = max(dp[0][v], dp[1][v]);
}

ll solve() {
	cin >> n >> k;
	g.clear();
	g.resize(n);
	for (int i = 0, u, v, w; i < n - 1; i++) {
		cin >> u >> v >> w;
		--u, --v;
		g[u].push_back(edge(v, w));
		g[v].push_back(edge(u, w));
	}
	dfs(0, -1);
	return max(dp[0][0], dp[1][0]);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst;
	cin >> tst;
	while (tst--) cout << solve() << '\n';
}