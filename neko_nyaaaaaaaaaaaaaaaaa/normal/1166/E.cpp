#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int m, n; cin >> m >> n;
	vector<int> a[n+1];

	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		while (k--) {
			int x; cin >> x;
			a[x].push_back(i);
		}
	}

	set<pair<int, int>> s;
	for (int i = 1; i <= n; i++) {
		for (int j: a[i]) {
			for (int k: a[i]) {
				if (j == k) continue;
				pair<int, int> t = make_pair(min(j, k), max(j, k));
				s.insert(t);
			}
		}
	}

	cout << (s.size() == m*(m - 1)/2 ? "possible" : "impossible"); 

	return 0;
}