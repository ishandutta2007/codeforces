#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;

	if (k == 1) {
		cout << "YES" << '\n';
		for (int i = 1; i <= n; i++) {
			cout << i << '\n';
		}
	} else if (n%2 == 0) {
		cout << "YES" << '\n';
		for (int i = 0; i < n; i++) {
			int s = i%2 + (i/2)*(2*k) + 1;
			for (int j = 0; j < k; j++, s += 2) {
				cout << s << " \n"[j+1==k];
			}
		}
	} else {
		cout << "NO" << '\n';
	}
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}