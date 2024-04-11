#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int c = 0;
	for (int k = 1; k < n; k <<= 1) {
		for (int i = 0; i < n; i += (k << 1)) {
			if (abs(a[i] - a[i + k]) != k) {
				cout << -1 << "\n";
				return;
			}
			if (a[i] > a[i + k]) {
				swap(a[i], a[i + k]);
				++c;
			}
		}
	}
	cout << c << '\n';
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