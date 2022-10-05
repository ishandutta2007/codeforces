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

ll s[3], e[3], x, y;

bool check() {
	ll t, k;
	if (x*x + y*y == 0) {
		if (x * (e[2] - s[2]) - y * (e[1] - s[1]) != 0) return false;
		k = 0;
	}
	else {
		if ((x * (e[2] - s[2]) - y * (e[1] - s[1])) % (x*x + y*y) != 0) return false;
		k = (x * (e[2] - s[2]) - y * (e[1] - s[1])) / (x*x + y*y);
	}
	// tx = ky + e1 - s1
	if (x == 0) {
		if (k * y + e[1] - s[1] != 0) return false;
		
		if (y == 0) {
			if (-k * x + e[2] - s[2] != 0) return false;
		}
		else {
			if ((-k * x + e[2] - s[2]) % y != 0) return false;
		}
	}
	else {
		if ((k * y + e[1] - s[1]) % x != 0) return false;
	}
	return true;
}

int main() {
	fast;
	cin >> s[1] >> s[2] >> e[1] >> e[2] >> x >> y;

	for (int i = 0; i < 4; i++) {
		if (check()) finish("YES");
		ll tmp = e[2];
		e[2] = e[1];
		e[1] = -tmp;
	}
	finish("NO");
}