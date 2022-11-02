#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const ll mod = 1e9 + 7;

void imult(ll & lhs, const ll & rhs) {
	lhs = (lhs * rhs) % mod;
}

void iadd(ll & lhs, const ll & rhs) {
	lhs = (lhs + rhs) % mod;
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
	return (lhs * rhs) % mod;
}

ll add(const ll & lhs, const ll & rhs) {
	return (lhs + rhs) % mod;
}

ll subt(const ll & lhs, const ll & rhs) {
	ll ret = (lhs - rhs) % mod;
	return ret + (ret < 0 ? mod : 0);
}

const int sz = 1e6 + 5;
ll f[sz], finv[sz];

void initf() {
	f[0] = 1;
	foru(i, 1, sz)f[i] = mult(i, f[i - 1]);
	finv[sz - 1] = bpw(f[sz - 1], mod - 2);
	ford(i, sz - 2, 0)finv[i] = mult(finv[i + 1], i + 1);
}

ll chs(int n, int k) {
	if (n < k)return 0;
	else if (n < 0)return 0;
	return mult(f[n], mult(finv[k], finv[n - k]));
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	ll cur = m, sm = 0;
	for (int i = 0; i < n; i++) {
		ll ele;
		if (cur < 0)ele = 0;
		else ele = mult(2 * k, cur);
		iadd(sm, mult(ele,chs(n, i)));
		cur--;
	}
	ll ans = mult(sm, inv(bpw(2, n)));
	cout << ans << '\n';
}

int main() {
    fast;
	initf();
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}