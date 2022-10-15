/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0;
		for (int bit = 0; bit < 9; bit++) {
			vector<int> a, b;
			for (int i = 1; i <= n; i++) {
				if (((i >> bit) & 1) == 0) {
					a.push_back(i);
				} else {
					b.push_back(i);
				}
			}
			if (a.empty() || b.empty()) continue;
			cout << a.size() << ' ' << b.size();
			for (int i : a) cout << ' ' << i;
			for (int i : b) cout << ' ' << i;
			cout << endl;
			cout.flush();
			int s;
			cin >> s;
			if (s == -1) return 0;
			ans = std::max(ans, s);
		}
		cout << "-1 " << ans << endl;
		cout.flush();
	}
}