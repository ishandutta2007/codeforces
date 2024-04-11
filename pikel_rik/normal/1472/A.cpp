#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int w, h, n;
		cin >> w >> h >> n;

		int cw = 0, ch = 0;
		for (; w % 2 == 0; cw++, w /= 2);
		for (; h % 2 == 0; ch++, h /= 2);

		cout << ((1ll << (cw + ch)) >= n ? "YES" : "NO") << '\n';
	}
	return 0;
}