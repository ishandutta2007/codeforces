#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=1e5;
int n, m, cnt[mxN], ans[9];
vector<ar<int, 2>> row[mxN], col[mxN], d1[2*mxN], d2[2*mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		int r, c; cin >> r >> c, --r, --c;
		row[r].push_back({c, i});
		col[c].push_back({r, i});
		d1[c-r+n-1].push_back({r, i});
		d2[c+r].push_back({r, i});
	}
	auto solve=[&](vector<ar<int, 2>> &v) {
		sort(v.begin(), v.end());
		int s=v.size();
		for (int i=0; i<s; ++i) {
			if (i-1>=0) ++cnt[v[i][1]];
			if (i+1<s) ++cnt[v[i][1]];
		}
	};
	for (int i=0; i<n; ++i) {
		solve(row[i]);
		solve(col[i]);
	}
	for (int i=0; i<2*n; ++i) {
		solve(d1[i]);
		solve(d2[i]);
	}
	for (int i=0; i<m; ++i) {
		++ans[cnt[i]];
	}
	for (int i=0; i<=8; ++i) {
		cout << ans[i] << " ";
	}
	return 0;
}