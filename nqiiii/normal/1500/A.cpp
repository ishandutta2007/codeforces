#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5, maxv = 5e6;
int n, p;
int a[maxn + 10], b[maxn + 10], cnt;
int ia[maxv + 10], ib[maxv + 10];
vector<int> g[maxv + 10];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		g[a[i]].push_back(i);
	}
	for (int i = 1; i <= maxv; ++i)
		if (g[i].size() >= 4) {
			printf("YES\n");
			printf("%d %d %d %d\n", g[i][0], g[i][1], g[i][2], g[i][3]);
			return 0;
		} else if (g[i].size() >= 2) {
			if (!p) p = i;
			else {
				printf("YES\n");
				printf("%d %d %d %d\n", g[p][0], g[i][0], g[p][1], g[i][1]);
				return 0;
			}
		} 
	if (p) {
		for (int i = 1; i < p * 2; ++i)
			if (i != p) {
				if (g[i].size() && g[p * 2 - i].size()) {
					printf("YES\n");
					printf("%d %d %d %d\n", g[i][0], g[p * 2 - i][0], g[p][0], g[p][1]);
					return 0;
				}
			}
	}
	for (int i = 1; i <= maxv; ++i)
		if (g[i].size()) {
			b[++cnt] = g[i][0];
		}
	for (int i = 1; i <= cnt; ++i)
		for (int j = i + 1; j <= cnt; ++j) {
			int v = a[b[i]] + a[b[j]];
			if (ia[v]) {
				printf("YES\n");
				printf("%d %d %d %d\n", b[i], b[j], ia[v], ib[v]);
				return 0;
			} else {
				ia[v] = b[i]; ib[v] = b[j];
			}
		}
	printf("NO");
}