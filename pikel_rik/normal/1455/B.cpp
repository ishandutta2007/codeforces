#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e6;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int x;
		cin >> x;

		int n = 0, ans = 0;
		for (int i = 1;; i++) {
			n += i;
			ans++;
			if (n >= x) {
				break;
			}
		}
		cout << ans + (n == x + 1) << '\n';
	}
	return 0;
}