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
		ll n, k;
		cin >> n >> k;

		if (k * k <= n && (k & 1) == (n & 1)) {
			cout << "YES\n";
		} else cout << "NO\n";
	}
	return 0;
}