#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
typedef long long ll;

int first[N], cur;
struct Edge {int nxt, to;} e[N << 2];
void con(int x, int y) {
	e[++cur] = (Edge){first[x], y};
	first[x] = cur;
}

int n, m, a[N], b[N], vis[N], ct, fr[N];
ll nw;

void get(int x) {
	while (!vis[x]) ct++, nw += b[x], vis[x] = 1, x = fr[x];
}

int dfs(int x, int fa, ll s) {
	for (int i = first[x]; i; i = e[i].nxt) {
		int v = e[i].to; if (v == fa) continue;
		if (!vis[x] && vis[v]) return get(x), 1;
		if (vis[v] || s <= a[v]) continue;
		if (fr[v]) return get(v), get(x), 1;
		fr[v] = x;
		if (dfs(v, x, s + b[v])) return 1;
	}
	return 0;
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++)
		scanf("%d", &b[i]);
	cur = 1;
	for (int i = 1; i <= n; i++)
		first[i] = 0;
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		con(u, v), con(v, u);
	}
	int l = 1, r = 1e9 + 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		for (int i = 1; i <= n; i++)
			vis[i] = 0;
		ct = 1, vis[1] = 1, nw = mid;
		while (ct < n) {
			int flag = 0;
			for (int i = 1; i <= n; i++)
				fr[i] = 0;
			for (int i = 1; i <= n; i++)
				if (vis[i] && dfs(i, 0, nw)) {
					flag = 1;
					break;
				}
			if (!flag) break;
		}
		if (ct == n) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", r);
}

int T;

int main() {
	for (scanf("%d", &T); T; T--) solve();
	return 0;
}