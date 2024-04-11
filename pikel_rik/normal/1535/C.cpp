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

		array<array<int, 2>, 2> pos;
		for (int i : {0, 1}) for (int j : {0, 1}) pos[i][j] = -1;

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0') {
				pos[0][i % 2] = i;
			} else if (s[i] == '1') {
				pos[1][i % 2] = i;
			}
			int odd = max(pos[0][0], pos[1][1]);
			int even = max(pos[0][1], pos[1][0]);
			ans += i - min(odd, even);
		}
		cout << ans << '\n';
	}
	return 0;
}