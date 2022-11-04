#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n;
int a[600];
int dp[600][600];
bool isp[600][600];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int left = 0; left < n; left++) {
		for (int right = left; right < n; right++) {
			bool ok = true;

			for (int i = 0; i <= right - left; i++) {
				ok &= a[left + i] == a[right - i];
			}

			isp[left][right] = ok;
		}
	}

	for (int i = 0; i < n; i++) {
		dp[i][i] = 1;
	}

	for (int len = 2; len <= n; len++) {
		for (int left = 0; left <= n - len; left++) {
			int right = left + len - 1;

			if (isp[left][right]) {
				dp[left][right] = 1;
				continue;
			}

			dp[left][right] = dp[left][right - 1] + 1;

			for (int i = left + 1; i < right; i++) {
				if (a[i] != a[right]) {
					continue;
				}

				dp[left][right] = min(dp[left][right], dp[left][i - 1] + dp[i][right]);
			}

			if (a[left] == a[right]) {
				dp[left][right] = min(dp[left][right], dp[left + 1][right - 1]);
			}
		}
	}

	cout << dp[0][n - 1] << endl;

    return 0;
}