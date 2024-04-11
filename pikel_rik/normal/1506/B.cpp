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

		string s;
		cin >> s;

		int ans = 1;
		int i = find(s.begin(), s.end(), '*') - s.begin();
		while (true) {
			int next_pos = i;
			for (int j = i + 1; j < n && j - i <= k; j++) {
				if (s[j] == '*') {
					next_pos = j;
				}
			}
			if (i == next_pos)
				break;
			i = next_pos;
			ans += 1;
		}

		cout << ans << '\n';
	}
	return 0;
}