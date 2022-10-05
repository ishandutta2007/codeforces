#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int x, y;

void solve() {
	cin >> x >> y;
	if (x > y) {
		cout << x + y << '\n';
		return;
	}
	if (x == y) {
		cout << x << '\n';
		return;
	}
	if (y <= 100) {
		for (int n = 1; n <= 100; n++) {
			if (n % x == y % n) {
				cout << n << '\n';
				return;
			}
		}
	}
	int m = y % x;
	cout << y - m / 2 << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}