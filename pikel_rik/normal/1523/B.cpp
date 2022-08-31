#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		//a = a + b;
		//b = b - a
		//a = a + b

		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		cout << 3 * n << '\n';
		for (int i = 0; i < n; i += 2) {
			for (int rot = 0; rot < 2; rot++) {
				cout << "1 " << i + 1 << ' ' << i + 2 << '\n';
				cout << "2 " << i + 1 << ' ' << i + 2 << '\n';
				cout << "1 " << i + 1 << ' ' << i + 2 << '\n';
			}
		}
	}
	return 0;
}