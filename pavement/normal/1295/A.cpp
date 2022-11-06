#include <bits/stdc++.h>
using namespace std;
#define int long long

int m[] = {-1, -1, 1, 7, 4, 5, 9};

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	for (cin >> t; t--; ) {
		cin >> n;
		cout << m[n - 2 * (n / 2 - 1)];
		for (int i = 0; i < n / 2 - 1; i++) cout << "1";
		cout << '\n';
	}
}