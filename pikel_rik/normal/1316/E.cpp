#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, p, k, a[N], s[N][7], pop[1 << 7];
ll dp[N][1 << 7], sum[N][1 << 7];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i < (1 << 7); i++) {
		pop[i] = __builtin_popcount(i);
	}

	cin >> n >> p >> k;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cin >> s[i][j];
		}
	}

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j) {
		return a[i] < a[j];
	});

	for (int j = 0; j < p; j++) {
		sum[0][1 << j] = s[ind[0]][j];
	}
	for (int i = 1; i < n; i++) {
		for (int mask = 0; mask < (1 << p); mask++) {
			sum[i][mask] = sum[i - 1][mask];
			for (int j = 0; j < p; j++) {
				if (mask & (1 << j)) {
					sum[i][mask] = max(sum[i][mask], s[ind[i]][j] + sum[i - 1][mask ^ (1 << j)]);
				}
			}
		}
	}

	int mx = (1 << p) - 1;

	for (int i = n - k - p; i < n; i++) {
		for (int mask = 0; mask < (1 << p); mask++) {
			if (n - i - 1 - pop[mx ^ mask] == k) {
				dp[i][mask] = sum[i][mask];
			} else if (n - i - 1 - pop[mx ^ mask] < k) {
				for (int j = 0; j < p; j++) {
					if (mask >> j & 1) {
						dp[i][mask] = max(dp[i][mask], s[ind[i]][j] + (i == 0 ? 0 : dp[i - 1][mask ^ (1 << j)]));
					}
				}
				dp[i][mask] = max(dp[i][mask], a[ind[i]] + (i == 0 ? 0 : dp[i - 1][mask]));
			}
		}
	}

	cout << dp[n - 1][mx] << '\n';
	return 0;
}