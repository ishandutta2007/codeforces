#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	char c;
	bool v[20] = {};
	cin >> n;
	while (n--) {
		cin >> c;
		if (c == 'L') {
			for (int i = 0; i <= 9; i++)
				if (!v[i]) {
					v[i] = 1;
					break;
				}
		} else if (c == 'R') {
			for (int i = 9; i >= 0; i--)
				if (!v[i]) {
					v[i] = 1;
					break;
				}
		} else v[c - '0'] = 0;
	}
	for (int i = 0; i <= 9; i++) cout << v[i];
	cout << '\n';
}