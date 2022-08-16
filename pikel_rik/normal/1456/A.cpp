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
		int n, p, k;
		cin >> n >> p >> k;

		string a;
		cin >> a;

		int x, y;
		cin >> x >> y;

		vector<int> dp(n);

		for (int i = n - 1; i >= n - k; i--) {
			dp[i] = a[i] != '1';
		}

		for (int i = n - k - 1; i >= 0; i--) {
			dp[i] = (a[i] != '1') + dp[i + k];
		}

		int ans = INT_MAX;
		for (int i = p - 1; i < n; i++) {
			ans = min(ans, y * (i - p + 1) + x * dp[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}