#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int xa, ya;
		cin >> xa >> ya;

		int xb, yb;
		cin >> xb >> yb;

		int xf, yf;
		cin >> xf >> yf;

		int ans = abs(xa - xb) + abs(ya - yb);
		if (xa == xb) {
			if (ya > yb) {
				swap(ya, yb);
			}
			if (xf == xa && ya <= yf && yf <= yb) {
				ans += 2;
			}
		} else if (ya == yb) {
			if (xa > xb) {
				swap(xa, xb);
			}
			if (yf == ya && xa <= xf && xf <= xb) {
				ans += 2;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}