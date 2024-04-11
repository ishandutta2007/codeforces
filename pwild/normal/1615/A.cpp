#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		sum += x;
	}
	cout << (sum%n != 0) << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}