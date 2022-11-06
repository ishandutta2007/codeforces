#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int maxN = 200000, mod = 1000000007;
int n, v[maxN + 10], sz[maxN + 10][2], dep[maxN + 10], ans;
vector<int> g[maxN + 10];

void Dfs(int p, int fa = 0) {
	++sz[p][dep[p]];
	for (int i = 0; i < g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fa) {
			dep[e] = dep[p] ^ 1; Dfs(e, p);
			sz[p][0] += sz[e][0]; sz[p][1] += sz[e][1];
		}
	}
}

void DfsAns(int p, int fa = 0) {
	int now0 = 1, now1 = 0; ans = (ans + v[p]) % mod;
	for (int i = 0; i < g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fa) {
			DfsAns(e, p);
			ans += 1ll * v[p] * now0 % mod * (sz[e][0] + sz[e][1]) % mod;
			ans %= mod;
			ans -= 1ll * v[p] * now1 % mod * (sz[e][0] + sz[e][1]) % mod;
			ans = (ans + mod) % mod;
			ans += 1ll * v[p] * sz[e][dep[p]] % mod * (now0 + now1) % mod;
			ans %= mod;
			ans -= 1ll * v[p] * sz[e][dep[p] ^ 1] % mod * (now0 + now1) % mod;
			ans = (ans + mod) % mod;
			now0 += sz[e][dep[p]]; now1 += sz[e][dep[p] ^ 1];
		}
	}
	int sz0 = sz[1][dep[p]] - sz[p][dep[p]], sz1 = sz[1][dep[p] ^ 1] - sz[p][dep[p] ^ 1];
	ans += 1ll * v[p] * now0 % mod * (sz0 + sz1) % mod;
	ans %= mod;
	ans -= 1ll * v[p] * now1 % mod * (sz0 + sz1) % mod;
	ans = (ans + mod) % mod;
	ans += 1ll * v[p] * sz0 % mod * (now0 + now1) % mod;
	ans %= mod;
	ans -= 1ll * v[p] * sz1 % mod * (now0 + now1) % mod;
	ans = (ans + mod) % mod;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &v[i]); v[i] = (v[i] + mod) % mod;
	}
	for (int i = 1; i < n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);
	}
	Dfs(1); DfsAns(1); printf("%d", ans);
}