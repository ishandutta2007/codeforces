#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod = 1e9 + 7;

void imult(ll& lhs, const ll& rhs) {
	lhs = ((lhs % mod) * (rhs % mod)) % mod;
}

void iadd(ll& lhs, const ll& rhs) {
	lhs = ((lhs%mod) + (rhs%mod)) % mod;
}

void isubt(ll& lhs, const ll& rhs) {
	ll ret = (lhs - rhs) % mod;
	lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll& lhs, const ll& rhs) {
	if (rhs == 0)return 1;
	ll ret = bpw(lhs, rhs >> 1);
	imult(ret, ret);
	if (rhs & 1) imult(ret, lhs);
	return ret;
}

ll inv(const ll& x) {
	return bpw(x, mod - 2);
}

ll mult(const ll& lhs, const ll& rhs) {
	return ((lhs % mod) * (rhs % mod)) % mod;
}

ll add(const ll& lhs, const ll& rhs) {
	return ((lhs%mod) + (rhs%mod)) % mod;
}

ll subt(const ll& lhs, const ll& rhs) {
	ll ret = (lhs - rhs) % mod;
	return ret + (ret < 0 ? mod : 0);
}

ll divi(const ll& lhs, const ll& rhs) {
	return mult(lhs, inv(rhs));
}

const int sz = 3e5;
int n;
pii lr[sz];
ll e[sz], ee[sz];

pii getSect(pii x, pii y) {
	if (x.ff > y.ss || y.ff > x.ss)return { -1,-2 };
	return { max(x.ff, y.ff), min(x.ss, y.ss) };
}

int sectSize(pii x) {
	return x.ss - x.ff + 1;
}

int main() {
	fast;
	cin >> n;
	foru(i, 0, n)cin >> lr[i].ff;
	foru(i, 0, n)cin >> lr[i].ss;
	foru(i, 0, n - 1) {
		e[i] = mult(divi(sectSize(getSect(lr[i], lr[i + 1])), lr[i].ss - lr[i].ff + 1), inv(lr[i + 1].ss - lr[i + 1].ff + 1));
		e[i] = subt(1, e[i]);
	}
	foru(i, 0, n - 2) {
		int len = sectSize(getSect(lr[i], getSect(lr[i + 1], lr[i + 2])));
		ll pboth = mult(divi(len, sectSize(lr[i])), mult(inv(sectSize(lr[i+1])), inv(sectSize(lr[i + 2]))));
		ee[i] = subt(add(e[i], e[i + 1]), subt(1, pboth));
	}
	ll ret = 0, tmp = 0;
	foru(i, 0, n - 1)iadd(ret, e[i]);
	foru(i, 0, n - 2)iadd(tmp, ee[i]);
	iadd(ret, mult(2, tmp));
	tmp = 0;
	foru(i, 0, n - 1)iadd(tmp, e[i]);
	imult(tmp, tmp);
	iadd(ret, tmp);
	tmp = 0;
	foru(i, 0, n - 2)iadd(tmp, mult(e[i], e[i + 1]));
	isubt(ret, mult(2, tmp));
	tmp = 0;
	foru(i, 0, n - 1)iadd(tmp, mult(e[i], e[i]));
	isubt(ret, tmp);
	iadd(ret, 1);
	foru(i, 0, n - 1)iadd(ret, 2 * e[i]);
	cout << ret << '\n';
	return 0;
}