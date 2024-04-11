#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> ok(n + 1);
	ok[0] = true;
	for (int i = 1; i <= n; ++i) {
		int x = a[i - 1];
		if (i + x <= n) ok[i + x] |= ok[i - 1];
		if (i - x - 1 >= 0) ok[i] |= ok[i - x - 1];
	}
	cout << (ok[n] ? "YES\n" : "NO\n");
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