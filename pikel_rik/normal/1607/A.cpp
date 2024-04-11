#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		string perm;
		cin >> perm;

		vector<int> pos(26);
		for (int i = 0; i < 26; i++) {
			pos[perm[i] - 'a'] = i;
		}

		string s;
		cin >> s;

		int ans = 0;
		for (int i = 1; i < (int) s.length(); i++) {
			ans += abs(pos[s[i] - 'a'] - pos[s[i - 1] - 'a']);
		}
		cout << ans << '\n';
	}
	return 0;
}