#include <cstdio>
#include <queue>
#include <cstdlib>

const int N = 500;

int n, m;
bool adj[N][N];
char c[N];
bool vis[N];

int main () {
	scanf ("%d %d", &n, &m);
	
	int u, v;
	for (int i=0; i<m; i++) {
		scanf ("%d %d", &u, &v);
		u--, v--;
		
		adj[u][v] = adj[v][u] = 1;
	}
	
	for (int i=0; i<n; i++) {
		if (vis[i]) continue;
		
		std :: queue <int> q;
		q.push (i);
		vis[i] = 1;
		c[i] = 'a';
		int cnt = 0;
		
		while (q.size()) {
			int now = q.front();
			q.pop();
			
			for (int i=0; i<n; i++) {
				if (i == now) continue;
				if (adj[now][i]) continue;
				
				if (vis[i]) {
					if (c[i] == c[now]) return 0 * printf ("No\n");
					continue;
				}
				vis[i] = 1;
				
				q.push(i);
				if (c[now] == 'a') c[i] = 'c';
				else c[i] = 'a';
				cnt++;
			}
		}
		
		if (cnt == 0) c[i] = 'b';
	}
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (adj[i][j] && abs (c[i] - c[j]) > 1) return 0 * printf ("No\n");
		}
	}
	
	printf ("Yes\n");
	for (int i=0; i<n; i++) printf ("%c", c[i]);
	printf ("\n");
	
	return 0;
}