#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;

		constexpr int n = 10;

		string t = s;

		int time = 10;
		for (int f = 0; f < 2; f++) {
			for (int i = 0; i < n; i++) {
				if (s[i] == '?') {
					t[i] = '0' + (i % 2 == f);
				}
			}

			int diff = 0;
			for (int i = 0; i < n; i++) {
				if (t[i] == '1') {
					if (i % 2 == 0) {
						diff += 1;
					} else {
						diff -= 1;
					}
				}
				int remaining0 = (10 - i - 1) / 2;
				int remaining1 = 10 - i - 1 - remaining0;

				if (diff - remaining1 > 0) {
					time = min(time, i + 1);
				} else if (diff + remaining0 < 0) {
					time = min(time, i + 1);
				}
			}
		}
		cout << time << '\n';
	}
	return 0;
}