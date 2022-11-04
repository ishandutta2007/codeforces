#include <iostream>
#include <vector>

#define INF 1 << 30

struct edge {
	int from, to, weight;
};

using namespace std;

int n, m;
long long g[500][500];
long long d[500][500];
int in_edges[500][500];
vector<edge> edges;

void input() {
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			g[i][j] = INF;
			d[i][j] = INF;
		}
	}
	for(int i = 0; i < m; i++) {
		int x, y, l;
		cin >> x >> y >> l;
		x--;
		y--;

		g[x][y] = l;
		g[y][x] = l;
		d[x][y] = l;
		d[y][x] = l;

		edges.push_back({x, y, l});
	}
}

void floyd() {
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	input();
	floyd();

	for(int from = 0; from < n; from++) {
		for(edge e : edges) {
			if(d[from][e.from] + e.weight == d[from][e.to]) {
				in_edges[from][e.to]++;
			}
			if(d[from][e.to] + e.weight == d[from][e.from]) {
				in_edges[from][e.from]++;
			}
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			int ans = 0;

			for(int k = 0; k < n; k++) {
				if(d[i][k] + d[k][j] == d[i][j]) {
					ans += in_edges[i][k];
				}
			}

			cout << ans << " ";
		}
	}

	cout << endl;

	return 0;
}