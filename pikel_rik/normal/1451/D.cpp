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
		ll d, k;
		cin >> d >> k;

		//a^2 + b^2 => 2ka + k^2, 2kb + k^2

		ll lo = 0, hi = (d + k - 1) / k;
		while (lo < hi) {
			ll mid = lo + (hi - lo + 1) / 2;
			if (2 * mid * mid * k * k <= d * d) {
				lo = mid;
			} else hi = mid - 1;
		}

		ll sq = lo * k;
		if (sq > 0 && (sq + k) * (sq + k) + sq * sq > d * d) {
			cout << "Utkarsh\n";
		} else {
			cout << "Ashish\n";
		}
	}
	return 0;
}