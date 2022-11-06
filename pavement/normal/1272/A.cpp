#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q, a[3], c[3];
	cin >> q;
	while (q--) {
		int m = LLONG_MAX;
		cin >> a[0] >> a[1] >> a[2];
		for (int i = 0; i < (1<<6); i++) {
			for (int j = 0; j < 3; j++) c[j] = a[j];
			for (int j = 0; j < 6; j++)
				if (i & (1<<j)) c[j % 3]--;
			m = min(m, abs(c[0] - c[1]) + abs(c[0] - c[2]) + abs(c[1] - c[2]));
		}
		cout << m << '\n';
	}
}