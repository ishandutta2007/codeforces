#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <iomanip>
#include <map>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;
const int N = 5e3 + 2;
int dp[N][N][2];
void relax(int& a, int b) {
	a = min(a, b);
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j) dp[i][j][0] = dp[i][j][1] = 0;
			else dp[i][j][0] = dp[i][j][1] = mod;
		}
	}
	for (int r = 0; r < n; ++r) {
		for (int l = r; l >= 0; --l) {
			for (int s = 0; s < 2; ++s) {
				int color = s ? a[r] : a[l];
				if (r < n - 1) {
					relax(dp[l][r + 1][1], dp[l][r][s] + (a[r + 1] != color));
				}
				if (l > 0) {
					relax(dp[l - 1][r][0], dp[l][r][s] + (a[l - 1] != color));
				}
			}
		}
	}
	cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << '\n';
	return 0;
}