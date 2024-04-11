#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2000 + 5;

int n, k, l[N], r[N], a[N];
unordered_map<int, ll> dp[N];

ll recurse(int i, int mag) {
	if (i == n) {
		return 0;
	}
	ll& ans = dp[i][mag];
	if (ans) {
		return ans;
	}
	ans = LLONG_MAX;
	int reloads = max(0, (a[i] - mag + k - 1) / k);
	if (reloads == r[i] - l[i]) {
		int left_over = mag + reloads * k - a[i];
		if (recurse(i + 1, left_over) != LLONG_MAX) {
			ans = min(ans, a[i] + recurse(i + 1, left_over));
		}
		if (i + 1 < n and r[i] != l[i + 1] and recurse(i + 1, k) != LLONG_MAX) {
			ans = min(ans, a[i] + left_over + recurse(i + 1, k));
		}
	} else if (reloads < r[i] - l[i]) {
		int left_over = mag + reloads * k - a[i];
		if (recurse(i + 1, left_over) != LLONG_MAX) {
			ans = min(ans, a[i] + recurse(i + 1, left_over));
		}
		if (recurse(i + 1, k) != LLONG_MAX) {
			ans = min(ans, a[i] + left_over + recurse(i + 1, k));
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i] >> a[i];

	ll ans = recurse(0, k);
	if (ans == LLONG_MAX) {
		ans = -1;
	}
	cout << ans << '\n';
	return 0;
}