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

		vector<int> left(n), right(n);
		left[0] = 1;

		for (int i = 1; i < n; i++) {
			if (s[i] != s[i - 1]) {
				left[i] = 1 + left[i - 1];
			} else left[i] = 1;
		}

		right[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--) {
			if (s[i] != s[i + 1]) {
				right[i] = 1 + right[i + 1];
			} else right[i] = 1;
		}

		cout << 1 + (s[0] == 'R') * right[0] << ' ';

		for (int i = 1; i < n; i++) {
			int ans = 1 + (s[i] == 'R') * right[i] + (s[i - 1] == 'L') * left[i - 1];
			cout << ans << ' ';
		}

		cout << 1 + (s[n - 1] == 'L') * left[n - 1] << '\n';
	}
	return 0;
}