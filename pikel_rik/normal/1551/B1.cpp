#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int n = (int) s.length();

		vector<int> cnt(26);
		for (int i = 0; i < n; i++) {
			cnt[s[i] - 'a'] += 1;
		}

		int take = 0;
		for (int i = 0; i < 26; i++) {
			cnt[i] = min(cnt[i], 2);
			take += cnt[i];
		}

		take -= take % 2;
		cout << take / 2 << '\n';
	}
	return 0;
}