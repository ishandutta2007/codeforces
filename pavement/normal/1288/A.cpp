#include <bits/stdc++.h>
using namespace std;
#define int long long

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N, D;
	cin >> T;
	while (T--) {
		cin >> N >> D;
		if (D <= N) {
			cout << "YES\n";
			continue;
		}
		bool b = 0;
		for (int i = 1; i <= 100000; i++) {
			if (i + (int)ceil((double)D / (double)(i + 1)) <= N) {
				cout << "YES\n";
				b = 1;
				break;
			}
		}
		if (!b) cout << "NO\n";
	}
}