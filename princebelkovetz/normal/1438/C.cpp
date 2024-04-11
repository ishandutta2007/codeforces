#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <queue>
#include <cassert>
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int inf = 1e9 + 7;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n, m; cin >> n >> m;
		vector <vector <int>> a(n, vector <int>(m));
		for (auto& x : a)
			for (auto& y : x) cin >> y;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] % 2 != (i + j) % 2) cout << a[i][j] + 1 << ' ';
				else cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}