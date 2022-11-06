#include <bits/stdc++.h>
using namespace std;
 
int a[200005];
 
int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		bool ans = 0;
		for (int i = 1; i < n; i++) {
			if (abs(a[i] - a[i - 1]) >= 2) {
				cout << "YES\n" << i << ' ' << i + 1 << '\n';
				ans = 1;
				break;
			}
		}
		if (!ans) cout << "NO\n";
	}
}