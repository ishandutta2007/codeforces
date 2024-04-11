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

		string s = to_string(n);
		int ans = s.length() + 1;
		for (int i = 0; i <= 60; i++) {
			string two = to_string(1ll << i);
			int j = 0, k = 0;
			for (; k < (int) two.length() && j < (int) s.length(); j++) {
				if (s[j] == two[k]) {
					k++;
				}
			}
			ans = min(ans, (int) s.length() - k + (int) two.length() - k);
		}
		cout << ans << '\n';
	}
	return 0;
}