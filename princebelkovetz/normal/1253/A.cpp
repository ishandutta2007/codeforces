#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define endl "\n";
#define int long long
using namespace std;

void solve() {
	int n, x = 0;
	cin >> n;
	vector <int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			if (!x) {
				x = b[i] - a[i];
			}
			else if (b[i] - a[i] != x or b[i - 1] - a[i - 1] != x) {
				cout << "NO\n";
				return;
			}
		}

	}
	if (x < 0) cout << "NO\n";
	else cout << "YES\n";
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(15);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}