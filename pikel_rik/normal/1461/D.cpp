#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, q, a[N];
ll pref[N];

set<ll> sums;

void recurse(int l, int r) {
	sums.insert(pref[r] - pref[l - 1]);
	int mid = (a[r] + a[l]) / 2;
	int idx = upper_bound(a + l, a + r + 1, mid) - a;
	if (idx != r + 1) {
		recurse(l, idx - 1);
		recurse(idx, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> q;
		for (int i = 1; i <= n; i++) cin >> a[i];

		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

		sums.clear();
		recurse(1, n);

		while (q--) {
			int s;
			cin >> s;
			cout << (sums.count(s) ? "Yes" : "No") << '\n';
		}
	}
	return 0;
}