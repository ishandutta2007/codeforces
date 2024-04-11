#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	if (k > (n+1)/2) {
		cout << -1 << '\n';
		return;
	}

	vector<string> a(n, string(n,'.'));
	for (int i = 0; i < k; i++) {
		a[2*i][2*i] = 'R';
	}
	for (string s: a) cout << s << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}