#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, x, y;
	cin >> n >> x >> y;

	const vector<string> ans = {"Vanya", "Vova", "Both"};

	vector<int> num(x + y + 1);
	num[0] = 2;

	long long cur_x = 0, cur_y = 0;
	for (int i = 1; i < x + y; i++) {
		if ((cur_x + 1) * y < x * (cur_y + 1)) {
			cur_x += 1;
			num[i] = 0;
		} else if ((cur_x + 1) * y > x * (cur_y + 1)) {
			cur_y += 1;
			num[i] = 1;
		} else {
			cur_x += 1, cur_y += 1;
			num[i] = num[i + 1] = 2;
			i += 1;
		}
	}

	while (n--) {
		int amt;
		cin >> amt;

		amt %= (x + y);
		cout << ans[num[amt]] << '\n';
	}
	return 0;
}