#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 500 + 5;

int n, k, a[N], b[N];
bool dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	dp[0][0] = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (!dp[i][j]) continue;
			int rem = (a[i] + b[i]) % k;
			for (int cur_a = 0; cur_a < k; cur_a++) {
				if (cur_a <= a[i] && (rem + k - cur_a) % k <= b[i]) {
					dp[i + 1][(j + cur_a) % k] = true;
				}
			}
		}
	}

	ll sum_a = accumulate(a, a + n, 0ll), sum_b = accumulate(b, b + n, 0ll);
	ll ans = sum_a / k + sum_b / k;

	for (int j = 0; j < k; j++) {
		if (dp[n][j]) {
			ans = max(ans, (sum_a + sum_b - j) / k);
		}
	}
	cout << ans << '\n';
	return 0;
}