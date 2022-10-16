#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, p; cin >> n >> p;
	string S; cin >> S;
	vector<int> s(n);
	int a[p][p];
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> cnt(p);
	for (int i = 0; i < n; i++) {
		s[i] = S[i] - 'a';
		cnt[s[i]]++;
	}

	vector<bool> valid(1 << p, 1);
	for (int c1 = 0; c1 < p; c1++) {
		for (int c2 = 0; c2 < p; c2++) {
			if (a[c1][c2]) continue;

			vector<bool> gud(1 << p, 1);
			for (int i = 0; i < n; i++) {
				if (s[i] != c1) continue;

				int j = i+1;
				for (; j < n; j++) {
					if (s[j] == c1 || s[j] == c2) break;
				}
				if (j == n) break;
				if (c1 != c2 && s[i] == s[j]) continue;

				int mask = (1 << p) - 1;
				for (int k = i+1; k < j; k++) {
					if (mask & (1 << s[k])) {
						mask ^= (1 << s[k]);
					}
				}
				gud[mask] = 0;
			}
			
			for (int mask = (1 << p) - 1; mask >= 0; mask--) {
				if (gud[mask]) continue;
				for (int i = 0; i < p; i++) {
					if (c1 == i) continue;
					if (c2 == i) continue;

					if (mask & (1 << i)) gud[mask ^ (1 << i)] = 0;
				}
				valid[mask] = 0;
			}
		}
	}

	int initial = 0;
	for (int i = 0; i < p; i++) {
		if (cnt[i]) initial |= (1 << i);
	}

	vector<int> dp(1 << p);
	dp[initial] = 1;

	for (int mask = initial; mask >= 0; mask--) {
		if (!dp[mask]) continue;

		for (int i = 0; i < p; i++) {
			if (mask & (1 << i)) {
				int nxt = mask ^ (1 << i);

				if (valid[nxt]) dp[nxt] = 1;
			}
		}
	}

	int ans = 100000000;
	for (int mask = 0; mask < (1 << p); mask++) {
		if (dp[mask]) {
			int tmp = 0;
			for (int i = 0; i < p; i++) {
				if (mask & (1 << i)) tmp += cnt[i];
			}
			ans = min(ans, tmp);
		}
	}
	cout << ans << '\n';

	return 0;
}