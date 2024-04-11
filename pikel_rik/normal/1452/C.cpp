#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;

		int n = int(s.length());
		int c0 = 0, c1 = 0;

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') {
				c0++;
			} else if (s[i] == '[') {
				c1++;
			} else if (s[i] == ')') {
				if (c0) {
					c0--;
					ans++;
				}
			} else {
				if (c1) {
					c1--;
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}