#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 100000;
int n, m, q, a[mxN], b[mxN];
ll base = 0, pre[mxN + 1];

int sign(int i) {return i % 2 == 0 ? 1 : -1;}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		base += sign(i) * a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
		pre[i + 1] = pre[i] + sign(i) * b[i];
	}
	set<ll> s;
	for (int i = n; i <= m; ++i) {
		s.insert(sign(i - n + 1) * (pre[i] - pre[i - n]));
	}
	auto Solve = [&]() {
		auto it = s.lower_bound(-base);
		ll ans = INT64_MAX;
		if (it != s.end()) ans = min(ans, abs(base + *it));
		if (it != s.begin()) ans = min(ans, abs(base + *(--it)));
		cout << ans << "\n";
	};
	Solve();
	for (int i = 0; i < q; ++i) {
		int l, r, x; cin >> l >> r >> x;
		if ((r - l + 1) % 2 == 1) {
			base += sign(l - 1) * x;
		}
		Solve();
	}
	return 0;
}