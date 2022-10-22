#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int read() {
	string s; cin >> s;
	int res = 0;
	for (char c : s) {
		res <<= 1;
		res += c - '0';
	}
	return res;
}

int n, m, q, w[12], cnt[1 << 12], c[1 << 12], ans[1 << 12][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) cin >> w[i];
	for (int i = 0; i < m; ++i) ++cnt[read()];
	for (int i = 0; i < (1 << n); ++i) for (int j = 0; j < n; ++j) if (!(i & (1 << j))) c[i] += w[n - j - 1];
	for (int i = 0; i < (1 << n); ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			int x = c[i ^ j];
			if (x <= 100) ans[i][x] += cnt[j];
		}
		for (int j = 1; j <= 100; ++j) ans[i][j] += ans[i][j - 1];
	}
	for (int i = 0; i < q; ++i) {
		int a = read();
		int b; cin >> b;
		cout << ans[a][b] << "\n";
	}
	return 0;
}