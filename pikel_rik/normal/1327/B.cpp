#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> a(n);
		for (int i = 0, k; i < n; i++) {
			cin >> k;
			a[i].resize(k);
			for (int j = 0; j < k; j++) {
				cin >> a[i][j]; --a[i][j];
			}
		}

		vector<bool> visited(n);
		int not_ok = -1;
		for (int i = 0; i < n; i++) {
			bool ok = false;
			for (int j = 0; j < a[i].size(); j++) {
				if (!visited[a[i][j]]) {
					visited[a[i][j]] = true;
					ok = true;
					break;
				}
			}
			if (!ok) {
				not_ok = i;
			}
		}

		if (not_ok == -1) {
			cout << "OPTIMAL\n";
		} else {
			cout << "IMPROVE\n";
			for (int i = 0; i < n; i++) {
				if (!visited[i]) {
					cout << not_ok + 1 << ' ' << i + 1 << '\n';
					break;
				}
			}
		}
	}
	return 0;
}