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
#define ld double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const int mod = 1e18;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << fixed << setprecision(7);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <pair <int, int>> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i].first;
		for (int i = 0; i < n; ++i)
			cin >> a[i].second;
		sort(a.begin(), a.end());
		vector <int> pref(n + 1);
		for (int i = 1; i <= n; ++i)
			pref[i] = pref[i - 1] + a[i - 1].second;
		int ans = mod;
		for (int i = 0; i < n; ++i) {
			ans = min(ans, max(a[i].first, pref[n] - pref[i + 1]));
		}
		ans = min(ans, pref[n]);
		ans = min(ans, a[n - 1].first);
		cout << ans << '\n';
	}
	return 0;
}