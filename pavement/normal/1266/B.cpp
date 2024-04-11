#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x < 15) cout << "NO\n";
		else if ((x - 15) % 14 == 0 || (x - 18) % 14 == 0 || (x - 19) % 14 == 0 || (x - 16) % 14 == 0 || (x - 17) % 14 == 0 || (x - 20) % 14 == 0) cout << "YES\n";
		else cout << "NO\n";
	}
}