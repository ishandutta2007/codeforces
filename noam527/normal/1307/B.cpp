#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

void solve() {
	int n, x, mx;
	cin >> n >> x;
	bool eq = false;
	mx = -1;
	while (n--) {
		int tmp;
		cin >> tmp;
		if (tmp == x) eq = true;
		mx = max(mx, tmp);
	}
	if (eq) {
		cout << "1\n";
		return;
	}
	if (x % mx == 0) {
		cout << x / mx << '\n';
		return;
	}
	if (x < mx) {
		cout << "2\n";
		return;
	}
	cout << x / mx + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}