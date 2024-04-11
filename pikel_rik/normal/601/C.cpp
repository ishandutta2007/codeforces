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

	cout << fixed << setprecision(9);

	int n, m;
	cin >> n >> m;

	vector<int> x(n);
	for (int i = 0; i < n; i++) cin >> x[i], --x[i];

	if (m == 1) {
		cout << 1.0f << '\n';
		return 0;
	}

	vector<ld> dp(n * m), dp1(n * m);

	for (int j = 0; j < m; j++) {
		if (j != x[0]) {
			dp[j] = 1;
		}
	}

	int sum = x[0];
	for (int i = 1; i < n; i++) {
		sum += x[i];
		ld sliding_sum = 0;
		for (int j = 0; j < n * m; j++) {
			sliding_sum += dp[j];
			if (j - m >= 0) {
				sliding_sum -= dp[j - m];
			}
			if (j - x[i] >= 0) {
				dp1[j] = (sliding_sum - dp[j - x[i]]) / (m - 1);
			} else {
				dp1[j] = sliding_sum / (m - 1);
			}
		}
		dp.swap(dp1);
	}

	ld ans = 1;
	for (int j = 0; j < sum; j++) {
		ans += dp[j];
	}
	cout << ans << '\n';
	return 0;
}