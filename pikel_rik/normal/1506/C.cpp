#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto match = [&](const string &s, const string &t) -> bool {
		bool ans = false;
		int n = s.length(), m = t.length();
		for (int i = 0; i + n <= m; i++) {
			bool matched = true;
			for (int j = i; j < i + n; j++) {
				matched &= s[j - i] == t[j];
			}
			ans |= matched;
		}
		return ans;
	};

	int t;
	cin >> t;

	while (t--) {
		string a, b;
		cin >> a >> b;

		int n = a.length(), m = b.length();
		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (match(a.substr(i, j - i + 1), b)) {
					ans = max(ans, 2 * (j - i + 1));
				}
			}
		}
		cout << n + m - ans << '\n';
	}
	return 0;
}