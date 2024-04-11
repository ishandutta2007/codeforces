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

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];

		ll delta = 0, cur = 0;
		for (int i = 0; i < n; i++) {
			cur += abs(a[i] + delta - a[0]);
			delta -= a[i] + delta - a[0];
		}

		ll ans = cur;
		for (int i = 2; i < n; i++) {
			ans = min(ans, cur - abs(a[i - 1] - a[i]) - abs(a[i - 2] - a[i - 1]) + abs(a[i - 2] - a[i]));
		}
		ans = min(ans, cur - abs(a[0] - a[1]));
		ans = min(ans, cur - abs(a[n - 2] - a[n - 1]));
		cout << ans << '\n';
	}
	return 0;
}