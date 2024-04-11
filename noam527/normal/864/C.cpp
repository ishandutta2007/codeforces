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
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 149;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll a, b, f, k, temp;

int main() {
	fast;
	cin >> a >> b >> f >> k;

	int ans = 0;

	if (f > b || a - f > b) return cout << -1 << endl, 0;
	if (k == 1) {
		if (a > b) return cout << 1 << endl, 0;
		cout << 0 << endl;
		return 0;
	}

	if (k > 2 && 2 * f > b) return cout << -1 << endl, 0;
	if (2 * (a - f) > b) return cout << -1 << endl, 0;

	temp = b - f;
	while (k > 2) {
		if (temp < 2 * (a - f)) ans++, temp = b;
		temp -= 2 * (a - f);

		if (temp < 2 * f) ans++, temp = b;
		temp -= 2 * f;

		k -= 2;
		
	}
	if (k == 1) {
		if (temp < a - f) ans++;
		return cout << ans << endl, 0;
	}
	if (temp < 2 * (a - f)) ans++, temp = b;
	temp -= 2 * (a - f);

	if (temp < f) ans++, temp = b;

	cout << ans << endl;
}