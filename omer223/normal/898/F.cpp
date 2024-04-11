
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define pb push_back

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <numeric>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 999999937;
const int sz = 1e6 + 5;
string s;
ll p[sz], tpw[sz], tpwinv[sz];
int n;

void imult(ll & lhs, const ll & rhs) {
	lhs = ((lhs % mod) * (rhs % mod)) % mod;
}

void iadd(ll & lhs, const ll & rhs) {
	lhs = ((lhs % mod) + (rhs % mod)) % mod;
}

void isubt(ll & lhs, const ll & rhs) {
	ll ret = (lhs - rhs) % mod;
	lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll & lhs, const ll & rhs) {
	if (rhs == 0)return 1;
	ll ret = bpw(lhs, rhs >> 1);
	imult(ret, ret);
	if (rhs & 1) imult(ret, lhs);
	return ret;
}

ll inv(const ll & x) {
	return bpw(x, mod - 2);
}

ll mult(const ll & lhs, const ll & rhs) {
	return ((lhs % mod) * (rhs % mod)) % mod;
}

ll add(const ll & lhs, const ll & rhs) {
	return ((lhs % mod) + (rhs % mod)) % mod;
}

ll subt(const ll & lhs, const ll & rhs) {
	ll ret = (lhs - rhs) % mod;
	return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll & lhs, const ll & rhs) {
	return mult(lhs, inv(rhs));
}

void prec() {
	tpw[0] = 1;
	foru(i, 1, sz)tpw[i] = (tpw[i - 1] * 10) % mod;
	tpwinv[0] = 1;
	tpwinv[1] = bpw(10, mod - 2);
	foru(i, 2, sz)tpwinv[i] = mult(tpwinv[i - 1], tpwinv[1]);
}

ll query(int i, int j) {
	if (i > j)return 0;
	ll psm = subt(p[i], p[j + 1]);
	return mult(psm, tpwinv[n - j]);
}

void ans(int i, int o1) {
	foru(j, 0, i + 1)cout << s[j];
	cout << '+';
	foru(j, i + 1, o1)cout << s[j];
	cout << '=';
	foru(j, o1, n)cout << s[j];
	cout << '\n';
}

bool legal(int i, int o) {
	if ((s[0] == '0'&&i!=0) || (s[i + 1] == '0'&&o!=i+2) || (s[o] == '0'&&o!=n-1))return 0;
	return 1;
}

int main() {
	fast;
	cin >> s;
	n = s.length();
	prec();
	ford(i, n - 1, 0)p[i] = add(p[i + 1], mult(s[i] - '0',tpw[n - 1 - i]));
	foru(i, 0, n - 2) {
		int crlen = i + 1;
		int o1 = n - crlen, o2 = n - crlen - 1;
		if (2 * crlen < n) {
			if (add(query(0, i), query(i + 1, o1 - 1)) == query(o1, n - 1) and legal(i,o1)) {
				ans(i, o1);
				return 0;
			}
		}
		if (2 * crlen + 1 < n) {
			if (add(query(0, i), query(i + 1, o2 - 1)) == query(o2, n - 1) and legal(i,o2)) {
				ans(i, o2);
				return 0;
			}
		}
	}
	ford(o, n - 1, 0) {
		int crlen = n - o;
		int i1 = o - crlen - 1, i2 = o - crlen;
		if (i1 >= 0) {
			if (add(query(0, i1), query(i1 + 1, o - 1)) == query(o, n - 1) and legal(i1, o)) {
				ans(i1,o);
				return 0;
			}
		}
		if (i2 >= 0) {
			if (add(query(0, i2), query(i2 + 1, o - 1)) == query(o, n - 1) and legal(i2, o)) {
				ans(i2, o);
				return 0;
			}
		}
	}
	return 0;
}