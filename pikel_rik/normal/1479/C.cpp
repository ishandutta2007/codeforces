#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int l, r;
	cin >> l >> r;

	vector<tuple<int, int, int>> ans;
	for (int i = 19; i >= -1; i--) {
		for (int j = i - 1; j >= -1; j--) {
			ans.emplace_back(20 - i, 20 - j, (1 << (j + 1)));
		}
		ans.emplace_back(20 - i, 22, 1);
	}

	ans.emplace_back(0, 22, l);

	int target = r - l;
	for (int i = 19, now = l; i >= 0; i--) {
		if (target & (1 << i)) {
			ans.emplace_back(0, 20 - i + 1, now);
			now += (1 << i);
		}
	}

	cout << "YES\n" << 23 << ' ' << ans.size() << '\n';
	for (auto &[u, v, w] : ans) {
		cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
	}
	return 0;
}