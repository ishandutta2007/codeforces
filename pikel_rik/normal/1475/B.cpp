#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		bool f = false;
		for (int i = 0; i * 2020 <= n; i++) {
			f |= (n - i * 2020) % 2021 == 0;
		}
		cout << (f ? "YES" : "NO") << '\n';
	}
	return 0;
}