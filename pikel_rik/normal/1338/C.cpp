#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

ll mask[][4] = {{0, 3, 1, 2}, {0, 1, 2, 3}, {0, 2, 3, 1}};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		ll n, pw = 1;
		cin >> n;

		int p = n % 3;
		n = (n + 2) / 3;

		int c = 0;
		for (; n > pw;) {
			n -= pw;
			pw <<= 2;
			c += 1;
		}
		n -= 1;
		ll ans;
		if (p == 0) {
			ans = pw | (pw << 1);
		} else if (p == 1) {
			ans = pw;
		} else {
			ans = pw << 1;
		}

		for (pw /= 4, c -= 1; pw > 0; pw /= 4, c -= 1) {
			ans |= mask[p][n / pw] << (2 * c);
			n %= pw;
		}

		cout << ans << '\n';
	}
	return 0;
}