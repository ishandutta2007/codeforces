#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define int long long
#define debug(x) cout << #x << " equals " << x << '\n'; 
const int mod = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases;
	cin >> testcases;
	while (testcases --> 0) {
		int n, m; cin >> n >> m;
		vector <int> a(n), b(m);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		int cnt = 0;
		for (auto x : a) {
			for (auto y : b)
				if (y == x) cnt++;
		}
		cout << cnt << '\n';
	}
}