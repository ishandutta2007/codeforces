#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<pair<pair<int, int>, pair<int, int>>> lec) {
	vector<tuple<int, int, int, int>> ev;
	for (int i = 0; i < n; i++) {
		int x = lec[i].first.first, u = lec[i].second.first, v = lec[i].second.second;
		ev.emplace_back(x, 0, u, v);
		x = lec[i].first.second, u = lec[i].second.first, v = lec[i].second.second;
		ev.emplace_back(x, 1, u, v);
	}
	sort(ev.begin(), ev.end());

	multiset<int> in, out;
	for (auto [x, op, u, v]: ev) {
		if (op == 0) {
			in.insert(u); out.insert(v);
		} else {
			in.erase(in.find(u)); out.erase(out.find(v));
		}

		if (in.empty()) continue;

		int mx_start = *in.rbegin();
		int mn_end = *out.begin();

		if (mx_start > mn_end) {
			return 1;
		}
	}
	return 0;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<pair<pair<int, int>, pair<int, int>>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first.first >> a[i].first.second;
		cin >> a[i].second.first >> a[i].second.second;
	}
	int ans = solve(n, a);
	for (int i = 0; i < n; i++) {
		swap(a[i].first, a[i].second);
	}
	ans |= solve(n, a);

	if (ans) cout << "NO\n";
	else cout << "YES\n";

	return 0;
}