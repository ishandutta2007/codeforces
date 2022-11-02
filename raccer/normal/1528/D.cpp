#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

const int INF = 0x3f3f3f3f;

typedef pair <int, int> pii;
typedef pair <int, pii> ppp;

int G[610][610];
int dist[610][610], D[610][610], tmp[610];
priority_queue <pii, vector <pii>, greater <pii> > q;

int main() {
	memset(G, 0x3f, sizeof(G));
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		G[a][b] = c;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = INF;
			for (int k = 0; k < n; k++) dist[i][j] = min(dist[i][j], k + G[i][(j - k + n) % n]);
		}
		for (int j = 0; j < n + n; j++) tmp[j] = dist[i][j % n];
		for (int j = 1; j < n + n; j++) tmp[j] = min(tmp[j], tmp[j - 1] + 1);
		for (int j = 0; j < n; j++) dist[i][j] = tmp[j + n];
	}
	memset(D, 0x3f, sizeof(D));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			D[i][j] = dist[i][j], q.push(mp(D[i][j], i * n + j));
		}
	}
	while (!q.empty()) {
		pii t = q.top(); q.pop();
		int x = t.se / n, y = t.se % n;
		if (D[x][y] != t.fi) continue;
		for (int i = 0; i < n; i++) {
			int w = D[x][y] + dist[y][(i - D[x][y] % n + n) % n];
			if (D[x][i] > w) D[x][i] = w, q.push(mp(D[x][i], x * n + i));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%d ", i == j ? 0 : D[i][j]); printf("\n");
	}
	return 0;
}