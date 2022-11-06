#include <bits/stdc++.h>
using namespace std;
#define int long long

char c[50005];

main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a, b;
		for (int i = 1; i <= n; i++) cin >> c[i], c[i] -= '0';
		bool add = 0;
		for (int i = 1; i <= n; i++) {
			if (c[i] == 2) {
				if (add) b.push_back(2), a.push_back(0);
				else a.push_back(1), b.push_back(1);
			} else if (c[i] == 1) {
				if (add) b.push_back(1), a.push_back(0);
				else a.push_back(1), b.push_back(0), add = 1;
			} else a.push_back(0), b.push_back(0);
		}
		for (int i : a) cout << i;
		cout << '\n';
		for (int i : b) cout << i;
		cout << '\n';
	}
}