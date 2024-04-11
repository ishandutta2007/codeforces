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

int n, a[2000], mn = 2e9, g;
bool isone;

int main() {
	fast;
	cin >> n >> a[0];
	g = a[0], isone = (a[0] == 1);
	for (int i = 1; i < n; i++) cin >> a[i], g = gcd(a[i], g), isone = isone || a[i] == 1;
	if (g != 1) finish(-1);
	if (isone) {
		int cnt = 0;
		for (int i = 0; i < n; i++) if (a[i] == 1) cnt++;
		finish(n - cnt);
	}
	for (int i = 0, p, v; i < n; i++) {
		p = i + 1, v = a[i];
		while (p < n && v != 1)
			v = gcd(v, a[p++]);
		if (v == 1) mn = min(p - i - 1, mn);
	}
	cout << mn + n - 1 << endl;
}