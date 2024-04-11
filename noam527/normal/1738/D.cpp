#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n;
vector<int> b;
vector<vector<int>> t;
vector<int> result;

void dfs(int v) {
	for (const auto &i : t[v]) {
		if (t[i].size() == 0)
			result.push_back(i);
	}
	for (const auto &i : t[v]) {
		if (t[i].size() > 0) {
			result.push_back(i);
			dfs(i);
		}
	}
}

void solve() {
	cin >> n;
	b.resize(n);
	for (auto &i : b) cin >> i;
	int mn = -1, mx = n + 1;
	for (int i = 0; i < n; i++) {
		mn = max(mn, min(i + 1, b[i]));
		mx = min(mx, max(i + 1, b[i]));
	}
	int k = mn;

	t.clear();
	t.resize(n + 2);
	for (int i = 0; i < n; i++) {
		t[b[i]].push_back(i + 1);
	}
	result.clear();
	if (t[0].size()) {
		dfs(0);
	}
	else {
		dfs(n + 1);
	}
	cout << k << '\n';
	for (const auto &i : result) cout << i << " "; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}