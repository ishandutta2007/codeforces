#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	auto ten = [](int x) -> long long {
		long long ans = 1;
		while (x--) {
			ans *= 10;
		}
		return ans;
	};

	while (t--) {
		int x1, p1, x2, p2;
		cin >> x1 >> p1 >> x2 >> p2;

		int sub = min(p1, p2);
		p1 -= sub, p2 -= sub;

		if (p1 >= 10) {
			cout << ">\n";
		} else if (p2 >= 10) {
			cout << "<\n";
		} else {
			long long y1 = x1 * ten(p1);
			long long y2 = x2 * ten(p2);
			if (y1 > y2) {
				cout << ">\n";
			} else if (y1 < y2) {
				cout << "<\n";
			} else {
				cout << "=\n";
			}
		}
	}
	return 0;
}