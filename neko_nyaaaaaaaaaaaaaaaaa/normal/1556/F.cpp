#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9+7;

int modpow(int n, int k) {
	int ans = 1; n %= M;
	while (k) {
		if (k % 2) ans = (ans*n) % M;
		n = (n*n) % M; k /= 2;
	}
	return ans;
}

int n, a[14], win[14][14], winm[1 << 14][14], dp[1 << 14];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (n == 1) {
		cout << "1\n";
		exit(0);
	}

	for (int j = 0; j < n; j++) {
		for (int k = 0; k < n; k++) {
			if (j != k) win[j][k] = a[j]*modpow(a[j] + a[k], M-2) % M;
		}
	}

	for (int j = 0; j < (1 << n); j++) {
		for (int k = 0; k < n; k++) {
			if (j & (1 << k)) continue;

			// entire set j beats k
			int tmp = 1;
			for (int x = 0; x < n; x++) {
				if (j & (1 << x)) {
					// x beats k
					tmp = (tmp * win[x][k]) % M;
				}
			}
			winm[j][k] = tmp;
		}
	}

	int ans = 0;
	for (int i = 1; i < (1 << n); i++) {
		int tmp = 0;
		for (int x = i; x; ) {
			--x &= i;

			int comp = i ^ x;
			int g = 1;
			for (int j = 0; j < n; j++) {
				if (comp & (1 << j)) {
					g = (g*winm[x][j]) % M;
				}
			}
			tmp = (tmp + dp[x]*g) % M;
		}
		tmp = (1 - tmp + M) % M;
		dp[i] = tmp;

		int f = dp[i];

		int comple = ((1 << n) - 1) ^ i;
		for (int j = 0; j < n; j++) {
			if (comple & (1 << j)) {
				f = (f*winm[i][j]) % M;
			}
		}
		ans = (ans + __builtin_popcountll(i)*f) % M;
	}
	cout << ans << '\n';

	return 0;
}