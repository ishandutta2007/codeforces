#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, cnt[20][20], dp[1 << 20];
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i < n; ++i)
		++cnt[s[i - 1] - 'a'][s[i] - 'a'], ++cnt[s[i] - 'a'][s[i - 1] - 'a'];
	for (int i = 0; i < m; ++i)
		cnt[i][i] = 0;
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < (1 << m); ++i) {
		int pos = __builtin_popcount(i);
		for (int j = 0; j < m; ++j) {
			if (!(i & (1 << j))) {
				int add = 0;
				for (int k = 0; k < m; ++k) {
					if (i & (1 << k))
						add += pos * cnt[j][k];
					else
						add -= pos * cnt[j][k];
				}
				dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + add);
			}
		}
	}
	cout << dp[(1 << m) - 1];
	return 0;
}