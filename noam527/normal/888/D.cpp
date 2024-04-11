#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - (y)]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll nck(int n, int k) {
	ll rtn = 1;
	for (int i = n; i > n - k; i--) rtn *= i;
	for (int i = 1; i <= k; i++) rtn /= i;
	return rtn;
}

int n, k;

int main() {
	fast;
	cin >> n >> k;
	ll ans = 1;
	if (k >= 2) ans += nck(n, 2);
	if (k >= 3) ans += 2 * nck(n, 3);
	if (k >= 4) ans += 9 * nck(n, 4);
	cout << ans << endl;
}