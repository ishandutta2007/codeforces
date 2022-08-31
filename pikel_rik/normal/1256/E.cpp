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

	int n;
	cin >> n;

	vector<int> a(n), ans(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<int> ind(n);
	iota(ind.begin(), ind.end(), 0);
	sort(ind.begin(), ind.end(), [&](int i, int j) {
		return a[i] < a[j];
	});

	vector<int> dp(n);

	dp[2] = a[ind[2]] - a[ind[0]];

	if (n > 3) dp[3] = a[ind[3]] - a[ind[0]];
	if (n > 4) dp[4] = a[ind[4]] - a[ind[0]];

	for (int i = 5; i < n; i++) {
		dp[i] = INT_MAX;
		for (int j = 2; j <= 5 && i - j - 1 >= 2; j++) {
			dp[i] = min(dp[i], a[ind[i]] - a[ind[i - j]] + dp[i - j - 1]);
		}
	}

	int team_no = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (i <= 4) {
			for (int j = 0; j <= i; j++) {
				ans[ind[j]] = team_no;
			}
			break;
		}
		for (int j = 2; j <= 5 && i - j - 1 >= 2; j++) {
			if (dp[i] == a[ind[i]] - a[ind[i - j]] + dp[i - j - 1]) {
				for (int k = i - j; k <= i; k++) {
					ans[ind[k]] = team_no;
				}
				i -= j;
				team_no++;
				break;
			}
		}
	}

	cout << dp[n - 1] << ' ' << team_no << '\n';
	for (int i : ans) cout << i << ' '; cout << '\n';
	return 0;
}