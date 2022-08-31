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

		int l = -1, r = -1;
		for (int i = 0; i < n; i++) {
			array<int, 2> cnt = {};
			for (int j = i; j < n; j++) {
				cnt[s[j] - 'a'] += 1;
				if (cnt[0] == cnt[1]) {
					l = i + 1, r = j + 1;
				}
			}
		}

		cout << l << ' ' << r << '\n';
	}
	return 0;
}