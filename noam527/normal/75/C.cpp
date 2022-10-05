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

int a, b, n, l, r, g;
set<int> s;

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {
	fast;
	cin >> a >> b;
	g = gcd(a, b);
	for (int i = 1, lim = ceil(sqrt(g)); i <= lim; i++)
		if (g % i == 0) s.insert(i), s.insert(g / i);
	cin >> n;
	while (n--) {
		cin >> l >> r;
		auto it = s.upper_bound(r);
		int v = *(--it);
		if (v >= l) cout << v << endl;
		else cout << -1 << endl;
	}
}