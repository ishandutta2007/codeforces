#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n);
	for (auto &x : a) cin >> x;

	int g = 0;
	for (auto &x : a) g = __gcd(g, x);

	bitset<2000 * 100 + 1> b;
	b[0] = 1;

	for (auto &x : a) {
		x /= g;
		b |= b << x;
	}

	int sum = accumulate(a.begin(), a.end(), 0);

	if (sum % 2 == 0 && b[sum / 2]) {
		int ans = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 != 0) {
				ans = i;
				break;
			}
		}
		cout << 1 << '\n' << ans + 1 << '\n';
	} else {
		cout << 0 << '\n';
	}
	return 0;
}