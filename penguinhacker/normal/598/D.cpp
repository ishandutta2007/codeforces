#include <bits/stdc++.h>
using namespace std;

int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

string s[1000]; //the grid
int n, m, q;
bool visited[1000][1000];
vector<pair<int, int>> adj[1000][1000];

int cmp[1000][1000]; //which component is room i,j in
int roomSize[1000000]; //num visible paintings

void fill(int i, int j, int room) {
	if (visited[i][j])
		return;
	visited[i][j] = 1;
	cmp[i][j] = room;
	roomSize[room] += 4-adj[i][j].size();
	for (pair<int, int> x:adj[i][j]) {
		fill(x.first, x.second, room);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	for (int i=1; i<n-1; ++i) {
		for (int j=1; j<m-1; ++j) {
			if (s[i][j]=='*')
				continue;
			for (int dir=0; dir<4; ++dir) {
				int a=i+dx[dir], b=j+dy[dir];
				if (s[a][b]=='.')
					adj[i][j].push_back({a, b});
			}
		}
	}
	
	int curr = 0;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (s[i][j]=='.'&&!visited[i][j]) {
				fill(i, j, curr);
				curr++;
			}
		}
	}

	while(q--) {
		int i, j;
		cin >> i >> j, i--, j--;
		cout << roomSize[cmp[i][j]] << '\n';
	}
	return 0;
}