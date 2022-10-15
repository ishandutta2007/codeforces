#include <iostream>
#include <vector>

using namespace std;

#define INF 1222333444

int n, m;
int a[1111], b[1111];
int p[1111], p2[1111];
int w[1111], w2[1111];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		int x = 0;
		for (int j = 1; j <= k; j++) {
			int u;
			cin >> u;
			x |= (1<<u-1);
		}
		a[x]++;
	}
	for (int x = 0; x < (1<<9); x++) {
		for (int y = 0; y < (1<<9); y++) {
			if ((y&x) == y) b[x] += a[y];
		}
	}
	for (int x = 0; x < (1<<9); x++) p[x] = p2[x] = INF;
	for (int i = 1; i <= m; i++) {
		int u, k;
		cin >> u >> k;
		int x = 0;
		for (int j = 1; j <= k; j++) {
			int u;
			cin >> u;
			x |= (1<<u-1);
		}
		if (u <= p[x]) {
			p2[x] = p[x];
			w2[x] = w[x];
			p[x] = u;
			w[x] = i;
		} else if (u <= p2[x]) {
			p2[x] = u;
			w2[x] = i;
		}
	}
	vector<int> r = {-1,0,0,0};
	for (int x = 0; x < (1<<9); x++) {
		for (int y = 0; y < (1<<9); y++) {
			if (x == y) {
				if (p2[x] == INF) continue;
				r = max(r,{b[x|y],-(p[x]+p2[x]),w[x],w2[x]});
			} else {
				if (p[x] == INF || p[y] == INF) continue;
				r = max(r,{b[x|y],-(p[x]+p[y]),w[x],w[y]});
			}
		}
	}
	cout << r[2] << " " << r[3] << "\n";
}