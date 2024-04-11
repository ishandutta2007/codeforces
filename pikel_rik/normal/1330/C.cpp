#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

ll n, m, l[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < m; i++) cin >> l[i];

	if (accumulate(l, l + m, 0ll) < n) {
		cout << "-1\n";
		return 0;
	}

	vector<ll> ans(m);
	ll last = 0;

	for (int i = m - 1; i >= 0; i--) {
		ans[i] = last + 1 - l[i];
		if (ans[i] < 0) {
			ans[i] = 0;
		}
		last = ans[i] + l[i];
	}

	if (last > n) {
		cout << "-1\n";
		return 0;
	}

	ll add = 0;
	for (int i = m - 2; i >= 0; i--) {
		ll moves = ans[i + 1] + l[i + 1] - ans[i];
		add += min(n - last, moves);
		last += min(n - last, moves);
		ans[i] += add;
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i] + 1 << ' ';
	}
	cout << '\n';
	return 0;
}