#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=500, INF=1e9;
int n, m, k, dp[mxN][mxN][11];
vector<ar<int, 3>> adj[mxN][mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	if (k&1) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j)
				cout << "-1 ";
			cout << "\n";
		}
		return 0;
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m-1; ++j) {
			int x;
			cin >> x;
			adj[i][j].push_back({i, j+1, x});
			adj[i][j+1].push_back({i, j, x});
		}
	}
	for (int i=0; i<n-1; ++i) {
		for (int j=0; j<m; ++j) {
			int x;
			cin >> x;
			adj[i][j].push_back({i+1, j, x});
			adj[i+1][j].push_back({i, j, x});
		}
	}
	for (int k2=1; k2<=k/2; ++k2) {
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				dp[i][j][k2]=1e9;
				for (ar<int, 3> a : adj[i][j])
					dp[i][j][k2]=min(dp[i][j][k2], dp[a[0]][a[1]][k2-1]+a[2]);
			}
		}
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j)
			cout << 2*dp[i][j][k/2] << " ";
		cout << "\n";
	}
	return 0;
}