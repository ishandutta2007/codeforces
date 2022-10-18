#include <bits/stdc++.h>
using namespace std;

void normalize(vector<int> &a, int n) {
	vector<pair<int, int>> p;
	for (int i = 0; i < n; i++) {
		p.emplace_back(a[i], i);
	}
	sort(p.begin(), p.end());

	for (int i = 0; i < n; i++) {
		a[p[i].second] = i;
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	normalize(a, n);

	vector<int> id(n);
	for (int i = 0; i < n; i++) {
		id[a[i]] = i;
	}

	// became permutation
	vector<pair<int, int>> ans;
	for (int ss = n-1; ss >= 0; ss--) {
		int cur = a[ss];
		while (cur != ss) {
			int ps = id[cur + 1];

			// swap positions ss and ps
			swap(id[cur], id[cur + 1]);
			swap(a[ss], a[ps]);
			ans.emplace_back(ss, ps);

			cur = a[ss];
		}
	}

	cout << ans.size() << '\n';
	for (auto [u, v]: ans) cout << min(u+1, v+1) << ' ' << max(u+1, v+1) << '\n';

	return 0;
}