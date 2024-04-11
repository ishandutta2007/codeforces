#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<vector<int>> a;
vector<int> dp;
vector<int> vis;

bool dfs(int v) {
	if (vis[v]) {
		if (vis[v] == 1) return true;
		return false;
	}
	vis[v] = 1;
	for (const auto &i : a[v]) {
		if (dfs(i))
			return true;
	}
	vis[v] = 2;
	return false;
}

int calc(int v) {
	if (dp[v] != -1) return dp[v];
	pair<int, int> mx = { -1, -1 };
	for (const auto &i : a[v]) {
		mx = max(mx, make_pair(calc(i), i));
	}
	if (mx.first == -1) dp[v] = 1;
	else if (mx.second < v) dp[v] = mx.first;
	else dp[v] = mx.first + 1;
	return dp[v];
}

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) i.clear();
	dp.resize(n);
	for (auto &i : dp) i = -1;
	vis.resize(n);
	for (auto &i : vis) i = 0;
	for (int i = 0; i < n; i++) {
		int l;
		cin >> l;
		a[i].resize(l);
		for (auto &j : a[i])
			cin >> j, --j;
	}
	for (int i = 0; i < n; i++) {
		if (dfs(i)) {
			cout << "-1\n";
			return;
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, calc(i));
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}