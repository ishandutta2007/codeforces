#include <stdio.h>
#include <vector>

#define N 3010

using namespace std;

vector<int> adj[N];
int con[N][N];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 0;i < m;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		con[u][v] = 1;
		adj[u].push_back(v);
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(i == j) {
				continue;
			}
			int cnt = 0;
			for(int v : adj[i]) {
				if(v != i && v != j && con[i][v] && con[v][j]) {
					cnt++;
				}
			}
			ans += cnt * (cnt - 1) / 2;
		}
	}
	printf("%d\n", ans);
	return 0;
}