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

	int n, x, pos;
	cin >> n >> x >> pos;

	ll ans = 1;
	int lo = 0, hi = n, smaller = x - 1, larger = n - x;

	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (pos >= mid) {
			if (pos == mid) {

			} else {
				ans = ans * smaller % mod;
				smaller--;
			}
			lo = mid + 1;
		} else {
			ans = ans * larger % mod;
			larger--;
			hi = mid;
		}
	}

	for (int i = 1; i <= smaller + larger; i++) {
		ans = ans * i % mod;
	}
	cout << ans << '\n';
	return 0;
}