#include <bits/stdc++.h>

using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

const int N = 1e5 + 5;

int r, n, t[N], x[N], y[N], dp[N], mx[N];

int dist(int i, int j) {
	return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> n;
	for (int i = 0; i < n; i++) cin >> t[i] >> x[i] >> y[i];

	//(2i ^ i) = 3i - 2(2i & i)

	for (int i = 0; i < n; i++) {
		if (x[i] - 1 + y[i] - 1 <= t[i]) {
			dp[i] = 1;
		} else {
			if (i > 0) {
				mx[i] = mx[i - 1];
			}
			continue;
		}
		for (int j = i - 1; j >= 0; j--) {
			if (t[i] - t[j] > 1000) {
				if (mx[j]) {
					dp[i] = max(dp[i], 1 + mx[j]);
				}
				break;
			}
			if (dp[j] and dist(i, j) <= t[i] - t[j]) {
				dp[i] = max(dp[i], 1 + dp[j]);
			}
		}
		mx[i] = dp[i];
		if (i > 0) {
			mx[i] = max(mx[i], mx[i - 1]);
		}
	}

	cout << *max_element(dp, dp + n) << '\n';
	return 0;
}