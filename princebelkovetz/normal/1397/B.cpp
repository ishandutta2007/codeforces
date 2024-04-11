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
	int n; cin >> n;
	vector <int> a(n);
	for (auto& x : a) cin >> x;
	sort(a.begin(), a.end());
	int ans = 1e15;
	for (int i = 1; i <= 1000000; ++i) {
		int cur = 0, z = 1;
		bool c = true;
		for (int j = 0; j < n; ++j) {
			cur += abs(a[j] - z);
			z *= i;
			if (cur > ans) {
				c = false;
				break;
			}
		}
		if (!c) break;
		ans = min(ans, cur);
	}
	cout << ans << '\n';
}