#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

ll n, a[5000], dp[2][5000], mn[3][5000];

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (a[0] > 0)
		dp[0][0] = 0, dp[1][0] = 0;
	else
		dp[0][0] = a[0], dp[1][0] = 1;
	for (int i = 1; i < n; i++) {
		ll best = a[i] + dp[0][i - 1];
		if (best > 0) dp[0][i] = dp[1][i] = 0;
		else dp[0][i] = best, dp[1][i] = dp[1][i - 1] + 1;
	}

	mn[0][0] = dp[0][0], mn[1][0] = dp[1][0], mn[2][0] = 0;
	for (int i = 1; i < n; i++) {
		if (dp[0][i] < mn[0][i - 1]) mn[0][i] = dp[0][i], mn[1][i] = dp[1][i], mn[2][i] = i;
		else for (int j = 0; j < 3; j++) mn[j][i] = mn[j][i - 1];
	}
	for (int i = n - 2; i >= 0; i--) a[i] += a[i + 1];

	ll mmn = mn[0][n - 1], at = n - 1, at2 = n, rmn = 0;
	pair<int, int> best = { at, at2 };
	for (int i = n - 1; i > 0; i--) {
		if (a[i] < rmn) {
			rmn = a[i], at2 = i;
		}
		if (mmn > mn[0][i - 1] + rmn) {
			mmn = mn[0][i - 1] + rmn, at = i - 1;
			best = { at, at2 };
		}
	}
	int del1 = mn[2][best.first] - mn[1][best.first] + 1, del2 = mn[2][best.first] + 1, del3 = best.second;
	cout << del1 << " " << del2 << " " << del3 << endl;
}