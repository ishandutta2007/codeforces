#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
vector<ll> t, h;
vector<vector<int>> g;
ll dp[3][200005];

void dfs(int v, int pre) {
	
	for (const auto &i : g[v])
		if (i != pre)
			dfs(i, v);
	dp[0][v] = dp[1][v] = dp[2][v] = 0;

	// 0
	vector<ll> L, H;
	vector<pair<ll, ll>> E;
	for (const auto &i : g[v]) {
		if (i != pre) {
			if (h[i] < h[v])
				L.push_back(min(dp[0][i] + t[i], dp[1][i]));
			else if (h[i] > h[v])
				H.push_back(min(dp[0][i] + t[i], dp[2][i]));
			else {
				ll tmp = dp[0][i] + t[i];
				E.emplace_back(min(tmp, dp[1][i]), min(tmp, dp[2][i]));
			}
		}
	}
	sort(E.begin(), E.end(), [](const pair<ll, ll> &aa, const pair<ll, ll> &bb) {
		return aa.first - aa.second > bb.first - bb.second;
	});
	for (const auto &i : L) dp[0][v] += i;
	for (const auto &i : H) dp[0][v] += i;
	dp[1][v] = dp[2][v] = dp[0][v];
	ll init = dp[0][v];
	ll sum = 0;
	for (const auto &i : E) sum += i.first;

	ll tmp = sum;
	tmp += max((int)L.size() + (int)E.size(), (int)H.size()) * t[v];
	dp[0][v] = init + tmp;
	if ((int)L.size() + (int)E.size() > H.size())
		dp[1][v] = init + tmp;
	else
		dp[1][v] = init + tmp + t[v];
	if ((int)L.size() + (int)E.size() < H.size())
		dp[2][v] = init + tmp;
	else
		dp[2][v] = init + tmp + t[v];
	for (int i = 0; i < E.size(); i++) {
		sum += E[i].second - E[i].first;
		tmp = sum;
		int x = (int)L.size() + (int)E.size() - (i + 1), y = (int)H.size() + (i + 1);
		tmp += max(x, y) * t[v];
		dp[0][v] = min(dp[0][v], init + tmp);
		if (x > y)
			dp[1][v] = min(dp[1][v], init + tmp);
		else
			dp[1][v] = min(dp[1][v], init + tmp + t[v]);
		if (x < y)
			dp[2][v] = min(dp[2][v], init + tmp);
		else
			dp[2][v] = min(dp[2][v], init + tmp + t[v]);
	}
	if (OO) {
		cout << "v " << v << endl;
		cout << dp[0][v] << " " << dp[1][v] << " " << dp[2][v] << endl;
	}
}

void solve() {
	cin >> n;
	t.resize(n);
	h.resize(n);
	g.resize(n);
	for (auto &i : t) cin >> i;
	for (auto &i : h) cin >> i;
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 0);
	cout << min({ dp[0][0], dp[1][0], dp[2][0] }) << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}