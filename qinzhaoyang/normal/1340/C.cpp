#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10, M = 1010;

struct Node {
	int x, y;
};

int n, m, d[N], g, red, dis[N][M];
Node q[20000010]; int l, r;

void upd(int x, int y, int c, int typ) {
	if (c < dis[x][y]) {
		dis[x][y] = c;
		if (typ) q[++r] = (Node){x, y};
		else q[--l] = (Node){x, y};
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &d[i]);
	scanf("%d%d", &g, &red);
	sort(d + 1, d + m + 1);
	memset(dis, 0x3f, sizeof dis);
	dis[1][0] = 0;
	l = 10000000, r = 9999999;
	q[++r] = (Node){1, 0};
	while (l <= r) {
		int x = q[l].x, y = q[l].y; l++;
		if (x != 1) {
			int fuk = y + (d[x] - d[x - 1]);
			if (fuk <= g) upd(x - 1, fuk % g, dis[x][y] + fuk / g, fuk / g);
		}
		if (x != m) {
			int fuk = y + (d[x + 1] - d[x]);
			if (fuk <= g) upd(x + 1, fuk % g, dis[x][y] + fuk / g, fuk / g);
		}
	}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < g; i++) {
		if (dis[m][i] == 0x3f3f3f3f) continue;
		int t = (g + red) * dis[m][i] + i;
		if (i == 0) t -= red;
		ans = min(ans, t);
	}
	if (ans == 0x3f3f3f3f) puts("-1");
	else printf("%d\n", ans);
	return 0;
}