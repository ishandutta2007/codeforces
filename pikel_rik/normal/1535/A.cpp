#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		array<int, 4> a;
		for (auto &x : a) cin >> x;

		int mx1 = max(a[0], a[1]), mx2 = max(a[2], a[3]);
		if (mx1 > mx2) swap(mx1, mx2);

		sort(a.begin(), a.end());
		cout << (mx1 == a[2] && mx2 == a[3] ? "YES" : "NO") << '\n';
	}
	return 0;
}