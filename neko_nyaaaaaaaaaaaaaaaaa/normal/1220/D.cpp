#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(int n, vector<long long> b, long long g) {
	// numbers should be in the form g + 2*k*g where k is non-negative
	vector<long long> ans;
	for (long long i: b) {
		if (i < g) {
			ans.push_back(i);
			continue;
		}
		long long sc = i;
		i -= g;
		if (i % (2*g)) ans.push_back(sc);
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<long long> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(b.begin(), b.end());

	vector<long long> ans = solve(n, b, 1);
	for (long long i = 1; i <= 60; i++) {
		vector<long long> tmp = solve(n, b, 1LL << i);
		if (tmp.size() < ans.size()) {
			swap(tmp, ans);
		}
	}
	cout << ans.size() << '\n';
	for (long long i: ans) cout << i << ' ';

	return 0;
}