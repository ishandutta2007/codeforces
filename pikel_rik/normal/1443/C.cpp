#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n;
pair<int, int> a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i].first;
		for (int i = 0; i < n; i++) cin >> a[i].second;

		sort(a, a + n);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i].second;
		}

		ll ans = sum;
		for (int i = 0; i < n; i++) {
			sum -= a[i].second;
			ans = min(ans, max((ll)a[i].first, sum));
		}
		cout << ans << '\n';
	}
	return 0;
}