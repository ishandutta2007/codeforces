#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
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

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int n, a[1000], b[2000];
set<int> s;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], s.insert(a[i]);
	if (n == 1) {
		cout << "1\n" << a[0] << endl;
		return 0;
	}
	if (n == 2) {
		if (gcd(a[0], a[1]) < min(a[0], a[1])) finish(-1);
		cout << "2\n" << a[0] << " " << a[1] << endl;
		return 0;
	}
	for (int i = 0; i < 2 * n; i++) {
		if (i & 1) b[i] = a[0];
		else b[i] = a[i / 2];
	}
	for (int i = 0, g; i < 2 * n; i++) {
		g = b[i];
		for (int j = i + 1; j < 2 * n; j++) {
			g = gcd(g, b[j]);
			if (s.find(g) == s.end()) finish(-1);
		}
	}
	cout << 2 * n << endl;
	for (int i = 0; i < 2 * n; i++) cout << b[i] << " "; cout << endl;
}