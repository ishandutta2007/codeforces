#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		if (n == 1) cout << "-1\n";
		else {
			cout << 2;
			n--;
			while (n--) cout << 3;
			cout << '\n';
		}
	}
}