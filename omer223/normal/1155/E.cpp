#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll mod = 1e6 + 3;

ll modpow(ll a, ll b) {
	if (!b)return 1;
	ll tmp = modpow(a, b >> 1);
	tmp *= tmp;
	tmp %= mod;
	if (b & 1) {
		tmp *= a;
		tmp %= mod;
	}
	return tmp;
}

inline ll inv(ll x) {
	x %= mod;
	if (x < 0)x += mod;
	return modpow(x, mod - 2);
}

vector<ll> polyMult(const vector<ll>& lhs, const vector<ll>& rhs) {
	int n = lhs.size() - 1, m = rhs.size() - 1;
	vector<ll> ret(n + m + 1, 0);
	int k;
	for (int i = 0; i <= n + m; i++) {
		for (int j = 0; j <= n; j++) {
			k = i - j;
			if (k<0 || k>m)continue;
			ret[i] += (lhs[j] * rhs[k]);
			ret[i] %= mod;
		}
	}
	return ret;
}

vector<ll> polyAdd(const vector<ll>& lhs, const vector<ll>& rhs) {
	int n = lhs.size() - 1, m = rhs.size() - 1, addSize = max(n, m) + 1;
	vector<ll> ret(addSize, 0);
	for (int i = 0; i < addSize; i++) {
		if (i <= n)ret[i] += lhs[i];
		if (i <= m)ret[i] += rhs[i];
		ret[i] %= mod;
	}
	return ret;
}

vector<ll> coeffMult(const vector<ll>& poly, const ll& num) {
	vector<ll> ret(poly.size(), 0);
	for (int i = 0; i < poly.size(); i++) {
		ret[i] = poly[i] * num;
		ret[i] %= mod;
	}
	return ret;
}

ll sub(const vector<ll>& poly, const ll& num) {
	ll tot = 0, numMult = 1;
	for (ll coeff : poly) {
		tot += coeff * numMult;
		numMult *= num;
		numMult %= mod;
		tot %= mod;
	}
	return tot;
}

vector<ll> interpolation(const vector<pll>& pts) {
	int n = pts.size();
	vector<ll> ret(1, 0);
	vector<ll> linear(2, 0);
	linear[1] = 1;
	for (int i = 0; i < n; i++) {
		vector<ll> cr(1, 0);
		ll coeff = 1;
		cr[0] = 1;
		for (int j = 0; j < n; j++) {
			if (i == j)continue;
			linear[0] = mod - pts[j].first;
			cr = polyMult(cr, linear);
			coeff *= inv(pts[i].first - pts[j].first);
			coeff %= mod;
		}
		ret = polyAdd(ret, coeffMult(coeffMult(cr, coeff), pts[i].second));
	}
	return ret;
}

ll ask(ll x) {
	cout << "? " << x << endl;
	fflush(stdout);
	ll ans;
	cin >> ans;
	return ans;
}

void answer(ll ans) {
	cout << "! " << ans << endl;
	fflush(stdout);
}

int main() {
	fast;
	vector<pll> pts;
	int tmp;
	for (int x = 0; x <= 10; x++) {
		tmp = ask(x);
		pts.pb({ x,tmp });
		if (tmp == -1)return 0;
	}
	vector<ll> poly = interpolation(pts);
	for (int x = 0; x < mod; x++) {
		if (sub(poly, x) == 0) {
			answer(x);
			return 0;
		}
	}
	answer(-1);
	return 0;
}

/*
1
7
17
31
49
71
97
127
161
199
241
*/