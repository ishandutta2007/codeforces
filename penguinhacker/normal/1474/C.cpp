#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[2000];
void solve() {
	cin >> n;
	for (int i = 0; i < 2 * n; ++i) cin >> a[i];
	sort(a, a + 2 * n);
	for (int i = 0; i < 2 * n - 1; ++i) {
		vector<pair<int, int>> ans;
		set<pair<int, int>> s;
		for (int j = 0; j < 2 * n - 1; ++j) if (i != j) {
			s.emplace(a[j], j);
			// cout << a[j] << " " << j << "\n";
		}
		ans.emplace_back(i, 2 * n - 1);
		int cur = a[2 * n - 1];
		for (int j = 1; j < n; ++j) {
			int x = s.rbegin()->second;
			// cout << a[x] << " " << cur - a[x] << "\n";
			s.erase(--s.end());
			auto it = s.lower_bound({cur - a[x], -1});
			if (it == s.end() || it->first != cur - a[x]) break;
			ans.emplace_back(x, it->second);
			s.erase(it);
			cur = a[x];
		}
		if (ans.size() == n) {
			cout << "YES\n" << a[i] + a[2 * n - 1] << "\n";
			for (pair<int, int> p : ans) cout << a[p.first] << " " << a[p.second] << "\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}