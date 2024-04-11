#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[100][100];
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x = a[i][j] + i + j;
			if (x % 2) ++a[i][j];
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}