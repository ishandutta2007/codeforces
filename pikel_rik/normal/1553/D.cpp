#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while (q--) {
		string s, t;
		cin >> s >> t;

		int n = (int) s.length();
		int m = (int) t.length();

		bool possible = false;
		for (int f = 0; f < 2; f++) {
			int cur_f = f;

			int i = 0, j = 0;
			for (; i < n && j < m; i++) {
				if (i % 2 == cur_f && s[i] == t[j]) {
					j += 1;
					cur_f ^= 1;
				}
			}

			if (j == m && (n - i) % 2 == 0) {
				possible = true;
			}
		}
		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}