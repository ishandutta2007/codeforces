#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i] += i;
		}

		vector<vector<int>> dp(n, vector<int>(n, 10000));

		for (int i = n - 2; i >= 0; i--) {
			if (a[i] == n - 1) {
				int c = 0;
				for (int j = i + 1; j < n - 1; j++) {
					c += a[j] == n - 1;
				}
				for (int j = i + 1; j < n; j++) {
					dp[i][j] = c;
				}
			} else if (a[i] != i) {
				vector<int> add(n), rem(n);
				for (int j = i + 1; j < n; j++) {
					add[a[j]]++;
					rem[j]++;
				}
				int cur = 0;
				for (int j = n - 1; j > i; j--) {
					cur += add[j] - rem[j];
					if (j <= a[i]) {
						dp[i][j] = min(dp[i][j + 1], cur + dp[j][a[i] + 1]);
					}
				}
			}
		}
		cout << dp[0][1] << '\n';
	}
	return 0;
}