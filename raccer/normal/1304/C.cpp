#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; cin >> n >> m;
		long long ll = m, rr = m, last = 0, pd = 0;
		for (int i = 0; i < n; i++) {
			long long t, l, r; cin >> t >> l >> r;
			ll -= t - last, rr += t - last;
			last = t;
			ll = max(ll, l), rr = min(rr, r);
			if (ll > rr) pd = 1;
		}
		if (pd) printf("NO\n");
		else printf("YES\n");
		END:;
	}
	return 0;
}