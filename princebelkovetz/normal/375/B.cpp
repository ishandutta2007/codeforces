#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(7);
	int n, m; cin >> n >> m;
	vector <string> a(n);
	for (auto& x : a) cin >> x;
	vector <vector <int>> seg(n, vector <int>(m, 0));
	for (int i = 0; i < n; ++i) {
		if (a[i][m - 1] == '1') seg[i][m - 1] = 1;
		for (int j = m - 2; j >= 0; --j) {
			if (a[i][j] == '1') seg[i][j] = seg[i][j + 1] + 1;
		}
	}
	int ans = 0;
	for (int j = 0; j < m; ++j) {
		vector <int> cnt(m + 2);
		for (int i = 0; i < n; ++i) {
			cnt[0]++;
			cnt[seg[i][j] + 1]--;
		}
		int cur = 0;
		for (int i = 0; i < m + 1; ++i) {
			cur += cnt[i];
			ans = max(ans, cur * i);
		}
	}
	cout << ans << '\n';
}