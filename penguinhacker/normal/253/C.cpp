#include <bits/stdc++.h>
using namespace std;

#define ll long long
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int n, a[101], dist[101][100002];
bool visited[101][100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n;
	for (int i=1; i<=n; ++i)
		cin >> a[i], a[i]++;
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	
	memset(visited, 0, sizeof(visited));
	dist[r1][c1] = 0;
	visited[r1][c1] = 1;
	queue<pair<int, int>> q;
	q.push({r1, c1});
	while (!q.empty()) {
		pair<int, int> curr = q.front(); q.pop();
		int i=curr.first, j=curr.second;
		for (int dir=0; dir<4; ++dir) {
			int x=i+dx[dir], y=j+dy[dir];
			if (x<1||x>n||y<1)
				continue;
			if (y>a[x])
				y = a[x];
			if (!visited[x][y]) {
				visited[x][y] = 1;
				dist[x][y] = dist[i][j]+1;
				q.push({x, y});
			}
		}
	}
	cout << dist[r2][c2];
	return 0;
}