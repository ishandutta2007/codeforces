#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int r, b, d;
		cin >> r >> b >> d;

		if (r > b) swap(r, b);
		cout << ((long long)r * (d + 1) >= b ? "YES" : "NO") << '\n';
	}
	return 0;
}