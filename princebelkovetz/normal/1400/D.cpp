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
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		vector <vector <int>> l(n, vector <int>(n)), r(n, vector <int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = n - 1; j >= i + 2; --j) {
				if (a[j] == a[i]) r[i][j]++;
				if (j != n - 1) r[i][j] += r[i][j + 1];
			}
			for (int j = 0; j <= i - 2; ++j) {
				if (a[j] == a[i]) l[i][j]++;
				if (j) l[i][j] += l[i][j - 1];
			}
		}
		int ans = 0;
		for (int i = 1; i < n; ++i) {
			for (int j = i + 1; j < n - 1; ++j) {
				ans += l[j][i - 1] * r[i][j + 1];
			}
		}
		cout << ans << '\n';
	}
}