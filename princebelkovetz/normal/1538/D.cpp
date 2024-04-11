#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>

using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#pragma GCC optimize("O3")
const int mod = 1e9 + 7;

int cnt(int a) {
	int res = 0;
	for (int i = 2; i * i <= a; ++i) {
		while (a % i == 0)
			res++, a /= i;
	}
	res += (a > 1);
	return res;
}

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		int a, b, k; cin >> a >> b >> k;
		int ax = cnt(a), bx = cnt(b);
		int g = gcd(a, b);
		if (k >= 2) {
			cout << (k <= ax + bx ? "Yes" : "No") << '\n';
		}
		else {
			cout << ((a == g) != (b == g) ? "Yes" : "No") << '\n';
		}
	}
}