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
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int diff_x = abs(x1 - x2), diff_y = abs(y1 - y2);
		if (diff_x > 0 and diff_y > 0) {
			cout << diff_x + diff_y + 2 << '\n';
		} else {
			cout << diff_x + diff_y << '\n';
		}
	}
	return 0;
}