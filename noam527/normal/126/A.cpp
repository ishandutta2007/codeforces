#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ldb t1, t2, t0, mn;
int x1, x2;

int main() {
	fast;
	cin >> t1 >> t2 >> x1 >> x2 >> t0;
	if (t1 == t0) {
		if (t1 == t2) cout << x1 << " " << x2;
		else cout << x1 << " 0";
		return 0;
	}
	int y1 = 0, y2 = 1, b[2] = { 0, 1 };
	mn = t2;
	while (y1 <= x1 && y2 <= x2) {
		if ((y1 * t1 + y2 * t2) / (y1 + y2) >= t0) {
			if (mn >= (y1 * t1 + y2 * t2) / (y1 + y2)) {
				mn = (y1 * t1 + y2 * t2) / (y1 + y2);
				b[0] = y1, b[1] = y2;
			}
			y1++;
		}
		else {
			y2++;
		}
	}
	int mult = 1;
	while (b[0] * mult <= x1 && b[1] * mult <= x2) mult++;
	b[0] *= (mult - 1);
	b[1] *= (mult - 1);
	cout << b[0] << " " << b[1] << endl;
}