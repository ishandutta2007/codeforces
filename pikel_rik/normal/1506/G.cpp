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

		int n = s.length();
		vector<vector<int>> pos(26);

		set<int, greater<>> ch;
		for (int i = 0; i < n; i++) {
			pos[s[i] - 'a'].push_back(i);
			ch.insert(s[i] - 'a');
		}

		vector<int> ptr(26);

		string ans;
		while (!ch.empty()) {
			for (int i : ch) {
				bool can_take = true;
				for (int j : ch) {
					can_take &= pos[j].back() >= pos[i][ptr[i]];
				}
				if (can_take) {
					ch.erase(i);
					for (int j : ch) {
						while (pos[j][ptr[j]] <= pos[i][ptr[i]]) {
							ptr[j] += 1;
						}
					}
					ans += 'a' + i;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}