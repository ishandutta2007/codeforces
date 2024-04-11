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

		string s;
		cin >> s;

		array<int, 2> cnt = {};

		vector<int> dp(n);
		map<pair<int, int>, int> last;

		for (int i = 0; i < n; i++) {
			if (s[i] == 'D') {
				cnt[0] += 1;
			} else {
				cnt[1] += 1;
			}
			int a = cnt[0], b = cnt[1];
			int g = __gcd(a, b);
			a /= g, b /= g;
			auto it = last.emplace(make_pair(a, b), -1).first;
			if (it->second == -1) {
				cout << (dp[i] = 1) << ' ';
			} else {
				cout << (dp[i] = 1 + dp[it->second]) << ' ';
			}
			it->second = i;
		}
		cout << '\n';
	}
	return 0;
}