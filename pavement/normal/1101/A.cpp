#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q, l, r, d;
	cin >> q;
	while (q--) {
		cin >> l >> r >> d;
		if (d < l) cout << d << '\n';
		else {
			int x = (r + d - 1) / d * d;
			if (x == r) x += d;
			cout << x << '\n';
		}
	}
}