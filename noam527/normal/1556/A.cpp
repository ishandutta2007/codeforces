#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

ll a, b, c, d;

void solve() {
	cin >> c >> d;
	a = b = 0;
	if ((a + b) % 2 != (c + d) % 2 || a + b > c + d) {
		cout << "-1\n";
		return;
	}
	if (c == 0 && d == 0) {
		cout << "0\n";
		return;
	}
	if (a + b == c + d || c == d) {
		cout << "1\n";
		return;
	}
	cout << 2 << "\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}