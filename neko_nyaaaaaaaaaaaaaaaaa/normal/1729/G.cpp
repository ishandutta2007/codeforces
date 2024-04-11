#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9+7;
const int MAXN = 505;

int can[MAXN][MAXN], wae[MAXN][MAXN];

void solve() {
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();
	vector<int> matches;
	for (int i = 0; i < n; i++) {
		bool is_match = 1;
		for (int j = 0; j < m; j++) {
			if (i+j >= n) {
				is_match = 0; break;
			} 
			if (s[i+j] != t[j]) {
				is_match = 0; break;
			}
		}
		if (is_match) matches.push_back(i);
	}

	if (matches.empty()) {
		cout << "0 1\n";
		return;
	}

	int k = matches.size();
	memset(can, 0, sizeof(can));
	memset(wae, 0, sizeof(wae));

	can[0][0] = wae[0][0] = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			if (can[i][j] == 0) continue;

			int last = (i == 0 ? -1 : matches[i-1]+m-1);
			int lo = 0;
			for (int nxt = i; nxt < k; nxt++) {
				if (matches[nxt] > last) {
					lo = matches[nxt];
					break;
				}
			}

			for (int nxt = i; nxt < k; nxt++) {
				if (matches[nxt] <= last) continue;
				if (matches[nxt] - lo >= m) break;

				can[nxt+1][j+1] = 1;
				wae[nxt+1][j+1] = (wae[nxt+1][j+1] + wae[i][j]) % M;
			}
		}
	}

	int lf = matches[k-1];
	int lstid = 0;
	for (int i = k-1; i >= 0; i--) {
		if (matches[i]+m-1 < lf) {
			break;
		}
		lstid = i;
	}

	for (int i = 0; i <= k; i++) {
		bool ok = 0;
		for (int j = lstid+1; j <= k; j++) {
			if (can[j][i]) {
				ok = 1; break;
			}
		}

		if (ok) {
			int res = 0;
			for (int j = lstid+1; j <= k; j++) {
				res = (res + wae[j][i]) % M;
			}
			cout << i << ' ' << res << '\n';
			return;
		}
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}