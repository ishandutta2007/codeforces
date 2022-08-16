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

		if (is_sorted(s.begin(), s.end())) {
			cout << 0 << '\n';
			continue;
		}

		cout << 1 << '\n';
		int ones = count(s.begin(), s.end(), '1'), zeroes = 0;

		for (int i = n - 1; i >= 0; i--) {
			zeroes += s[i] == '0';
			ones -= s[i] == '1';
			if (zeroes >= ones) {
				cout << ones + zeroes << ' ';
				for (int j = 0; j < i; j++) {
					if (s[j] == '1') {
						cout << j + 1 << ' ';
					}
				}
				for (int j = i; j < n; j++) {
					if (s[j] == '0') {
						cout << j + 1 << ' ';
					}
				}
				cout << '\n';
				break;
			}
		}
	}
	return 0;
}