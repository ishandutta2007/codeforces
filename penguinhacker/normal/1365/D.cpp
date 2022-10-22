#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int n, m;
string g[50];
bool vis[50][50];

void dfs(int i, int j) {
	assert(g[i][j]!='B');
	vis[i][j]=1;
	for (int k=0; k<4; ++k) {
		int a=i+dx[k], b=j+dy[k];
		if (a<0||a>=n||b<0||b>=m)
			continue;
		if (!vis[a][b]&&(g[a][b]=='.'||g[a][b]=='G'))
			dfs(a, b);
	}
}

void solve() {
	memset(vis, 0, sizeof(vis));
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> g[i];
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (g[i][j]=='B') {
				for (int k=0; k<4; ++k) {
					int a=i+dx[k], b=j+dy[k];
					if (a<0||a>=n||b<0||b>=m)
						continue;
					if (g[a][b]=='G') {
						cout << "NO\n";
						return;
					}
					if (g[a][b]=='.')
						g[a][b]='#';
				}
			}
	if (g[n-1][m-1]!='#')
		dfs(n-1, m-1);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (g[i][j]=='G'&&!vis[i][j]) {
				cout << "NO\n";
				return;
			}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/