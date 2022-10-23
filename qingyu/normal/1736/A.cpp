#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
	vector<int> a(n), b(n);
	int mncost = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i]) ++a1;
		else ++a0;
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		mncost += (a[i] != b[i]);
		if (b[i]) ++b1;
		else ++b0;
	}
	if (a0 >= b0) {
		mncost = min(mncost, 1 + a0 - b0);
	}
	if (a1 >= b1) {
		mncost = min(mncost, 1 + a1 - b1);
	}
	cout << mncost << '\n';
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