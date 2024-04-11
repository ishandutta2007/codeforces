#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>
using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;
bool ok(int m1, int m2, int len) {
	int l1 = -1, l2 = -1;
	while (len --> 0) {
		int c1 = m1 & 1, c2 = m2 & 1;
		if (l1 != -1) {
			if ((l1 + l2 + c1 + c2) % 2 == 0) return false;
		}
		l1 = c1, l2 = c2;
		m1 >>= 1, m2 >>= 1;
	}
	return true;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	vector <string> a(n);
	for (auto& x : a) cin >> x;
	if (min(n, m) > 3) {
		cout << "-1\n";
		return 0;
	}
	if (min(n, m) < 2) {
		cout << "0\n";
		return 0;
	}
	vector <vector <int>> mat(min(n, m), vector <int>(max(n, m)));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int cur = a[i][j] - '0';
			if (n > m) swap(i, j);
			mat[i][j] = cur;
			if (n > m) swap(i, j);
		}
	}
	if (n > m) swap(n, m);
	vector <vector <int>> dp(m + 1, vector <int>(1 << n));
	for (int i = 1; i <= m; ++i) {
		for (int m1 = 0; m1 < (1 << n); ++m1) {
			dp[i][m1] = mod;
			int add = 0;
			for (int j = 0; j < n; ++j)
				add += (((m1 >> j) & 1) ^ mat[j][i - 1]);
			for (int m2 = 0; m2 < (1 << n); ++m2) {
				if (ok(m1, m2, n))
					dp[i][m1] = min(dp[i][m1], dp[i - 1][m2] + add);
			}
		}
	}
	int ans = mod;
	for (auto x : dp.back()) ans = min(ans, x);
	cout << ans << '\n';
}