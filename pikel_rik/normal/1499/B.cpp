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
		bool possible = is_sorted(s.begin(), s.end());

		for (int i = -1; i < n; i++) {
			vector<int> pos;
			for (int j = 0; j <= i; j++) {
				if (s[j] == '1') {
					pos.push_back(j);
				}
			}
			for (int j = i + 1; j < n; j++) {
				if (s[j] == '0') {
					pos.push_back(j);
				}
			}

			sort(pos.begin(), pos.end());

			bool ok = true;
			for (int j = 1; j < pos.size(); j++) {
				ok &= pos[j - 1] + 1 != pos[j];
			}
			possible |= ok;
		}

		cout << (possible ? "YES" : "NO") << '\n';
	}
	return 0;
}