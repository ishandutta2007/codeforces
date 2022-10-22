#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <set>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#define int long long
#define endl "\n"
#define debug(x) cout << #x << " actually equals " << x << endl

using namespace std;
const int mxN = 1e5 + 7;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(3);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		string s = "";
		for (int i = 0; i < n; ++i) s += '0';
		vector <string> ans(n, s);
		for (int curdiag = 0; k > 0; curdiag++) {
			for (int j = 0; j < n && k > 0; ++j) {
				ans[(curdiag + j) % n][j] = '1';
				--k;
			}
		}
		int mincol = 1e9, maxcol = 0, minrow = 1e9, maxrow = 0;
		for (int i = 0; i < n; ++i) {
			int currow = 0;
			for (int j = 0; j < n; ++j) {
				if (ans[i][j] == '1') currow++;
			}
			minrow = min(minrow, currow);
			maxrow = max(maxrow, currow);
		}
		for (int i = 0; i < n; ++i) {
			int curcol = 0;
			for (int j = 0; j < n; ++j) {
				if (ans[j][i] == '1') curcol++;
			}
			mincol = min(mincol, curcol);
			maxcol = max(maxcol, curcol);
		}
		cout << (int)(pow((maxcol - mincol), 2) + pow((maxrow - minrow), 2)) << endl;
		for (auto x: ans) cout << x << endl;
	}
	return 0;
}