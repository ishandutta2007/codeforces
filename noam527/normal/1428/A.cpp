#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int x[2], y[2];

void solve() {
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	if (x[0] == x[1] || y[0] == y[1]) {
		cout << abs(x[0] - x[1]) + abs(y[0] - y[1]) << '\n';
		return;
	}
	cout << 2 + abs(x[0] - x[1]) + abs(y[0] - y[1]) << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}