#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int m, d, w;
		cin >> m >> d >> w;
		int k = min(m, d);

		int diff = abs((d % w) - 1);
		int p = w/__gcd(w, diff);

		int cnt = k/p;
		int f1 = cnt*k;
		int f2 = p*(cnt*(cnt+1)/2);

		cout << f1 - f2 << '\n';
	}

	return 0;
}