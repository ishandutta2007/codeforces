#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
#include <string>
#include <queue>
#include <time.h>
#include <chrono>
#include <random>
#include <iomanip>
#include <map>
#include <numeric>
#include <complex>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, pair<pii, int>> einf;

const ll mod = 998244353;

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

ll divv(const ll & lhs, const ll & rhs) {
	return mult(lhs, inv(rhs));
}

const int sz = 5e5 + 5;
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

const int nsz = 5e3 + 5;
int n;
 //dp[i][j] currently putting i as even, used elements in the past

void solve() {
	cin >> n;
	vector<int> a(n);
	vector<pll> b;
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
	foru(i, 0, n)cin >> a[i];
	ll todiv = 1;
	ll cur = 1;
	foru(i, 1, n) {
		if (a[i] == a[i - 1])cur++;
		else {
			imult(todiv, finv[cur]);
			b.push_back({ a[i - 1],cur });
			cur = 1;
		}
	}
	imult(todiv, finv[cur]);
	b.push_back({ a[n - 1],cur });
	int m = b.size(), k = 3;
	vector<ll> psm(m, 0);
	foru(i, 0, m)psm[i] = add((i ? psm[i - 1] : 0), b[i].ss);
	vector<ll> sufdp(n + 1, 0);
	sufdp[n] = 1;
	ford(i, m - 1, 1) {
		if (i == m - 1) {
			if (b[i].ss == 1)dp[i][n - 1] = 1;
		}
		else {
			foru(j, 0, n - 2 + 1) {
				dp[i][j] = mult(mult(b[i].ss, max(psm[i - 1] - j, 0LL)), sufdp[j + 2]);
			}
		}
		foru(j, 0, n + 1)iadd(sufdp[j], dp[i][j]);
	}
	ll ans = 0;
	foru(i, 1, m)iadd(ans, mult(dp[i][1], psm[i - 1]));
	cout << mult(ans,todiv) << '\n';
}

int main() {
	fast;
	initf();
	int t;
	cin >> t;
	while (t--)solve();
	
	return 0;
}