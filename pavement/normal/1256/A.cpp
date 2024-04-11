#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);int q, a, b, n, s;
	cin >> q;
	while (q--) {
		cin >> a >> b >> n >> s;
		int x = min(a, s / n);
		if (x * n + b >= s) cout << "YES\n";
		else cout << "NO\n";
	}
}