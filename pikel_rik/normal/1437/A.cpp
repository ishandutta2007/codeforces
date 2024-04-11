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
		int l, r;
		cin >> l >> r;

		int ans = r + 1;
		if (2ll * (l % ans) >= ans && 2ll * (r % ans) >= ans) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
	return 0;
}