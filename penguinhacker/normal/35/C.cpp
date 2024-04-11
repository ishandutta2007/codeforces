#include <bits/stdc++.h>
using namespace std;

#define ll long long
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int n, m, k;
bool visited[2000][2000];
pair<int, int> last;

queue<pair<int, int>> q;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	memset(visited, 0, sizeof(visited));
	cin >> n >> m >> k;
	for (int i=0, x, y; i<k; ++i) {
		cin >> x >> y, x--, y--;
		visited[x][y] = 1;
		q.push({x, y});
	}

	while (!q.empty()) {
		pair<int, int> curr = q.front(); q.pop();
		last = curr;
		for (int dir=0; dir<4; ++dir) {
			int a=curr.first+dx[dir], b=curr.second+dy[dir];
			if (a>=0&&a<n&&b>=0&&b<m&&!visited[a][b]) {
				visited[a][b] = 1;
				q.push({a, b});
			}
		}
	}
	cout << last.first+1 << ' ' << last.second+1;
	return 0;
}