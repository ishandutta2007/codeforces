#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//4, 3 + 1, 2 + 2, 2 + 1 + 1, 1 + 1 + 1 + 1

	int n;
	cin >> n;

	vector<int> s(n);
	for (auto &x : s) cin >> x;

	array<int, 5> cnt = {0};
	for (auto &x : s) {
		cnt[x] += 1;
	}

	int ans = cnt[4];

	ans += cnt[3];
	cnt[1] = max(0, cnt[1] - cnt[3]);

	ans += cnt[2] / 2;
	cnt[2] %= 2;

	if (cnt[2] == 1) {
		ans += 1;
		cnt[1] = max(0, cnt[1] - 2);
	}

	ans += (cnt[1] + 3) / 4;

	cout << ans << '\n';
	return 0;
}