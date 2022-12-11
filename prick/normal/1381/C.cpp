#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define sz(x) ((int) (x).size())


void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<vector<int>> ids(n + 2);
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		ids[val].push_back(i);
	}
	int rest = -2;
	set<pair<int, int>> counts;
	for (int i = 1; i <= n + 1; ++i) {
		if (ids[i].empty()) {
			rest = i;
		} else {
			counts.insert({sz(ids[i]), i});
		}
	}
	vector<int> ans(n, -1);
	for (int it = 0; it < x; ++it) {
		auto p = *counts.rbegin();
		counts.erase(p);
		--p.first;
		int id = ids[p.second].back();
		ids[p.second].pop_back();
		ans[id] = p.second;
		if (p.first > 0) {
			counts.insert(p);
		}
	}
	vector<pair<int, int>> order;
	for (auto p: counts) {
		for (auto id: ids[p.second]) {
			order.emplace_back(id, p.second);
		}
	}
	reverse(order.begin(), order.end());
	int shift = 0;
	if (!counts.empty()) {
		shift = counts.rbegin()->first;
	}
	for (int i = 0; i < sz(order); ++i) {
		auto [id, value] = order[i];
		if (i < n - y) {
			ans[id] = rest;
			continue;
		}
		int res = order[(i + sz(order) - shift) % sz(order)].second;
		if (res == value) {
			cout << "NO\n";
			return;
		}
		ans[id] = res;
	}
	cout << "YES\n";
	for (auto i: ans) {
		cout << i << ' ';
	}
	cout << '\n';
}

signed main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}