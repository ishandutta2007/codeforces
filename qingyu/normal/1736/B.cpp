#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	auto lcm = [&](long long x, long long y) {
		return x / gcd(x, y) * y;
	};
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		long long x = (i == 0 ? a[0] : lcm(a[i - 1], a[i]));
		long long y = (i + 1 == n ? a[n - 1] : lcm(a[i], a[i + 1]));
		if (gcd(x, y) != a[i]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}