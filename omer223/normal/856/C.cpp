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

const ll mod = 998244353;
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

int n;
vector<int> a[2];
const int sz = 2e3 + 5;

pair<int, bool> getData(int x) {
	string s = to_string(x);
	pair<pii, bool> ret{ {0,0},(bool)(s.length() & 1) };
	foru(i, 0, s.length()) {
		if (i & 1)ret.ff.ss += (s[i] - '0');
		else ret.ff.ff += (s[i] - '0');
	}
	ret.ff.ff %= 11;
	ret.ff.ss %= 11;
	return { (ret.ff.ff - ret.ff.ss + 11) % 11,ret.ss };
}

inline int neg(int x) {
	return (11 - x) % 11;
}

void input() {
	cin >> n;
	a[0].clear();
	a[1].clear();
	if (n == 1) {
		int tmp;
		cin >> tmp;
		cout << (tmp % 11 == 0 ? 1 : 0) << '\n';
		return;
	}
	foru(i, 0, n) {
		int tmp;
		cin >> tmp;
		auto r = getData(tmp);
		a[r.ss].pb(r.ff);
	}
}

ll factorial(ll n) {
	if (!n)return 1;
	return mult(n, factorial(n - 1));
}

ll calc(vector<ll> tmp) {
	vector<vector<ll>> dp(n + 1, vector<ll>(11, 0)), prv = dp;
	foru(k, 0, 11)
		prv[(a[1].size() + 1) / 2][k] = tmp[k];
	foru(i, 0, a[0].size()) {
		int val = a[0][i], places = a[1].size() + i + 1;
		foru(j, 0, n + 1) {
			foru(k, 0, 11) {
				dp[j][k] = add(mult(max(j - 1, 0), (j ? prv[j - 1][(k + val) % 11] : 0)),
					mult(max(0, places - j), prv[j][(k + neg(val)) % 11]));
			}
		}
		foru(j, 0, n + 1) {
			foru(k, 0, 11)
				prv[j][k] = dp[j][k], dp[j][k] = 0;
		}
	}
	ll ret = 0;
	foru(i, 0, n + 1)iadd(ret, prv[i][0]);
	return ret;
}

void solve() {
	input();
	if (n == 1)return;
	int e = a[0].size(), o = a[1].size();
	vector<vector<ll>> dp(o + 1, vector<ll>(11, 0)), prv = dp;
	prv[0][0] = 1;
	int sumall = 0;
	foru(i, 0, o) {
		sumall = (sumall + a[1][i]) % 11;
		foru(j, 0, o / 2 + 1) {
			foru(k, 0, 11)
				dp[j][k] = add(prv[j][k], (j ? prv[j - 1][(k + neg(a[1][i])) % 11] : 0));
		}
		foru(j, 0, o) {
			foru(k, 0, 11)
				prv[j][k] = dp[j][k], dp[j][k] = 0;
		}
	}
	ll fac = factorial(o / 2), com = factorial(o - o / 2);
	vector<ll> remp(11, 0), rem = remp;
	foru(i, 0, 11)
		iadd(remp[(sumall + 2 * neg(i)) % 11], prv[o / 2][i]);
	foru(i, 0, 11)
		imult(remp[i], mult(fac, com));
	cout << calc(remp) << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}