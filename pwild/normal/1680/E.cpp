#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<string> a(n, string(2,'?'));
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < n; i++) {
			cin >> a[i][j];
		}
	}

	for (int dir = 0; dir < 2; dir++) {
		while (a[n-1] == "..") {
			a.pop_back(), n--;
		}
		reverse(begin(a), end(a));
	}

	int x = 1e8, y = 1e8, z = 0;
	for (string s: a) {
		int nx = s[1] == '.' ? 1 + min(x,z) : 1e8;
		int ny = s[0] == '.' ? 1 + min(y,z) : 1e8;
		int nz = 2 + min(min(x,y),z);
		tie(x,y,z) = make_tuple(nx,ny,nz);
	}

	int res = min(min(x,y),z) - 1;
	cout << res << '\n';
}

int main() {
	int tc; cin >> tc;
	while (tc--) solve();
}