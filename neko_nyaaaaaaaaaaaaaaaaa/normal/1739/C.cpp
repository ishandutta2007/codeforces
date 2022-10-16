#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 998244353;

int nCk[61][61];

pair<int, int> solve(int n) {
	if (n == 2) {
		return {1, 0};
	} else {
		auto [a, b] = solve(n-2);
		return {(nCk[n-1][n/2] + b) % M, (nCk[n-2][n/2] + a) % M};
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	nCk[0][0] = 1;
	for (int i = 1; i <= 60; i++) {
		nCk[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			nCk[i][j] = (nCk[i-1][j] + nCk[i-1][j-1]) % M;
		}
	}

	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		auto [a, b] = solve(n);
		cout << a << ' ' << b << " 1\n";
	}

	return 0;
}