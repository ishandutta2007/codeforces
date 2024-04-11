#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN = 5e5 + 1;
int n, m, rs[mxN], nxt[mxN][20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	iota(rs, rs + mxN, 0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int l, r; cin >> l >> r;
		rs[l] = max(rs[l], r);
	}
	for (int i = 0; i < mxN; ++i) {
		if (i) rs[i] = max(rs[i], rs[i - 1]);
		nxt[i][0] = rs[i];
	}
	for (int j = 1; j < 20; ++j)
		for (int i = 0; i < mxN; ++i)
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
	for (int i = 0; i < m; ++i) {
		int l, r; cin >> l >> r;
		if (nxt[l][19] < r) {
			cout << "-1\n";
			continue;
		}
		int ans = 1;
		int cur = l;
		for (int j = 19; ~j; --j) {
			if (nxt[cur][j] < r) {
				ans += 1 << j;
				cur = nxt[cur][j];
			}
		}
		assert(nxt[cur][0] >= r);
		cout << ans << "\n";
	}
	return 0;
}