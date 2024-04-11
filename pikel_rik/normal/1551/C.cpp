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

		vector<string> s(n);
		for (int i = 0; i < n; i++) cin >> s[i];

		int ans = 0;
		for (int letter = 0; letter < 5; letter++) {
			vector<int> a(n);
			for (int i = 0; i < n; i++) {
				int cnt = count(s[i].begin(), s[i].end(), 'a' + letter);
				a[i] = 2 * cnt - (int) s[i].length();
			}

			sort(a.rbegin(), a.rend());

			int sum = 0;
			for (int i = 0; i < n; i++) {
				sum += a[i];
				if (sum <= 0) {
					break;
				} else {
					ans = max(ans, i + 1);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}