/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	long long xr, sm;
	cin >> xr >> sm;
	if (sm < xr) {
		cout << "-1\n";
		return 0;
	}
	long long left = sm - xr;
	if ((left & 1) == 1) {
		cout << "-1\n";
		return 0;
	}
	if (left == 0) {
		if (xr == 0) {
			cout << "0\n";
		} else {
			cout << "1\n" << xr << '\n';
		}
		return 0;
	}
	left /= 2;
	if ((xr & left) == 0) {
		cout << "2\n" << xr + left << ' ' << left << '\n';
	} else {
		cout << "3\n" << xr << ' ' << left << ' ' << left << '\n';
	}
}