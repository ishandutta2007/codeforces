#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
const char dir[4]={'U', 'R', 'D', 'L'};

const int mxN=1000;
int n;
char ans[mxN][mxN];
bool vis[mxN][mxN];
ar<int, 2> g[mxN][mxN];

bool ok(int i, int j) {return i>=0&&i<n&&j>=0&&j<n;}

void dfs(ar<int, 2> u) {
	vis[u[0]][u[1]]=1;
	for (int i=0; i<4; ++i) {
		int a=u[0]+dx[i], b=u[1]+dy[i];
		if (ok(a, b)&&!vis[a][b]&&g[u[0]][u[1]]==g[a][b]) {
			ans[a][b]=dir[(i+2)%4];
			dfs({a, b});
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			for (int k=0; k<2; ++k) {
				cin >> g[i][j][k];
				if (g[i][j][k]!=-1) {
					--g[i][j][k];
				}
			}
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (vis[i][j]) {
				continue;
			}
			if (g[i][j]==ar<int, 2>{-1, -1}) {
				for (int k=0; k<4; ++k) {
					int a=i+dx[k], b=j+dy[k];
					if (ok(a, b)&&!vis[a][b]&&g[a][b]==ar<int, 2>{-1, -1}) {
						ans[i][j]=dir[k];
						dfs({i, j});
						break;
					}
				}
			}
			else if (g[i][j]==ar<int, 2>{i, j}) {
				ans[i][j]='X';
				dfs({i, j});
			}
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			if (ans[i][j]==0) {
				cout << "INVALID";
				return 0;
			}
		}
	}
	cout << "VALID\n";
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/