#include <bits/stdc++.h>

using namespace std; // I don't like this anyway...

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	auto to = [&](int x, int y) {
		return x / (x / y) + 1;
	};
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		vector<int> b(*max_element(a.begin(), a.end()) + 2);
		for (int i = 0; i < n; ++i) {
			int z = 0x3f3f3f3f;
			for (int j = 1; j <= a[i] && j <= k; j = to(a[i], j)) {
				int k = a[i] / j + 1;
				b[k] = max(b[k], z);
				z = k - 1;
			}
			b[0] = max(b[0], z);
		}
		int f = 0, g = 0x3f3f3f3f;
		for (int i = 0; i <= a[0]; ++i) {
			f = max(f, b[i]);
			g = min(g, f - i);
		}
		cout << g << '\n';
	}
}