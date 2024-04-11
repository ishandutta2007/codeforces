#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int px, py;
		cin >> px >> py;

		string s;
		cin >> s;

		int x = 0, y = 0;
		for (char &ch : s) {
			if (ch == 'U') {
				y += 1;
			} else if (ch == 'D') {
				y -= 1;
			} else if (ch == 'R') {
				x += 1;
			} else {
				x -= 1;
			}
		}

		x -= px, y -= py;
		bool f = true;
		if (x > 0) {
			f &= count(s.begin(), s.end(), 'R') >= x;
		} else if (x < 0) {
			f &= count(s.begin(), s.end(), 'L') >= -x;
		}

		if (y > 0) {
			f &= count(s.begin(), s.end(), 'U') >= y;
		} else if (y < 0) {
			f &= count(s.begin(), s.end(), 'D') >= -y;
		}

		cout << (f ? "YES" : "NO") << '\n';
	}
	return 0;
}