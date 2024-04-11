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
		int x, y;
		cin >> x >> y;

		int ans = 2 * min(x, y);
		x = max(x, y) - min(x, y);

		ans += max(0, 2 * x - 1);

		cout << ans << '\n';
	}
	return 0;
}