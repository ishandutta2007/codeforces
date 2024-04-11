#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int MN = 200000;
int n;
int ord[MN];
int a[MN];
int vis[MN];
int mx[MN];
int tp[MN];
int totalcnt[MN];
int dyn[MN];

vector<int> adj[MN];

int dfs(int i, int lb) {
	vis[i] = 1;
	int _cnt = 1;
	int _max1 = 0;
	int _tot = 1;
	int _notfullcnt = 0;
	for (auto &x : adj[i]) {
		if (vis[x]) continue;
		int ret = dfs(x, lb);
		_tot += totalcnt[x];
		if (tp[x]) {
			_cnt += ret;
		}
		else {
			_max1 = max(_max1, ret);
			_notfullcnt++;
		}
	}
	if (a[i] < lb) {
		mx[i] = 0;
		tp[i] = 0;
	}
	else {
		if (!_notfullcnt) tp[i] = 1;
		else tp[i] = 0;
		mx[i] = _cnt + _max1;
	}
	totalcnt[i] = _tot;
	return mx[i];
}

void dfs2(int i, int lb, int parcnt = 0) {
	vis[i] = 1;
	int ans = 1;
	int _notfull = 0;
	int _notfull2 = 0;
	if (a[i] < lb) {
		dyn[i] = 0;
		_notfull = _notfull2 = 0;
	}
	else {
		for (auto &x : adj[i]) {
			if (vis[x]) continue;
			if (tp[x]) ans += totalcnt[x];
			else {
				if (mx[x] > _notfull2) _notfull2 = mx[x];
				if (_notfull2 > _notfull) swap(_notfull, _notfull2);
			}
		}
		if (parcnt + totalcnt[i] == n) ans += parcnt;
		else {
			if (parcnt > _notfull2) _notfull2 = parcnt;
			if (_notfull2 > _notfull) swap(_notfull, _notfull2);
		}
		dyn[i] = ans + _notfull;
	}
	for (auto &x : adj[i]) {
		if (vis[x]) continue;
		if (a[i] < lb) {
			dfs2(x, lb, 0);
			continue;
		}
		if (tp[x]) {
			dfs2(x, lb, dyn[i] - totalcnt[x]);
		}
		else {
			if (mx[x] == _notfull) {
				dfs2(x, lb, dyn[i] - _notfull + _notfull2);
			}
			else dfs2(x, lb, dyn[i]);
		}
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		ord[i] = a[i] = x;
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v; scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	sort(ord, ord + n);
	int l = 0; int u = n - 1;
	while (l != u) {
		int m = (l + u + 1) / 2;
		dfs(0, ord[m]);
		memset(vis, 0, sizeof(vis));
		dfs2(0, ord[m]);
		int _M = 0;
		for (int i = 0; i < n; i++) {
			_M = max(_M, dyn[i]);
		}
		if (_M >= k) l = m;
		else u = m - 1;
		memset(tp, 0, sizeof(tp));
		memset(vis, 0, sizeof(vis));
	}
	printf("%d\n", ord[l]);

	return 0;
}