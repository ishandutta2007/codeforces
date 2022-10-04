#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d", &(x), &(y))

using namespace std;
typedef long long ll;

const int MN = 100000;
const int LG = 16;

vector<int> adj[MN];
int cnt[MN];
ll sum[MN];
int vis[MN];
int anc[MN][LG + 1];
int rnk[MN];
ll parsum[MN];

int n;

void dfs(int i) {
	vis[i] = 1;
	int _cnt = 1;
	ll _sum = 0;
	for (auto &x : adj[i]) {
		if (vis[x]) continue;
		vis[x] = 1;
		anc[x][0] = i;
		rnk[x] = rnk[i] + 1;
		dfs(x);
		_cnt += cnt[x];
		_sum += cnt[x] + sum[x];
	}
	cnt[i] = _cnt;
	sum[i] = _sum;
}

void dfs2(int i, ll pp) {
	vis[i] = 1;
	pp += n - cnt[i];
	parsum[i] = pp;
	pp += sum[i];
	for (auto &x : adj[i]) {
		if (vis[x]) continue;
		dfs2(x, pp - sum[x] - cnt[x]);
	}
}

int goup(int x, int d) {
	for (int i = LG; i >= 0; i--) {
		if (d >= (1 << i)) {
			x = anc[x][i];
			d -= (1 << i);
		}
	}
	return x;
}

int lca(int x, int y) {
	if (rnk[x] < rnk[y]) swap(x, y);
	int dif = rnk[x] - rnk[y];
	x = goup(x, dif);
	if (x == y) return y;
	for (int i = LG; i >= 0; i--) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m; nii(n, m);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		nii(a, b);
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	anc[0][0] = -1;
	rnk[0] = 0;
	dfs(0);
	memset(vis, 0, sizeof(vis));
	dfs2(0, 0);
	for (int i = 1; i <= LG; i++) {
		for (int j = 0; j < n; j++) {
			int a = anc[j][i - 1];
			if (a == -1) anc[j][i] = -1;
			else anc[j][i] = anc[a][i - 1];
		}
	}
	ll tot = (ll)n*(n - 1) / 2;
	for (int i = 0; i < m; i++) {
		int u, v;
		nii(u, v); u--; v--;
		if (rnk[u] < rnk[v]) swap(u, v);
		int _lca = lca(u, v);
		if (_lca == v) {
			int _gg = goup(u, rnk[u] - rnk[v] - 1);
			int _cnt = n - cnt[_gg];
			ll _sum = sum[v] + parsum[v] - sum[_gg] - cnt[_gg];
			ll ans = 0;
			ans += (ll)(rnk[u] - rnk[v])*cnt[u] * _cnt;
			ans += cnt[u] * _sum + sum[u] * _cnt;
			printf("%.15f\n", (double)ans / cnt[u]/_cnt + 1);
		}
		else {
			ll ans = 0;
			ans += (ll)(rnk[u] + rnk[v] - 2 * rnk[_lca])*cnt[u] * cnt[v];
			ans += sum[u] * cnt[v] + sum[v] * cnt[u];
			printf("%.15f\n", (double)ans / cnt[u]/cnt[v] + 1);
		}
	}
	return 0;
}