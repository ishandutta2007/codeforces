#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000000;
int t, n;
int p1, p2, ans;
vector<int> g[maxn + 10];

void dfs(int p, int fa, int d) {
	if (p == p2) ans = d;
	for (int i = 0; i < (int)g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fa) dfs(e, p, d ^ 1);
	}
}

bool solve() {
	int tot = 0;
	for (int i = 1; i <= n; ++i)
		if ((int)g[i].size() >= 4) return 1;
		else if ((int)g[i].size() == 3) {
			int cnt = 0;
			for (int j = 0; j < 3; ++j) {
				int e = g[i][j];
				if ((int)g[e].size() > 1) ++cnt;
			}
			if (cnt >= 2) return 1;
			++tot;
		}
	if (tot < 2) return 0;
	p1 = p2 = 0;
	for (int i = 1; i <= n; ++i)
		if ((int)g[i].size() == 3) {
			if (!p1) p1 = i;
			else p2 = i;
		}
	dfs(p1, 0, 1);
	return ans;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) g[i].clear();
		for (int i = 1; i < n; ++i) {
			int l, r; scanf("%d%d", &l, &r);
			g[l].push_back(r); g[r].push_back(l);
		}
		for (int i = 1, nn = n; i <= nn; ++i) {
			char c = getchar();
			while (!isgraph(c)) c = getchar();
			if (c == 'W') {
				g[++n].clear(); g[i].push_back(n); g[n].push_back(i);
				g[++n].clear(); g[n - 1].push_back(n); g[n].push_back(n - 1);
				g[++n].clear(); g[n - 2].push_back(n); g[n].push_back(n - 2);
			}
		}
		printf("%s\n", solve() ? "White" : "Draw");
	}
}