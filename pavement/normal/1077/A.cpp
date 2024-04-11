#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, a, b, k;
	cin >> t;
	while (t--) {
		cin >> a >> b >> k;
		if (k & 1) cout << (a - b) * (k >> 1) + a << '\n';
		else cout << (a - b) * (k >> 1) << '\n';
	}
}