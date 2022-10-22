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
	cout << fixed << setprecision(4);
		int n; cin >> n;
		vector <vector <int>> a(n, vector <int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i & 1) a[i][j] = 0;
				else a[i][j] = pow(2, (i + j));
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
		int q; cin >> q;
		while (q--) {
			int x; cin >> x;
			vector <pair <int, int>> ans;
			x /= 2;
			pair <int, int> cur = { 0 , 0 };
			ans.push_back(cur);
			while (ans.size() != n + n - 1) {
				if (x % 2 == 0 and cur.second < n - 1 and a[cur.first][cur.second + 1] == 0) {
					cur.second++;
					ans.push_back(cur);
				}
				else if (x % 2 != 0 and cur.second < n - 1 and a[cur.first][cur.second + 1] != 0) {
					cur.second++;
					ans.push_back(cur);
				}
				else {
					cur.first++;
					ans.push_back(cur);
				}
				x /= 2;
			}
			for (auto x : ans) cout << x.first + 1 << ' ' << x.second + 1 << endl;
		}
}