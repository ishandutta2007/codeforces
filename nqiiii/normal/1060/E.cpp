#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200000;
int n, sz[maxn + 10], dep[maxn + 10], sz2[maxn + 10], cnt1;
vector<int> g[maxn + 10];
ll ans;

void dfs(int p, int fa) {
	sz[p] = 1; dep[p] = dep[fa] ^ 1;
	cnt1 += dep[p];
	for (int i = 0; i < g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fa) {
			dfs(e, p); sz[p] += sz[e];
		}
	}
}

void dfsans(int p, int fa) {
	for (int i = 0; i < g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fa) {
			ans += 1ll * sz[e] * (sz[1] - sz[e]);
			dfsans(e, p);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);
	}
	dfs(1, 0);
	dfsans(1, 0);
	printf("%lld", (ans + 1ll * cnt1 * (n - cnt1)) / 2);
}