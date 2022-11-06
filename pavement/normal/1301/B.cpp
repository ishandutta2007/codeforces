#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[100005], b[100005];

int f(int x) {
	for (int i = 1; i <= n; i++) {
		if (a[i] == -1) b[i] = x;
		else b[i] = a[i];
	}
	int r = 0;
	for (int i = 1; i < n; i++)
		r = max(r, abs(b[i] - b[i + 1]));
	return r;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int lo = 0, hi = 1e9;
		while (hi - lo >= 3) {
			int m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3, p1 = f(m1), p2 = f(m2);
			if (p1 > p2) lo = m1;
			else hi = m2;
		}
		int r = LLONG_MAX, ans = -1;
		for (int i = lo; i <= hi; i++) {
			int c = f(i);
			if (c <= r) {
				r = c;
				ans = i;
			}
		}
		cout << r << ' ' << ans << '\n';
	}
}