#include <bits/stdc++.h>
using namespace std;

const int MAX = 5000001;
bitset<MAX> has;
pair<int, int> gs[MAX];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	// find two numbers with
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int v = a[i] + a[j];

			if (!has[v]) {
				has[v] = 1;
				gs[v] = {i, j};
			} else {
				// already has
				if (i == gs[v].first || i == gs[v].second) continue;
				if (j == gs[v].first || j == gs[v].second) continue;

				cout << "YES\n";
				cout << gs[v].first+1 << ' ' << gs[v].second+1 << ' ' << i+1 << ' ' << j+1 << '\n';
				exit(0);
			}
		}
	}
	cout << "NO\n";

	return 0;
}