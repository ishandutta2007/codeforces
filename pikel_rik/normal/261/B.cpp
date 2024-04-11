#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 50 + 5;

int n, a[N], p;
ld fact[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(9);

	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = i * fact[i - 1];
	}

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> p;

	if (accumulate(a, a + n, 0) <= p) {
		cout << n << '\n';
		return 0;
	}

	ld ans = 0;
	for (int i = 0; i < n; i++) {
		vector<vector<ll>> dp(n, vector<ll>(p + 1));
		dp[0][0] = 1;

		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			for (int k = n - 1; k >= 0; k--) {
				for (int sum = 0; sum <= p; sum++) {
					if (dp[k][sum] && sum + a[j] <= p) {
						dp[k + 1][sum + a[j]] += dp[k][sum];
					}
				}
			}
		}

		for (int k = 0; k < n; k++) {
			for (int sum = 0; sum <= p; sum++) {
				if (dp[k][sum] && sum + a[i] > p) {
					//k! * (n - k - 1)! / n! * k
					ans += dp[k][sum] * fact[k] * fact[n - k - 1] * k / fact[n];
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}