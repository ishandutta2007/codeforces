#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;

void solve() {
	cin >> n >> k;
	int x = n - k + 1;
	if (x <= n / 2) {
		for (int i = 0; i < k - 1; ++i)
			cout << 1 << " ";
		cout << x << "\n";
		return;
	}
	while(k > 3)
		cout << 1 << " ", --n, --k;
	if (n % 4 == 0) {
		cout << n / 2 << " " << n / 4 << " " << n / 4 << "\n";
		return;
	}
	int mul = 1 << (__builtin_ctz(n));
	n /= mul;
	cout << n / 2 * mul << " " << n / 2 * mul << " " << mul << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}