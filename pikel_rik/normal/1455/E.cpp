#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

ll x[4], y[4], k;
int p[] = {0, 1, 2, 3};
ll check(ll xx, ll yy) {
	sort(p, p + 4);
	ll ans = LLONG_MAX;
	do {
		ll cur = abs(xx - x[p[0]]) + abs(yy - y[p[0]]);
		cur += abs(xx + k - x[p[1]]) + abs(yy - y[p[1]]);
		cur += abs(xx - x[p[2]]) + abs(yy + k - y[p[2]]);
		cur += abs(xx + k - x[p[3]]) + abs(yy + k - y[p[3]]);
		ans = min(ans, cur);
	} while (next_permutation(p, p + 4));
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		for (int i = 0; i < 4; i++) {
			cin >> x[i] >> y[i];
		}

		int mxx = *max_element(x, x + 4), mnx = *min_element(x, x + 4);
		int mxy = *max_element(y, y + 4), mny = *min_element(y, y + 4);
		k = min(mxx - mnx, mxy - mny);
		if (mxx - mnx > mxy - mny) {
			for (int i = 0; i < 4; i++) swap(x[i], y[i]);
		}

		ll ans = LLONG_MAX;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				ans = min(ans, check(x[i], y[j]));
				ans = min(ans, check(x[i] - k, y[j]));
				ans = min(ans, check(x[i], y[j] - k));
				ans = min(ans, check(x[i] - k, y[j] - k));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}