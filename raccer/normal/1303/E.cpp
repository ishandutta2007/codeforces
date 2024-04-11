#include <bits/stdc++.h>
using namespace std;

int dp[410][410];

int main () {
	int T; cin >> T;
	while (T--) {
		string s, t; cin >> s >> t;
		for (int _ = 0; _ < t.size(); _++) {
			string t1 = t.substr(0, _ + 1), t2 = t.substr(_ + 1, t.size() - _ - 1);
			assert(t1 + t2 == t);
			memset(dp, -1, sizeof(dp));
			dp[0][0] = 0;
			for (int i = 0; i < s.size(); i++) {
				for (int j = 0; j <= t1.size(); j++) {
					if (dp[i][j] == -1) continue;
					int k = dp[i][j];
					dp[i + 1][j] = max(dp[i + 1][j], k);
					if (j < t1.size() && s[i] == t1[j]) dp[i + 1][j + 1] = max(dp[i + 1][j + 1], k);
					if (k < t2.size() && s[i] == t2[k]) dp[i + 1][j] = max(dp[i + 1][j], k + 1);
				}
			}
			if (dp[s.size()][t1.size()] == t2.size()) {
				printf("YES\n");
				goto END;
			}
		}
		printf("NO\n");
		END:;
	}
	return 0;
}