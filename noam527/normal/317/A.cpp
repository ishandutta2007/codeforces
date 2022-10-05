#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll x, y, m, ans = 0;

int main() {
	fast;
	cin >> x >> y >> m;

	if (max(x, y) >= m) return cout << 0 << endl, 0;
	if (max(x, y) <= 0) return cout << -1 << endl, 0;
	if (x < 0) ans += (-x + (x % y)) / y, x %= y;
	if (y < 0) ans += (-y + (y % x)) / x, y %= x;
	while (max(x, y) < m) {
		if (x > y) y += x;
		else x += y;
		ans++;
	}
	cout << ans << endl;
}