#define _CRT_SECURE_NO_WARNINGS
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
#include <stack>
#include <map>

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
	return (lhs + rhs) % mod;
}

ll subt(const ll & lhs, const ll & rhs) {
	ll ret = (lhs - rhs) % mod;
	return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll & lhs, const ll & rhs) {
	return mult(lhs, inv(rhs));
}

const int sz = 1e6 + 5, LOG = 20, N = sz;
ll f[sz][LOG];

int lp[N + 1];
vector<int> pr;

void findPrimes() {
	for (int i = 2; i <= N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
			lp[i * pr[j]] = pr[j];
	}
}

void prec() {
	f[0][0] = 1;
	foru(i, 1, LOG) 
		f[0][i] = 2;
	foru(r, 1, sz) {
		f[r][0] = 1;
		foru(i, 1, LOG)
			f[r][i] = add(f[r - 1][i], f[r][i - 1]);
	}
	findPrimes();
}

int solve(int n, int r) {
	ll cur = 1;
	while (n!=1) {
		int curalpha = 0, mylp = lp[n];
		while (n!=1&&mylp == lp[n]) {
			curalpha++;
			n /= lp[n];
		}
		imult(cur, f[r][curalpha]);
	}
	return cur;
}

int main() {
	int q;
	scanf("%d", &q);
	prec();
	while (q--) {
		int n, r;
		scanf("%d %d", &r, &n);
		printf("%d\n", solve(n, r));
	}
	return 0;
}