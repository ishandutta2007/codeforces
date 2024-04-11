#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string.h>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;

vector<int> adj[1000000];
int avkey = 3;

char input[1001][1001];
int board[1000][1000];

int dist[3][1000000];
int vis[1000000];

void bfs(int i) {
	memset(vis, 0, sizeof(vis));
	dist[i][i] = 0;
	vis[i] = 1;
	queue<int> q;
	q.push(i);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (auto &v : adj[x]) {
			if (vis[v]) continue;
			dist[i][v] = dist[i][x] + 1;
			q.push(v);
			vis[v] = 1;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int m, n;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%s", input[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (input[i][j] == '#') continue;
			if (input[i][j] == '.') board[i][j] = avkey++;
			else {
				board[i][j] = input[i][j] - '1';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (input[i][j] == '#') continue;
			else {
				int curk = board[i][j];
				if (i > 0 && input[i - 1][j] != '#') {
					int k = board[i - 1][j]; adj[k].push_back(curk); adj[curk].push_back(k);
				}
				if (j > 0 && input[i ][j-1] != '#') {
					int k = board[i ][j-1]; adj[k].push_back(curk); adj[curk].push_back(k);
				}
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < avkey; j++) {
			dist[i][j] = 100000000;
		}
	}
	bfs(0); bfs(1); bfs(2);
	
	if (dist[0][1] == 100000000 || dist[0][2] == 100000000) {
		puts("-1"); return 0;
	}
	int _min = 300000000;
	for (int i = 0; i < avkey; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += dist[j][i];
		}
		_min = min(sum, _min);
	}
	printf("%d\n", _min-2);
	return 0;
}