#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const ll mod = 1e9 + 7;

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

const int sz = 3e5;
int n, m;
ll dp[sz][4]; //one zero, one one, two zero, two one
ll dpr[sz][2]; //diff as before, same

int main() {
	fast;
	cin >> n >> m;
	ll tot = 0;
	dp[0][0] = dp[0][1] = 1;
	foru(i, 1, m) {
		dp[i][0] = add(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = add(dp[i - 1][0], dp[i - 1][3]);
		dp[i][2] = dp[i - 1][0];
		dp[i][3] = dp[i - 1][1];
	}
	ll all = dp[m - 1][0] + dp[m - 1][1] + dp[m - 1][2] + dp[m - 1][3] - 2 + mod;
	all %= mod;
	iadd(tot, all);
	dpr[0][0] = 2;
	dpr[1][0] = 2;
	dpr[1][1] = 2;
	foru(i, 2, n) {
		dpr[i][0] = add(dpr[i - 1][1], dpr[i - 1][0]);
		dpr[i][1] = dpr[i - 1][0];
	}
	iadd(tot, add(dpr[n - 1][0], dpr[n - 1][1]));
	cout << tot;
	return 0;
}