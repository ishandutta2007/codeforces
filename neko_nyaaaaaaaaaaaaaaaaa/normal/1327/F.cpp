#include <bits/stdc++.h>
using namespace std;

const int M = 998244353;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k, m; cin >> n >> k >> m;
	vector<int> l(m), r(m), x(m);
	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i] >> x[i];
	}

	int ans = 1;
	for (int j = 0; j < k; j++) {
		vector<int> a(n+2), b(n+2);
		for (int i = 0; i < m; i++) {
			if (x[i] & (1 << j)) {
				// every bit has to be 1
				a[l[i]]++; a[r[i] + 1]--;
			} else {
				// previous 0 bit must be at no later than l[i] 
				b[r[i]] = max(b[r[i]], l[i]);
			}
		}

		vector<int> dp(n+2);
		dp[0] = 1;
		for (int i = 1; i <= n+1; i++) {
			a[i] += a[i-1];

			if (a[i]) {dp[i] = 0;}
			else {
				dp[i] = dp[i-1];
				if (b[i - 1]) {
					dp[i] -= dp[b[i - 1] - 1];
				}
				dp[i] %= M;
			}

			dp[i] += dp[i-1];
			dp[i] %= M;
			b[i] = max(b[i], b[i-1]);
		}

		int r = (dp[n+1] - dp[n]) % M;
		if (r < 0) r += M;
		ans = (1LL*ans*r) % M;
	}
	cout << ans << '\n';

	return 0;
}