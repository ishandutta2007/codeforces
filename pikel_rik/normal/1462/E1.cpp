#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

ll C(ll n, int k) {
	if (k == 0)
		return 1;
	if (k == 1)
		return n;
	if (k == 2)
		return (n * n - n) / 2;
	return (n * (n - 1) * (n - 2)) / 6;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m = 3, k = 2;
		cin >> n;

		vector<int> a(n), cnt(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			cnt[--a[i]]++;
		}

		vector<int> pref(cnt.begin(), cnt.end());
		for (int i = 1; i < n; i++) pref[i] += pref[i - 1];

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int temp = pref[min(n - 1, i + k)]  - pref[i];
			for (int j = 1; j <= min(m, cnt[i]); j++) {
				if (temp >= m - j) {
					ans += C(cnt[i], j) * C(temp, m - j);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}