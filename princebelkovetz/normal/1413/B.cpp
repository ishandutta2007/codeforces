#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 1e9 + 7;
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		vector <vector <int>> b(m, vector <int>(n));
		map <int, vector <int>> ok;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			ok[x] = {};
			for (int j = 0; j < m - 1; ++j) {
				int y; cin >> y;
				ok[x].push_back(y);
			}
		}
		int ind = -1;
		for (int i = 0; i < m; ++i) {
			int x; cin >> x;
			b[i][0] = x;
			if (ok.find(x) != ok.end())
				ind = i;
			for (int j = 0; j < n - 1; ++j) {
				int y; cin >> y;
				b[i][j + 1] = y;
			}
		}
		for (auto x : b[ind]) {
			cout << x << ' ';
			for (auto y : ok[x])
				cout << y << ' ';
			cout << '\n';
		}

	}
	return 0;
}