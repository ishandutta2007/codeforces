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

	int q;
	cin >> q;

	while (q--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		sort(a.begin(), a.end());

		vector<vector<int>> dp(n, vector<int>(2 * n, -1));
		function<int(int, int)> recurse = [&] (int i, int t) -> int {
			if (i == n) {
				return 0;
			}
			if (t >= 2 * n) {
				return 1000000;
			}
			if (dp[i][t] != -1) {
				return dp[i][t];
			}
			return dp[i][t] = min(abs(t - a[i]) + recurse(i + 1, t + 1), recurse(i, t + 1));
		};
		cout << recurse(0, 1) << '\n';
	}
	return 0;
}