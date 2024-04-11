#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[300010][8];
int vis[1 << 8];
int xx, yy;

bool check(int x) {
	memset(vis, -1, sizeof(vis));
	for (int i = 0; i < n; i++) {
		int mask = 0;
		for (int j = 0; j < m; j++) {
			if (a[i][j] >= x) mask |= 1 << j;
		}
		vis[mask] = i;
	}
	for (int i = 0; i < (1 << m); i++) {
		for (int j = 0; j < (1 << m); j++) {
			if (~vis[i] && ~vis[j] && (i | j) == (1 << m) - 1) {
				xx = vis[i], yy = vis[j];
				return 1;
			}
		}
	}
	return 0;
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int l = 0, r = 1000000000;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
		else r = mid - 1;
	}
	check(l);
	printf("%d %d\n", xx + 1, yy + 1);
	return 0;
}