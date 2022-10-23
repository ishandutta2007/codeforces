#include <bits/stdc++.h>

using namespace std;

void solve() {
	bitset<1000> bs;
	bs[0] = 1;
	vector<int> f(15);
	for (int i = 1; i < 15; ++i) {
		bitset<1000> cur;
		cur |= bs << 1;
		cur |= bs << 5;
		cur |= bs << 10;
		cur |= bs <<50;
		f[i] = cur.count();
		bs = cur;
	}
	int n;
	cin >> n;
	cout << [&](int n) -> int64_t {
		if (n < 15)
			return f[n];
		// x_1 = 13, y_1 = f(13)
		// x_2 = 14, y_2 = f(14)
		int64_t k = f[14] - f[13];
		return f[13] + k * (n - 13);
	}(n) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T = 1;
	while (T--) {
		solve();
	}
	return 0;
}