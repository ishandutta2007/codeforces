#include <bits/stdc++.h>
using namespace std;

char s[300010], t[300010];
int fa[300010], sz[300010];
int ans[300010];
int n;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return ;
	fa[x] = y, sz[y] += sz[x];
}

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s);
		for (int it = 0; it < 2; it++) {
			for (int i = 0; i <= n; i++) {
				fa[i] = i, sz[i] = 1;
			}
			for (int i = 0; i < n; i++) {
				if ((i & 1) == it) {
					if (s[i] == 'R') merge(i, i + 1);
				} else {
					if (s[i] == 'L') merge(i, i + 1);
				}
			}
			for (int i = 0; i <= n; i++) {
				if ((i & 1) == it) ans[i] = sz[find(i)];
			}
		}
		for (int i = 0; i <= n; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}