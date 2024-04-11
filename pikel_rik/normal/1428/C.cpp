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
		int n = s.length();

		int curA = 0, curB = 0, ans = n, front = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == 'A') {
				if (curA <= curB) {
					ans -= 2 * curA;
					front += curB - curA;
					curA = 0, curB = 0;
				} else {
					ans -= 2 * curB;
					curA = curA - curB;
					curB = 0;
				}
				curA++;
			} else {
				curB++;
			}
		}

		if (curA <= curB) {
			ans -= 2 * curA;
			front += curB - curA;
		} else {
			ans -= 2 * curB;
		}

		ans -= 2 * (front / 2);
		cout << ans << '\n';
	}
	return 0;
}