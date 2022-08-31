#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e6 + 5;

int dp[N], pref[N][10];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; i < 10; i++) dp[i] = i;
	for (int i = 10; i < N; i++) {
		int prod = 1;
		int temp = i;
		while (temp) {
			prod *= max(temp % 10, 1);
			temp /= 10;
		}
		dp[i] = dp[prod];
	}

	for (int d = 1; d < 10; d++) {
		for (int i = 1; i < N; i++) {
			pref[i][d] = (dp[i] == d) + pref[i - 1][d];
		}
	}

	int q;
	cin >> q;

	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;

		cout << pref[r][k] - pref[l - 1][k] << '\n';
	}
	return 0;
}