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
		ll a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a > b * c) {
			cout << "-1\n";
			continue;
		}

		ll last = (a + b - 1) / b + 1;

		if (last % d == 0) {
			last -= d - 1;
		} else {
			last -= last % d - 1;
		}

		ll num = (last - 1) / d + 1;
		ll ans = num * a - b * (num * last - num - d * (num * num - num) / 2);

		last -= d;
		num -= 1;
		
		if (last >= 1) {
			ans = max(ans, num * a - b * (num * last - num - d * (num * num - num) / 2));
		}
		cout << ans << '\n';
	}
	return 0;
}