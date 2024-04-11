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

		if (b >= a) {
			cout << b << '\n';
		} else {
			a -= b;
			if (c <= d) {
				cout << "-1\n";
			} else {
				cout << b + c * ((a + c - d - 1) / (c - d)) << '\n';
			}
		}
	}
	return 0;
}