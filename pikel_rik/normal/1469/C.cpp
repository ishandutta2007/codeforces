#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> h(n);
		for (int i = 0; i < n; i++) cin >> h[i];

		vector<array<int, 2>> s;
		int len = 1;

		for (int i = 1; i < n; i++) {
			if (h[i] != h[i - 1]) {
				s.push_back({h[i - 1], len});
				len = 1;
			} else {
				len++;
			}
		}

		s.push_back({h[n - 1], len});

		if (s.size() == 1) {
			cout << "YES\n";
			continue;
		}

		int last = s[0][0];
		if (s[0][1] > 1 && s[0][0] < s[1][0]) {
			last += k - 1;
		}

		bool bad = false;
		for (int i = 1;; i++) {
			if (last < s[i][0]) {
				bad |= s[i][0] - last > k - 1;
			} else if (last > s[i][0] + k - 1) {
				bad |= last - (s[i][0] + k - 1) > k - 1;
			}
			if (i == (int)s.size() - 1) break;
			if (s[i - 1][0] < s[i][0] && s[i][0] > s[i + 1][0]) {
				last = s[i][0];
			} else if (s[i - 1][0] > s[i][0] && s[i][0] < s[i + 1][0]) {
				last = s[i][0] + k - 1;
			} else if (s[i][1] == 1) {
				if (s[i - 1][0] < s[i][0] && s[i][0] < s[i + 1][0]) {
					last = min(last + k - 1, s[i][0] + k - 1);
				} else {
					last = max(last - (k - 1), s[i][0]);
				}
			} else {
				if (s[i - 1][0] < s[i][0] && s[i][0] < s[i + 1][0]) {
					last = s[i][0] + k - 1;
				} else {
					last = s[i][0];
				}
			}
		}

		if (bad || (s.back()[1] == 1 && abs(last - s.back()[0]) > k - 1)) {
			cout << "NO\n";
		} else cout << "YES\n";
	}
	return 0;
}