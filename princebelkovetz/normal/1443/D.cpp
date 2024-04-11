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
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		vector <int> dcr(n), incr(n);
		dcr[0] = a[0], incr[0] = 0;
		bool c = true;
		for (int i = 1; i < n; ++i) {
			dcr[i] = min(dcr[i - 1], a[i] - incr[i - 1]);
			incr[i] = a[i] - dcr[i];
			c &= incr[i] >= 0 && dcr[i] >= 0;
		}
		cout << (c ? "YES\n" : "NO\n");
	}
	return 0;
}