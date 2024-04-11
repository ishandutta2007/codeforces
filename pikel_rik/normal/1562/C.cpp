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

		string s;
		cin >> s;

		int i = find(s.begin(), s.end(), '0') - s.begin();
		if (i == n) {
			cout << 1 << ' ' << n / 2 << ' ';
			cout << n / 2 + 1 << ' ' << 2 * (n / 2) << '\n';
		} else {
			if (i < n / 2) {
				cout << i + 1 << ' ' << n << ' ';
				cout << i + 2 << ' ' << n << '\n';
			} else {
				cout << 1 << ' ' << i + 1 << ' ';
				cout << 1 << ' ' << i << '\n';
			}
		}
	}
	return 0;
}