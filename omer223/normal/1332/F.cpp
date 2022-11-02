#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second
#define chkmin(a, b) (a = ((a > b) ? b : a))
#define chkmax(a, b) (a = ((a < b) ? b : a))

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <set>
#include <map>
#include <random>
#include <memory>
#include <numeric>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef vector<int> vi;
typedef pair<ld, ld> pld;
typedef pair<ll, int> pdi;

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

const int sz = 3e5 + 5;
vector<int> adj[sz];
int n;
ll dpno[sz], dpyes[sz], dp[sz], dpcon[sz];

void dfs(int src, int prv) {
	ll dpnomul = 1, dpsum = 1, dpyesum = 1, dpmul = 1;
	bool noleaf = 0;
	for (int x : adj[src]) {
		if (x == prv)continue;
		dfs(x, src);
		noleaf = 1;
		imult(dpnomul, dpno[x]);
		imult(dpmul, dp[x]);
		imult(dpsum, dp[x] + dpcon[x]);
		imult(dpyesum, dpno[x] + dp[x]);
	}
	//isubt(dpsum, dpnomul);
	if (noleaf) {
		dpyes[src] = subt(dpyesum, dpmul);
		dpno[src] = dpsum;
		dpcon[src] = add(dpyesum, dpsum);
		dp[src] = add(dpyes[src], dpno[src]);
	}
	else {
		dpno[src] = 1;
		dp[src] = 1;
		dpcon[src] = 2;
		dpyes[src] = 0;
	}
}

int main() {
    fast;
    cin >> n;
    foru(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }
    dfs(0, -1);
	cout << subt(dp[0],1);
    return 0;
}