#include <bits/stdc++.h>

int N, M, Q;
std::pair <int, int> col[210000];
int last[210000], vis[210000];
std::vector <int> edge[210000];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> M >> Q;
	for (int i = 1; i <= Q; ++i) std::cin >> col[i].first >> col[i].second;
	std::sort (col, col + Q);
	for (int i = 1; i <= Q; ++i) {
		if (last[col[i].second] != 0) {
			int x = col[i].first, y = last[col[i].second];
			edge[x].push_back (y); edge[y].push_back (x);
		}
		last[col[i].second] = col[i].first;
	}
	int res = 0;
	for (int i = 1; i <= N; ++i) if (!vis[i]) {
		++res; std::queue <int> q; q.push (i); vis[i] = true;
		while (!q.empty ()) {
			int n = q.front (); q.pop ();
			for (int e : edge[n]) if (!vis[e]) {
				q.push (e); vis[e] = true;
			}
		}
	}
	for (int i = 1; i <= M; ++i) if (last[i] == 0) ++res;
	std::cout << res - 1 << "\n";
}