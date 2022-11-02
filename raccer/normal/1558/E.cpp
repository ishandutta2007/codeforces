#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1010], b[1010];
vector <int> from[1010];
int vis[1010];
vector <int> path[1010];
vector <int> cur, ans;

int dfs(int x, int last, long long mid) {
	if (mid <= a[x]) return 0;
	if (path[x].size()) {
		ans = cur;
		for (int i = path[x].size() - 1; i >= 0; i--) {
			ans.push_back(path[x][i]);
		}
		return 1;
	}
	mid += b[x];
	cur.push_back(x);
	path[x] = cur;
	vis[x] = 1;
	for (auto v : from[x]) if (v != last) {
		if (vis[v]) {
			ans = cur;
			cur.pop_back();
			vis[x] = 0;
			return 1;
		}
		if (dfs(v, x, mid)) {
			cur.pop_back();
			vis[x] = 0;
			return 1;
		}
	}
	vis[x] = 0;
	cur.pop_back();
	return 0;
}

int Check(long long mid) {
	for (int i = 1; i <= n; i++) {
		vis[i] = 0;
	}
	vis[1] = 1;
	int tot = 1;
	while (tot < n) {
		ans.clear();
		for (int i = 1; i <= n; i++) {
			path[i].clear();
		}
		for (int x = 1; x <= n; x++) {
			if (!vis[x]) continue;
			cur.push_back(x);
			for (auto v : from[x]) {
				if (!vis[v]) {
					if (dfs(v, x, mid)) {
						cur.pop_back();
						goto END;
					}
				}
			}
			cur.pop_back();
		}
		return 0;
		END:;
		for (auto x : ans) {
			if (!vis[x]) mid += b[x], tot++;
			vis[x] = 1;
		}
	}
	return 1;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			from[i].clear();
		}
		for (int i = 2; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 2; i <= n; i++) {
			scanf("%d", &b[i]);
		}
		for (int i = 0; i < m; i++) {
			int x, y; scanf("%d%d", &x, &y);
			from[x].push_back(y);
			from[y].push_back(x);
		}
		int l = 0, r = 1000000001;
		while (l < r) {
			int mid = l + r >> 1;
			if (Check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}