#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;

		string s;
		cin >> s;

		if (b >= 0) {
			cout << n * (a + b) << '\n';
		} else {
			int ans = n * a, segments = 1;
			for (int i = 1; i < n; i++) {
				if (s[i] != s[i - 1]) {
					segments += 1;
				}
			}
			ans += (segments / 2 + 1) * b;
			cout << ans << '\n';
		}
	}
	return 0;
}