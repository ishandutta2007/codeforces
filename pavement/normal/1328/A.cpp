#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int u = ((a + b - 1) / b) * b;
		cout << abs(a - u) << '\n';
	}
}