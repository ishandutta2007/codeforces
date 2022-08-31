#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;

		string moves;
		cin >> moves;

		int cur_x = 0, cur_y = 0;

		int mn_x = 0, mx_x = 0;
		int mn_y = 0, mx_y = 0;

		int ans_x = -1, ans_y = -1;
		for (auto move : moves) {
			if (move == 'L') {
				cur_y -= 1;
				mn_y = min(mn_y, cur_y);
			} else if (move == 'R') {
				cur_y += 1;
				mx_y = max(mx_y, cur_y);
			} else if (move == 'D') {
				cur_x += 1;
				mx_x = max(mx_x, cur_x);
			} else if (move == 'U') {
				cur_x -= 1;
				mn_x = min(mn_x, cur_x);
			}
			if (mx_x - mn_x + 1 > n || mx_y - mn_y + 1 > m) {
				if (move == 'L') {
					mn_y += 1;
				} else if (move == 'U') {
					mn_x += 1;
				}
				ans_x = -mn_x;
				ans_y = -mn_y;
				break;
			}
		}

		if (ans_x == -1) {
			ans_x = -mn_x;
			ans_y = -mn_y;
		}

		cout << ans_x + 1 << ' ' << ans_y + 1 << '\n';
	}
	return 0;
}