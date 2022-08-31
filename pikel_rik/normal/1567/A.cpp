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

		string row;
		cin >> row;

		string ans;
		for (int i = 0; i < n; i++) {
			if (row[i] == 'U') {
				ans += 'D';
			} else if (row[i] == 'D') {
				ans += 'U';
			} else {
				ans += "LR";
				i += 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}