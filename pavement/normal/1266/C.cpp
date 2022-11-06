#include <bits/stdc++.h>
using namespace std;
#define int long long

int res[505][505];

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c, idx = 1;
	cin >> r >> c;
	if (r == 1 && c == 1) {
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			res[i][j] = 1;
	if (r <= c) {
		for (int i = 0; i < r; i++) {
			int tidx = idx++;
			for (int j = 0; j < c; j++)
				res[i][j] = lcm(res[i][j], tidx);
		}
		for (int i = 0; i < c; i++) {
			int tidx = idx++;
			for (int j = 0; j < r; j++)
				res[j][i] = lcm(res[j][i], tidx);
		}
	} else {
		for (int i = 0; i < c; i++) {
			int tidx = idx++;
			for (int j = 0; j < r; j++)
				res[j][i] = lcm(res[j][i], tidx);
		}
		for (int i = 0; i < r; i++) {
			int tidx = idx++;
			for (int j = 0; j < c; j++)
				res[i][j] = lcm(res[i][j], tidx);
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			cout << res[i][j] << ' ';
		cout << '\n';
	}
}