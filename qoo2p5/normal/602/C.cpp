#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-10
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

int n, m;
ll g[500][500];
ll dist[500][500];

void floyd(int f) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				dist[i][j] = LINF;
			}

			if (g[i][j] == f) {
				dist[i][j] = 1;
			}
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;

		g[u][v] = 1;
		g[v][u] = 1;
	}

	if (g[0][n - 1]) {
		floyd(0);
		if (dist[0][n - 1] == LINF) {
			cout << "-1\n";
		} else {
			cout << dist[0][n - 1] << "\n";
		}
	} else {
		floyd(1);
		if (dist[0][n - 1] == LINF) {
			cout << "-1\n";
		} else {
			cout << dist[0][n - 1] << "\n";
		}
	}

    return 0;
}