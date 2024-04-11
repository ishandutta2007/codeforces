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

	int n;
	cin >> n;

	vector<int> a((n + 1) / 2);
	for (int i = 0; i < (n + 1) / 2; i++) cin >> a[i];

	int x;
	cin >> x;

	vector<ll> pref(a.begin(), a.end());
	for (int i = 1; i < (n + 1) / 2; i++) pref[i] += pref[i - 1];

	if (x <= 0) {
		vector<ll> sum(a.size());
		for (int i = 0; i < a.size(); i++) {
			sum[i] = pref.back() - (i != 0 ? pref[i - 1] : 0) + (ll)i * x;
		}
		vector<ll> pref_mn(sum.begin(), sum.end());
		for (int i = 1; i < a.size(); i++) {
			pref_mn[i] = min(pref_mn[i], pref_mn[i - 1]);
		}
		int ok = -1;
		for (int k = n / 2 + 1; k <= n; k++) {
			if (pref_mn[n - k] + (ll)(k - (n + 1) / 2) * x > 0) {
				ok = k;
				break;
			}
		}
		cout << ok << '\n';
	} else {
		if (pref.back() + (ll)(n / 2) * x > 0) {
			cout << n << '\n';
		} else {
			cout << -1 << '\n';
		}
	}
	return 0;
}