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

		vector<string> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		vector<pair<int, int>> ans;
		char ch1 = '0', ch2 = '1';
		for (int i = 0; i < 2; i++) {
			int c = 0;
			c += a[0][1] != ch1;
			c += a[1][0] != ch1;
			c += a[n - 2][n - 1] != ch2;
			c += a[n - 1][n - 2] != ch2;

			if (c <= 2) {
				if (a[0][1] != ch1) {
					ans.emplace_back(1, 2);
				}
				if (a[1][0] != ch1) {
					ans.emplace_back(2, 1);
				}
				if (a[n - 2][n - 1] != ch2) {
					ans.emplace_back(n - 1, n);
				}
				if (a[n - 1][n - 2] != ch2) {
					ans.emplace_back(n, n - 1);
				}
				break;
			}
			swap(ch1, ch2);
		}

		cout << ans.size() << '\n';
		for (auto &[i, j] : ans) cout << i << ' ' << j << '\n';
	}
	return 0;
}