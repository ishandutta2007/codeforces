#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define next(p) ((p) == n - 1 ? 0 : ((p) + 1))

int main()
{
#ifdef _MSC_VER
	freopen("d.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>> g(n, vector<int>(n, -1));
		for (int i = 0; i < m; ++i) {
			int a, b, c;
			cin >> a >> b >> c;
			g[a][b] = c;
		}
		vector<vector<int>> q(n);
		for (int start = 0; start < n; ++start) {
			int base = 2e9;
			for (int i = 0; i < n; ++i) {
				if (g[start][i] >= 0) {
					base = min(base, g[start][i]);
				}
			}
			vector<int> d(n, 2e9);
			for (int i = 0; i < n; ++i) {
				q[i].clear();
			}
			auto add = [&](int p, int new_d) {
				assert(new_d >= base);
				if (new_d >= base + n) {
					return;
				}
				if (new_d < d[p]) {
					d[p] = new_d;
					q[new_d - base].push_back(p);
				}
			};
			d[start] = 0;
			for (int i = 0; i < n; ++i) {
				if (g[start][i] >= 0) {
					add(i, g[start][i]);
					if (i == start) {
						add(next(i), g[start][i] + 1);
					}
				}
			}
			vector<int> v(n);
			for (int offset = 0; offset < n; ++offset) {
				for (int cur : q[offset]) {
					if (v[cur]) {
						continue;
					}
					v[cur] = 1;
					int w = d[cur];
					add(next(cur), w + 1);
					if (next(cur) == start) {
						add(next(next(cur)), w + 2);
					}

					int p = w % n;
					for (int i = 0; i < n; ++i) {
						if (g[cur][i] >= 0) {
							add(p, w + g[cur][i]);
							if (p == start) {
								add(next(p), w + g[cur][i] + 1);
							}
						}
						p = next(p);
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				printf("%d ", d[i]);
			}
			printf("\n");
		}
	}
	return 0;
}