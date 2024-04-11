#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, q;
ll a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
	}

	ll k_1 = 0;
	for (int i = 1; i < n; i++) {
		k_1 += a[i];
	}

	cin >> q;
	while (q--) {
		int k;
		cin >> k;

		if (k == 1) {
			cout << k_1 << ' ';
			continue;
		}

		int left = n - 1;
		ll pw = k;

		ll ans = 0;
		for (int i = 1;; i++, pw *= k) {
			if (left <= pw) {
				ans += i * a[left];
				break;
			} else {
				ans += i * (a[left] - a[left - pw]);
				left -= pw;
			}
		}
		cout << ans << ' ';
	}
	cout << '\n';
	return 0;
}