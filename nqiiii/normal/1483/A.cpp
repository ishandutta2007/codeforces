#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
int T, n, m, lim;
vector<int> g[maxn + 10];
int cnt[maxn + 10], ans[maxn + 10];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		int lim = (m + 1) / 2;
		for (int i = 1; i <= m; ++i) g[i].clear();
		for (int i = 1; i <= n; ++i) cnt[i] = 0;
		for (int i = 1; i <= m; ++i) {
			int k; scanf("%d", &k);
			while (k--) {
				int x; scanf("%d", &x);
				g[i].push_back(x);
			}
		}
		for (int i = 1; i <= m; ++i)
			if (g[i].size() == 1) {
				++cnt[g[i][0]];
				ans[i] = g[i][0];
			}	
		for (int i = 1; i <= m; ++i)
			if (g[i].size() > 1) {
				if (cnt[g[i][0]] < cnt[g[i][1]]) {
					++cnt[g[i][0]];
					ans[i] = g[i][0];
				} else {
					++cnt[g[i][1]];
					ans[i] = g[i][1];
				}
			}
		bool fd = 0;
		for (int i = 1; i <= n; ++i)
			if (cnt[i] > lim) fd = 1;
		if (fd) {
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1; i <= m; ++i)
			printf("%d%c", ans[i], " \n"[i == m]);
	}
}