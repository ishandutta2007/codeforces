#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array
int di[4]={1,-1,0,0}, dj[4]={0,0,1,-1};

int n, m, visited[50][50];
string s[50];
vector<pair<int, int>> adj[50][50];
bool cyc=0;

void fill(int i, int j) {
	if (visited[i][j]) {
		cyc=1;
		return;
	}
	visited[i][j]=1;
	while (!adj[i][j].empty()) {
		pair<int, int> x=adj[i][j].back(); adj[i][j].pop_back();
		int a=x.first, b=x.second;
		adj[a][b].erase(find(adj[a][b].begin(), adj[a][b].end(), make_pair(i,j)));
		fill(a,b);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(visited, 0, sizeof(visited));
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> s[i];
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			for (int dir=0; dir<4; ++dir) {
				int a=i+di[dir], b=j+dj[dir];
				if (a<0||a>=n||b<0||b>=m)
					continue;
				if (s[i][j]==s[a][b])
					adj[i][j].emplace_back(a,b);
			}
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			if (!visited[i][j]&&!cyc)
				fill(i,j);
		}
	}
	cout << (cyc?"Yes":"No");
	return 0;
}