#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20, K = 24;

int binom(int n, int k) {
	if (k < 0 || n < k) return 0;
	return (n&k) == k;
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> b(n);
	for (int &x: b) cin >> x;

	// dp[r][i] = sum { binom(n-r,j) | i <= j }
	vector<vector<int>> dp(K, vector<int>(n+1));
	for (int r = 0; r < K; r++) {
		for (int i = n-r; i >= 0; i--) {
			dp[r][i] = binom(n-r,i);
			if (i+1 <= n) dp[r][i] ^= dp[r][i+1];
		}
	}

	vector<int> res(N);
	for (int i = 0; i < n; i++) {
		int cur = b[i];
		for (int j = i+1; j <= n; j++) {
			int r = j-i, s = k;
			if (i > 0) r++, s--;
			if (j < n) r++, s--;
			s = max(s,0);
//			cerr << i << " " << j << " " << cur << " " << r << " " << s << " " << dp[r][s] << endl;
			if (dp[r][s]) res[cur] ^= 1;
			if (j == n) break;
			int x = b[j];
			while (x--) {
				cur <<= 1;
				if (cur >= N) break;
			}
			if (cur >= N || cur == 0) break;
		}
	}

	int s = N;
	while (s > 0 && res[s-1] == 0) s--;

	if (s == 0) {
		cout << 0;
	} else {
		while (s--) cout << res[s];
	}
	cout << '\n';
}