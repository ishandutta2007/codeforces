#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k, s, p = 1;
	bool f = 0;
	cin >> n >> k >> s;
	if (s < k || (n - 1) * k < s) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = k - 1; i >= 0; i--) {
		int d = min(n - 1, s - i);
		if (!f) p += d;
		else p -= d;
		f = !f;
		s -= d;
		cout << p << ' ';
	}
	cout << '\n';
}