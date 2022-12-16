#include <bits/stdc++.h>

int N, K;
int deg[110000], leaf[110000];
std::vector <int> edge[110000];
bool vis[110000];
std::vector <int> st[2];

int main () {
	scanf ("%d%d", &N, &K);
	for (int i = 1; i <= N - 1; ++i) {
		int u, v; scanf ("%d%d", &u, &v);
		edge[u].push_back (v); edge[v].push_back (u); ++deg[u]; ++deg[v];
	}
	for (int i = 1; i <= N; ++i) if (deg[i] == 1) vis[i] = true, leaf[i] = 3, st[0].push_back (i);
	int t = 0, ok = 0;
	while (!st[t & 1].empty ()) {
		st[t & 1 ^ 1].clear ();
		for (int u : st[t & 1]) if (leaf[u] < 3) { puts ("No"); return 0; }
		for (int u : st[t & 1]) vis[u] = true;
		if (st[t & 1].size () == 1) { ok = 1; break; }
		for (int u : st[t & 1]) if (deg[u] != 1) { puts ("No"); return 0; }
		for (int u : st[t & 1]) for (int n : edge[u]) if (!vis[n]) st[t & 1 ^ 1].push_back (n), ++leaf[n], --deg[n];
		std::sort (st[t & 1 ^ 1].begin (), st[t & 1 ^ 1].end ());
		st[t & 1 ^ 1].resize (std::unique (st[t & 1 ^ 1].begin (), st[t & 1 ^ 1].end ()) - st[t & 1 ^ 1].begin ());
		++t;
	}
	for (int i = 1; i <= N; ++i) if (!vis[i]) { puts ("No"); return 0; }
	if (t == K && ok) puts ("Yes");
	else puts ("No");
}