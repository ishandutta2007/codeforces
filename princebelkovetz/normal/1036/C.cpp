#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <iomanip>
#include <map>
#include <cassert>
using namespace std;
#define int long long
#define debug(x) cout << #x << " is " << x << '\n';
const int mod = 1e9 + 7;
const int N = 19;
int dp[N][4][10];
string tostr(int x) {
	string s = "";
	while (x)
		s += (x % 10) + '0', x/= 10;
	reverse(s.begin(), s.end());
	return s;
}
int get(string s) {
	int n = s.size();
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 1; k < 10; ++k)
				ans += dp[i][j][k];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 4 - cnt; ++j) {
			for (int k = 0 + (!i); k < s[i] - '0' + (i == n - 1); ++k)
				ans += dp[n - i][j][k];
		}
		cnt += (s[i] != '0');
	}
	return ans;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	dp[1][0][0] = 1;
	for (int i = 1; i < 10; ++i)
		dp[1][1][i] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 10; ++k)
				dp[i][j][0] += dp[i - 1][j][k];
			for (int k = 1; k < 10; ++k) {
				if (j) {
					for (int s = 0; s < 10; ++s)
						dp[i][j][k] += dp[i - 1][j - 1][s];
				}
			}

		}
	}
	int tt; cin >> tt;
	while (tt --> 0) {
		int l, r; cin >> l >> r;
		l--;
		cout << get(tostr(r)) - get(tostr(l)) << '\n';
	}
	return 0;
}