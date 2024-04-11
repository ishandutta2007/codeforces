#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	string s; cin >> s;
	
	int m = min(20,k);
	vector<bool> forbidden(1 << m);
	
	int run = 0;
	for (int i = 0; i <= n-m; i++) {
		if (run >= k-m) {
			int mask = 0;
			for (int j = 0; j < m; j++) {
				mask = 2*mask + '1'-s[i+j];
			}
			forbidden[mask] = true;
		}
		run = s[i] == '1' ? run+1 : 0;
	}

	for (int mask = 0; mask < (1 << m); mask++) {
		if (forbidden[mask]) continue;
		cout << "YES\n";
		cout << string(k-m,'0');
		for (int j = m-1; j >= 0; j--) cout << ((mask >> j) & 1);
		cout << '\n';
		return;
	}
	cout << "NO\n";
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}