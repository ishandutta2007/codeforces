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

		vector<int> a(n);
		vector<vector<int>> pos(n);

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			pos[--a[i]].push_back(i);
		}

		int ans = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (pos[i].empty()) continue;

			int now = (pos[i].front() != 0) + (pos[i].back() != n - 1);
			for (int j = 1; j < pos[i].size(); j++) {
				now += pos[i][j] != pos[i][j - 1] + 1;
			}
			ans = min(ans, now);
		}

		cout << ans << '\n';
	}
	return 0;
}