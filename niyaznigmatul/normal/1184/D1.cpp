/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, k, m, t;
	cin >> n >> k >> m >> t;
	for (int i = 0; i < t; i++) {
		int op, x;
		cin >> op >> x;
		if (op == 1) {
			if (x <= k) {
				k++;
			}
			n++;
		} else {
			if (k <= x) {
				n = x;
			} else {
				k -= x;
				n -= x;
			}
		}
		cout << n << ' ' << k << endl;
	}
}