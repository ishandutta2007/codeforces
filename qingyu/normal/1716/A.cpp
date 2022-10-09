#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;
	auto f = [&](int n) {
		if (n % 3 == 0) {
			return abs(n) / 3;
		}
		return 0x3f3f3f3f;
	};
	while (T--) {
		int n;
		cin >> n;
		int ans = 0x3f3f3f3f;
		for (int i = -50; i <= 50; ++i)
			ans = min(ans, abs(i) + f(n + 2 * i));
		cout << ans << '\n';
	}
}