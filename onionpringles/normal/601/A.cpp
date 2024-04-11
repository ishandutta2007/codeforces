#pragma warning(disable:4996)
#include <stdio.h>

#include <vector>
#include <algorithm>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

const int mod = 1000000007;
const int inf = 1000000000;

vector<int> adj[400];
int dist[400][400];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int findf = 0;
	for (auto &x : adj[0]) {
		if (x == n - 1) {
			findf = 1;
			break;
		}
	}
	if (findf) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if(i!=j)dist[i][j] = 1;
				else dist[i][i] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (auto &x : adj[i]) {
				dist[i][x] =inf;
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) dist[i][i] = 0;
				else dist[i][j] = inf;
			}
		}
		for (int i = 0; i < n; i++) {
			for (auto &x : adj[i]) {
				dist[i][x] = 1;
			}
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j]>dist[i][k] + dist[j][k]) {
					dist[i][j] = dist[i][k] + dist[j][k];
				}
			}
		}
	}
	if (dist[0][n-1] == inf) {
		printf("%d", -1);
	}
	else {
		printf("%d", dist[0][n - 1]);
	}
	return 0;
}