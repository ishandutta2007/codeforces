#include <bits/stdc++.h>
using namespace std;
#define int long long

bool r[105], b[105];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, t = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> r[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= 1000; i++) {
		int pta = 0, ptb = 0;
		for (int j = 1; j <= n; j++) {
			if (r[j] && b[j]) continue;
			if (r[j]) pta += i;
			if (b[j]) ptb++;
		}
		if (pta > ptb) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << "-1\n";
}