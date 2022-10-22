#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <cassert>
#include <map>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
const ld eps = 1e-7;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt--) {
		int n, l; cin >> n >> l;
		vector <int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (int i = 0; i < n; ++i)
			b[i] = l - a[n - i - 1];
		ld le = 0, ri = 1e9;
		while (le + eps < ri) {
			ld m = (le + ri) / 2;
			ld cur = m, spd = 1, lst = 0, tm = 0;
			for (int i = 0; i < n; ++i) {
				if (cur < a[i]) break;
				ld need = tm + (a[i] - lst) / spd;
				tm = need;
				spd++;
				cur += m - need;
				lst = a[i];
			}
			ld cur1 = m, spd1 = 1, lst1 = 0, tm1 = 0;
			for (int i = 0; i < n; ++i) {
				if (cur1 < b[i]) break;
				ld need = tm1 + (b[i] - lst1) / spd1;
				tm1 = need;
				spd1++;
				cur1 += m - need;
				lst1 = b[i];
			}
			if (cur + cur1 > l) ri = m;
			else le = m;
		}
		cout << le << '\n';
	}
}