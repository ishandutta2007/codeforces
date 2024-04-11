#include <bits/stdc++.h>
using namespace std;

set<int> get_candidates(vector<int> a) {
	set<int> ans; int n = a.size();
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int d = a[j] - a[i];
			for (int k = 1; k*k <= d; k++) {
				if ((d % k) == 0) {
					ans.insert(-k);
					ans.insert(-d/k);
				}
			}
		}
	}
	return ans;
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	// case -1

	map<int, int> mp;
	for (int i: a) {
		mp[i]++;
		if (mp[i] >= n/2) {
			cout << "-1\n";
			return;
		}
	}

	// general

	vector<int> cnt(2000000);
	set<int> candidates = get_candidates(a);
	for (int kk: candidates) {
		int k = -kk;

		for (int i: a) {
			cnt[((i % k) + k) % k]++;
			if (cnt[((i % k) + k) % k] >= n/2) {
				cout << k << '\n';
				return;
			} 
		}

		for (int i: a) {
			cnt[((i % k) + k) % k]--;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}