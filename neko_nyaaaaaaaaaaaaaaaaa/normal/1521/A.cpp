#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		int a, b; cin >> a >> b;
		if (b == 1) cout << "NO\n";
		else {
			cout << "YES\n";
			if (b == 2) {
				cout << a << ' ' << a*3 << ' ' << a*4 << '\n';
			} else {
				cout << a << ' ' << a*(b-1) << ' ' << a*b << '\n';
			}
		}
	}

	return 0;
}