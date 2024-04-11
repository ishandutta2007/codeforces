#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
		int a, b, n; cin >> a >> b >> n;
		if (n % 3 == 2) {
			cout << (a^b) << '\n';
		} else if (n % 3 == 0) {
			cout << a << '\n';
		} else {
			cout << b << '\n';
		}
    }

    return 0;
}