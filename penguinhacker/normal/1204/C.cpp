#include <bits/stdc++.h>
using namespace std;

int n, m, dist[101][101], p[1000000];
bool adj[101][101];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	string inUse;
	for (int i=1; i<=n; ++i) {
		cin >> inUse;
		for (int j=0; j<n; ++j) {
			adj[i][j+1] = (inUse[j]=='1');
		}
		for (int j=1; j<=n; ++j) {
			if (i==j)
				dist[i][j] = 0;
			else if (adj[i][j])
				dist[i][j] = 1;
			else
				dist[i][j] = 1000000;
		}
	}
	
	for (int k=1; k<=n; ++k) {
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
			}
		}
	}
	
	int ans = 2;
	cin >> m;
	for (int i=0; i<m; ++i) {
		cin >> p[i];
	}
	int curr = 0;
	vector<int> v;
	for (int i=1; i<m; ++i) {
		if (i-curr>dist[p[curr]][p[i]]) {
			ans++;
			v.push_back(p[i-1]);
			curr = i-1;
		}
	}
	cout << ans << '\n';
	cout << p[0] << ' ';
	for (int i:v)
		cout << i << ' ';
	cout << p[m-1];
	return 0;
}