#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int n, m, t, d[1000][1000];
string g[1000];
queue<pair<int, int>> q;

bool ok(int i, int j) {
	return i>=0&&i<n&&j>=0&&j<m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> t;
	for (int i=0; i<n; ++i) {
		cin >> g[i];
		for (int j=0; j<m; ++j)
			d[i][j]=-1;
	}
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			for (int k=0; k<4; ++k) {
				int a=i+dx[k];
				int b=j+dy[k];
				if (ok(a, b)&&g[i][j]==g[a][b]) {
					d[i][j]=0;
					q.emplace(i, j);
					break;
				}
			}
	while(!q.empty()) {
		int i=q.front().first, j=q.front().second;
		q.pop();
		for (int k=0; k<4; ++k) {
			int a=i+dx[k], b=j+dy[k];
			if (ok(a, b)&&d[a][b]==-1) {
				d[a][b]=d[i][j]+1;
				q.emplace(a, b);
			}
		}
	}
	while(t--) {
		ll i, j, p;
		cin >> i >> j >> p, --i, --j;
		if (d[i][j]==-1) cout << g[i][j] << '\n';
		else if (p<=d[i][j]) cout << g[i][j] << '\n';
		else cout << (g[i][j]-'0'+p-d[i][j])%2 << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/