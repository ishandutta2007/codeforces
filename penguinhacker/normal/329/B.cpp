#include <bits/stdc++.h>
using namespace std;

int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

string grid[1000];
int n, m;
int si, sj, ei, ej; //start, end pos

int dist[1000][1000];
bool visited[1000][1000]={};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<n; ++i) {
		cin >> grid[i];
		for (int j=0; j<m; ++j) {
			if (grid[i][j]=='S') {
				si = i; sj = j;
			}
			else if (grid[i][j]=='E') {
				ei = i; ej = j;
			}
		}
	}
	
	memset(dist, 0x3f, sizeof(dist));
	dist[ei][ej] = 0;
	visited[ei][ej] = 1;
	queue<pair<int, int>> q;
	q.push({ei, ej});
	while (!q.empty()) {
		pair<int, int> curr = q.front(); q.pop();
		int i=curr.first, j=curr.second;
		for (int dir=0; dir<4; ++dir) {
			int a=i+dx[dir], b=j+dy[dir];
			if (!(a>=0&&a<n&&b>=0&&b<m&&!visited[a][b]))
				continue;
			if (grid[a][b]!='T') {
				visited[a][b] = 1;
				dist[a][b] = dist[i][j]+1;
				q.push({a, b});
			}
		}
	}
	
	int ans = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if ('0'<grid[i][j]&&grid[i][j]<='9'&&dist[i][j]<=dist[si][sj])
				ans += (grid[i][j]-'0');
		}
	}
	cout << ans;
	return 0;
}