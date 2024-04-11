#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#define int long long
#define ull unsigned long long
#define ld long double
#define debug(x) cout << #x << " is " << x << endl;
using namespace std;
struct p {
	int x, y;
};
bool cmp(p a, p b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y > b.y;
}
int gcd(int a, int b, int& x, int& y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
signed main() {
	int n, k; cin >> n >> k;
	int mod = 998244353;
	vector <p> a;
	int fact = 1;
	for (int i = 2; i < k; ++i) {
		fact = fact * i;
		fact %= mod;
	}
	int x, y;
	int g = gcd(fact, mod, x, y);
	fact = (x % mod + mod) % mod;
	vector <int> ok(n + 1, 1);
	for (int i = 0; i < k - 1; ++i) {
		ok[k - 1] *= k - 1 - i;
		ok[k - 1] %= mod;
	}
	for (int j = k; j <= n; ++j) {
		int e, f, got;
		int cc = gcd(j - k + 1, mod, e, f);
		assert(cc == 1);
		got = (e % mod + mod) % mod;
		ok[j] = ok[j - 1] * got;
		ok[j] %= mod;
		ok[j] *= j;
		ok[j] %= mod;
	}

	for(int i = 0, l, r; i < n; ++i) {
		cin >> l >> r;
		a.push_back({ l, 1 });
		a.push_back({ r, -1 });
	}
	sort(a.begin(), a.end(), cmp);
	int balance = 0, ans = 0;
	for (auto z : a) {
		if (z.y < 0) {
			if (balance >= k) {
				int c = k - 1, d = balance - 1;
				int res = ok[d];
				ans += res * fact;
				ans %= mod;
			}
		}
		balance += z.y; 
	}
	cout << ans << '\n';
	return 0;
}