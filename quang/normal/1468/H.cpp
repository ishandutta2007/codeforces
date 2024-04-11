#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n, k, m;
		cin >> n >> k >> m;
		vector<int> a(m);
		set<int> s;
		for (int i = 1; i <=n; i++) {
			s.insert(i);
		}
		for (int &e : a) {
			cin >> e;
			s.erase(e);
		}

		if (s.size() % (k - 1) != 0) {
			cout << "NO\n";
			continue;
		}

		vector<int> b;
		for (int e : s) {
			b.push_back(e);
		}

		if (s.size() == 0) {
			cout << "YES\n";
			continue;
		}

		int lower = b[(k - 1) / 2 - 1];
		int upper = b[b.size() - (k - 1) / 2];

		int id = lower_bound(a.begin(), a.end(), lower) - a.begin();

		if (id == a.size() || a[id] >= upper) {
			cout << "NO\n";
			continue;
		} else cout << "YES\n";
	}


	return 0;
}