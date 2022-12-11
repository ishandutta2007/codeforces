#include <bits/stdc++.h>

using namespace std;

//#define int long long
#define sz(x) ((int) (x).size())

void solve() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	vector<vector<char>> g(20, vector<char>(20));
	for (int i = 0; i < n; ++i) {
		if (a[i] > b[i]) {
			cout << -1 << '\n';
			return;
		} else if (a[i] < b[i]) {
			g[a[i] - 'a'][b[i] - 'a'] = true;
			g[b[i] - 'a'][a[i] - 'a'] = true;
		}
	}
	for (int k = 0; k < 20; ++k) {
		for (int i = 0; i < 20; ++i) {
			for (int j = 0; j < 20; ++j) {
				g[i][j] |= g[i][k] & g[k][j];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < i; ++j) {
			if (g[j][i]) {
				++ans;
				break;
			}
		}
	}
	cout << ans << '\n';
}

signed main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}