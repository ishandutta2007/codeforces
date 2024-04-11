#pragma warning(disable:4996)

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <iterator>
#include <random>
#include <time.h>
#include <tuple>
#include <functional>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))
#define mul(x,y) ((ll)(x)*(y)%mod)
#define mtp make_tuple
#define add(x,y) ((ll)(x)+(y))%mod
#define F(i,n) for(int i = 0; i < (n); i++)
#define FF(i,n) for(int i = 1; i <= (n); i++)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

const int N = 100000;
vector<pair<int, long long> > adj[N];

ll dp[N];
int rnk[N];
int vis[N];

vector<ll> CYC;
vector<int> cur;

void reduce() {
	vector<ll> CYC2 = CYC;
	vector<int> V;
	F(i, (int)CYC.size()) V.push_back(i);
	int m = CYC.size();
	int cur = 0;
	for (int i = 62; i >= 0 && cur < m; i--) {
		ll mask = 1LL << i;
		bool bb = true;
		for (int j = cur; j < m; j++) {
			if (CYC2[j] & mask) {
				swap(V[cur], V[j]);
				swap(CYC2[cur], CYC2[j]);
				bb = false;
				break;
			}
		}
		if (bb) {
			continue;
		}
		cur++;
		for (int j = cur; j < m; j++) {
			if (CYC2[j] & mask) {
				CYC2[j] = CYC2[j] ^ CYC2[cur - 1];
			}
		}
	}
	V.resize(cur);
	CYC2.resize(cur);
	F(i, cur) {
		CYC2[i] = CYC[V[i]];
	}
	CYC = CYC2;
}
void dfs(int i) {
	vis[i] = 1;
	cur.push_back(i);
	for (auto &x : adj[i]) {
		if (vis[x.first]) {
			if (rnk[x.first] < rnk[i]) {
				CYC.push_back(dp[x.first] ^ dp[i] ^ x.second);
			}
			continue;
		}
		dp[x.first] = dp[i] ^ x.second;
		rnk[x.first] = rnk[i] + 1;
		dfs(x.first);
	}
}
int vis2[N];
int dfs2(int i, int bit) {
	vis2[i] = 1;
	int ret = 0;
	for (auto &x : adj[i]) {
		if (vis2[x.first]) continue;
		ret += dfs2(x.first, bit);
	}
	if (dp[i] & (1LL << bit))ret++;
	return ret;
}

int modpow(int e) {
	if (e <= 62) return (1LL << e) % mod;
	int tmp = modpow(e / 2);
	tmp = mul(tmp, tmp);
	if (e & 1) tmp = mul(tmp, 2);
	return tmp;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n, m; nii(n, m);
	F(i, m) {
		int u, v; ll c;
		nii(u, v); u--; v--;
		scanf("%lld", &c);
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}
	auto nc2 = [](int n)->int {
		return (long long)n*(n - 1) / 2 % mod;
	};
	int ans = 0;
	for (int rt = 0; rt < n; rt++) {
		if (vis[rt]) continue;
		cur.clear();
		dfs(rt);
		reduce();
		for (int bit = 0; bit <= 62; bit++) {
			int cyc1 = 0;
			for (auto &x : CYC) {
				if (x & (1LL << bit)) cyc1++;
			}
			if (cyc1 != 0) {
				int NUM = mul(nc2((int)cur.size()), (1LL << (CYC.size() - 1))%mod);
				ans += mul(NUM, (1LL << bit) % mod);
				if (ans >= mod) ans -= mod;
				continue;
			}
			int cyc0 = CYC.size() - cyc1;
			for (auto &u : cur) vis2[u] = 0;
			int tree1 = dfs2(rt, bit);
			int tree0 = (int)cur.size() - tree1;

			ll T1 = (ll)tree0*tree1;
			int NUM = mul(T1%mod, (1LL << cyc0) % mod);
			ans += mul(NUM, (1LL << bit) % mod);
			if (ans >= mod) ans -= mod;
		}
		CYC.clear();
	}
	printf("%d\n", ans);
	return 0;
}