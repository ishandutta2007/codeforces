#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	using ll = long long;

	int n; ll k;
	cin >> n >> k;

	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	auto g = [&](int i, ll d) -> int {
		int lo = 1, hi = a[i];

		if (a[i] - 1 < d) {
			return 0;
		}

		while (lo < hi) {
			int mid = lo + (hi - lo + 1) / 2;
			if (a[i] - 3ll * (mid - 1) * mid - 1 < d)
				hi = mid - 1;
			else lo = mid;
		}
		return lo;
	};

	auto f = [&](ll diff) -> ll {
		ll chosen = 0;
		for (int i = 0; i < n; i++) {
			chosen += g(i, diff);
		}
		return chosen;
	};

	ll lo = (ll)-3e18, hi = (ll)1e9;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (f(mid) <= k)
			hi = mid;
		else lo = mid + 1;
	}

	set<pair<ll, int>, greater<>> s;
	for (int i = 0; i < n; i++) {
		b[i] = g(i, lo);
		k -= b[i];
		if (b[i] != a[i]) {
			s.emplace(a[i] - 3ll * b[i] * (b[i] + 1) - 1, i);
		}
	}

	for (int i = 0; i < k; i++) {
		int x = s.begin()->second;
		s.erase(s.begin());
		if (++b[x] != a[x]) {
			s.emplace(a[x] - 3ll * b[x] * (b[x] + 1) - 1, x);
		}
	}

	for (int i = 0; i < n; i++) cout << b[i] << ' '; cout << '\n';
	return 0;
}