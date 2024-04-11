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

		string s0, s1;
		cin >> s0 >> s1;

		int ans = 0;
		vector<bool> picked(n);

		for (int i = 0; i < n; i++) {
			if (s0[i] != s1[i]) {
				picked[i] = true;
				ans += 2;
			}
		}

		for (int i = 0; i < n; i++) {
			if (!picked[i] && s0[i] == '0') {
				if (i > 0 && !picked[i - 1] && s0[i - 1] == '1') {
					picked[i - 1] = true;
					ans += 2;
				} else if (i + 1 < n && !picked[i + 1] && s0[i + 1] == '1') {
					picked[i + 1] = true;
					ans += 2;
				} else {
					ans += 1;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}