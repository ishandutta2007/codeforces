#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#define endl "\n"
#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const ld eps = 1e-13;
signed main(int kostya_luchinkin_gay) {
	int n, m, k, curx = 1;
	vector <pair <int, int>> ans;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) 
		for (int j = 1; j <= m; ++j) {
			if (i & 1) ans.push_back({ i, j });
			else ans.push_back({ i, m - j + 1 });
		}
	for (int i = 0; i < 2 * k - 2; i += 2) {
		cout << "2 " << ans[i].first << ' ' << ans[i].second;
		cout << " " << ans[i + 1].first << ' ' << ans[i + 1].second << endl;
	}
	cout << n * m - 2 * k + 2 << ' ';
	for (int i = 2 * k - 2; i < n * m; ++i)
		cout << ans[i].first << ' ' << ans[i].second << ' ';
	
	
	return 0;
}