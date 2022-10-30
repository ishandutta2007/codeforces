#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
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
#include <random>
#include <time.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

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

const int sz = 2e6 + 5, absz = 26;
int n, k, m;
string s;
ll dp[sz], p[sz];
int prv[absz];

int main() {
	fast;
	cin >> n >> k >> s;
	m = s.length();
	dp[0] = p[0] = 1;
	for (int i = 1; i <= m; i++) {
		dp[i] = subt(p[i - 1],(prv[s[i - 1] - 'a'] ? p[prv[s[i - 1] - 'a'] - 1] : 0));
		p[i] = add(p[i - 1], dp[i]);
		prv[s[i - 1] - 'a'] = i;
	}
	for (int i = m + 1; i <= m + n; i++) {
		int mn = 1e9, mnk = -1;
		for (int j = 0; j < k; j++) {
			if (prv[j] < mn) {
				mn = prv[j];
				mnk = j;
			}
		}
		dp[i] = subt(p[i - 1], (prv[mnk] ? p[prv[mnk] - 1] : 0));
		p[i] = add(p[i - 1], dp[i]);
		prv[mnk] = i;
	}
	ll ans = 0;
	for (int i = 0; i <= n + m; i++)iadd(ans, dp[i]);
	cout << ans;
	return 0;
}