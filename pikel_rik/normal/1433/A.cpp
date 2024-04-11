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

	function<int(int, int)> make = [&] (int x, int l) -> int {
		int ans = 0;
		while (l--) {
			ans = 10 * ans + x;
		}
		return ans;
	};

	int t;
	cin >> t;

	while (t--) {
		int x;
		cin >> x;

		bool done = false;
		int c = 0;
		for (int i = 1; i <= 9; i++) {
			for (int l = 1; l <= 4; l++) {
				int ans = make(i, l);
				c += l;
				if (x == ans) {
					done = true;
					break;
				}
			}
			if (done) {
				break;
			}
		}
		cout << c << '\n';
	}
	return 0;
}