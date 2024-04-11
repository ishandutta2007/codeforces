#include <iostream>

#define N 110

using namespace std;

int group[N][N];
int n, m;

int G(int *g, int u) {
	return (u == g[u] ? u : g[u] = G(g, g[u]));
}
void merge(int *g, int a, int b) {
	if(G(g, a) == G(g, b)) {
		return;
	}
	g[g[b]] = g[a];
}
int main() {
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		for(int j = 1;j <= n;j++) {
			group[i][j] = j;
		}
	}
	for(int i = 1;i <= m;i++) {
		int a, b, c;
		cin >> a >> b >> c;
		merge(group[c], a, b);
	}
	int q;
	cin >> q;
	while(q--) {
		int u, v;
		cin >> u >> v;
		int ans = 0;
		for(int i = 1;i <= m;i++) {
			ans += G(group[i], u) == G(group[i], v);
		}
		cout << ans << endl;
	}			
	return 0;
}