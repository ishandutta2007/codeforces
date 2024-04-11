#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first > b.first;
}

int solve(vector<pair<int, int>> a) {
	int n = a.size();
	sort(a.begin(), a.end(), cmp);

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(ans.begin(), ans.end(), a[i].second);
		if (it == ans.end()) ans.push_back(a[i].second);
		else *it = a[i].second;
	}
	return ans.size();
}

void solve() {
	int n, m; cin >> n >> m;
	vector<pair<int, int>> o, e;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			if (c == '1') {
				if ((i+j) % 2) o.emplace_back(i+j, i-j);
				else e.emplace_back(i+j, i-j);
			}
		}
	}

	cout << solve(o) + solve(e) << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}