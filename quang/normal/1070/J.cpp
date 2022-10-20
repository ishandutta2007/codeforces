#include <bits/stdc++.h>

using namespace std;
const int N = 200010;

int n, m, k;
int cnt[100];
bool dp[N];

void init() {
	memset(cnt, 0, sizeof cnt);
}

void calcDp(int u) {
	for (int i = 0; i <= k; i++) dp[i] = 0;
	dp[0] = 1;
	int tot = 0;
	for (int i = 0; i < 26; i++) {
		if (i == u) continue;
		for (int j = tot; j >= 0; j--) {
			dp[j + cnt[i]] |= dp[j];
		}
		tot += cnt[i];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> k;
		init();
		string s;
		cin >> s;
		for (char u : s) {
			cnt[u - 'A']++;
		}
		long long res = (1ll << 60);
		for (int i = 0; i < 26; i++) {
			calcDp(i);
			for (int j = 0; j <= k; j++) {
				if (!dp[j]) continue;
				int a = max(0, n - j);
				int b = max(0, m - (k - cnt[i] - j));
				if (a + b <= cnt[i]) {
					res = min(res, 1ll * a * b);
				}
			}
		}
		cout << res << endl;
	}
	return 0;	
}