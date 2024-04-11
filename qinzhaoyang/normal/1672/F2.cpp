	#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int T, n, a[N], b[N], c[N], vis[N], ins[N];
vector<int> G[N];

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n); int mx = 0;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), c[a[i]]++;
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (int i = 1; i <= n; i++) if (c[mx] < c[i]) mx = i;
		for (int i = 1; i <= n; i++) c[a[i]]--, G[i].clear(), vis[i] = ins[i] = 0;
		for (int i = 1; i <= n; i++) if (a[i] != mx && b[i] != mx) G[a[i]].push_back(b[i]);
		function <int(int)> dfs;
		dfs = [&](int x) ->int {
			for (int v : G[x]) {
				if (ins[v]) return 1;
				if (vis[v]) continue;
				vis[v] = 1, ins[v] = 1;
				int ret = dfs(v); ins[v] = 0;
				if (ret) return 1;
			}
			return 0;
		};
		int ok = 0;
		for (int i = 1; i <= n; i++)
			ins[i] = 1, vis[i] = 1, ok |= dfs(i), ins[i] = 0;
		puts(ok ? "WA" : "AC");
	}
	return 0;
}