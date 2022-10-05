#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, k;

void solve() {
	cin >> n >> k;
	if (n == 4 && k == 3) {
		cout << "-1\n";
		return;
	}
	if (k == n - 1) {
		cout << n - 1 << " " << n - 2 << '\n';
		cout << "0 2\n";
		cout << 1 << " " << n - 3 << '\n';
		for (int i = 3; i < n / 2; i++)
			cout << i << " " << n - 1 - i << '\n';
	}
	else {
		cout << k << " " << n - 1 << '\n';
		if (k != 0 && k != n - 1)
			cout << 0 << " " << n - 1 - k << '\n';
		k = min(k, n - 1 - k);
		for (int i = 1; i < n / 2; i++)
			if (i != k)
				cout << i << " " << n - 1 - i << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}