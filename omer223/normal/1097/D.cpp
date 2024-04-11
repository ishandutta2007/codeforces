#define _CRT_SECURE_NO_WARNINGS
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
#include <list> 
#include <queue> 
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> dat;

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
ll divv(const ll& lhs, const ll& rhs) {
	return mult(lhs, inv(rhs));
}

vector<pll> factor(ll x) {
	vector<pll> ret;
	for (ll i = 2; i * i <= x; i++) {
		if (x%i == 0) {
			int cnt = 0;
			while (x%i == 0) {
				x /= i;
				cnt++;
			}
			ret.pb({ i,cnt });
		}
	}
	if (x != 1)ret.pb({ x,1 });
	return ret;
}

const int szk = 1e4 + 5, LOG = 50;
ll dp[szk][LOG];

ll foo(pll ii, int k) {
	ll p = ii.ff;
	int occ = ii.ss;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= occ; j++)
			dp[i][j] = 0;
	}
	ll crpw = 1;
	for (int j = 0; j <= occ; j++)
		dp[0][j] = crpw, imult(crpw, p);
	for (int i = 1; i <= k; i++) {
		ll crsm = 0;
		for (int j = 0; j <= occ; j++) {
			iadd(crsm, dp[i - 1][j]);
			dp[i][j] = divv(crsm, j + 1);
		}
	}
	return dp[k][occ];
}

int main() {
	fast;
	ll n, k;
	cin >> n >> k;
	vector<pll> f = factor(n);
	ll ret=1;
	for (pll fa : f) {
		if (ret == -1)ret = foo(fa, k);
		else imult(ret, foo(fa, k));
	}
	cout << ret << '\n';
	return 0;
}