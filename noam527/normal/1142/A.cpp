#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

ll gcd(ll x, ll y) {
	return !y ? x : gcd(y, x % y);
}

ll n, k, a, b;
ll mxg = 1, mng = inf;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k >> a >> b;

	ll st, en;
	st = a, en = b;
	while (en < st) en += k;
	for (int i = 0; i < n + 4; i++) {
		ll g = gcd(en - st, n * k);
		mxg = max(mxg, g);
		mng = min(mng, g);
		en += k;
	}

	st = a, en = -b;
	while (en < st) en += k;
	for (int i = 0; i < n + 4; i++) {
		ll g = gcd(en - st, n * k);
		mxg = max(mxg, g);
		mng = min(mng, g);
		en += k;
	}

	st = -a, en = b;
	while (en < st) en += k;
	for (int i = 0; i < n + 4; i++) {
		ll g = gcd(en - st, n * k);
		mxg = max(mxg, g);
		mng = min(mng, g);
		en += k;
	}

	st = -a, en = -b;
	while (en < st) en += k;
	for (int i = 0; i < n + 4; i++) {
		ll g = gcd(en - st, n * k);
		mxg = max(mxg, g);
		mng = min(mng, g);
		en += k;
	}
	cout << n * k / mxg << " " << n * k / mng << '\n';
}