#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), f(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	f[0] = 1;
	for (int i = 1; i < n; ++i) {
		f[i] = min(f[i - 1] + 1, a[i]);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans += f[i];
	cout << ans << '\n';
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