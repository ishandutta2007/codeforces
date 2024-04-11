#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;
vector<string> g;
vector<vector<bool>> vis, vis2;

bool ok(int i, int j, vector<vector<bool>>& v) {
	return 0<=i&&0<=j&&i<n&&j<m&&!v[i][j]&&g[i][j]=='.';
}

void dfs1(int i=0, int j=0) {
	vis[i][j]=1;
	if (ok(i+1, j, vis))
		dfs1(i+1, j);
	if (ok(i, j+1, vis))
		dfs1(i, j+1);
}

void dfs2(int i=n-1, int j=m-1) {
	vis2[i][j]=1;
	if (ok(i-1, j, vis2))
		dfs2(i-1, j);
	if (ok(i, j-1, vis2))
		dfs2(i, j-1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	g.resize(n);
	vis=vis2=vector<vector<bool>>(n, vector<bool>(m));
	for (string& s : g)
		cin >> s;
	dfs1();
	dfs2();
	if (!vis[n-1][m-1]) {
		cout << 0;
		return 0;
	}
	vector<int> cnt(n+m);
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cnt[i+j]+=vis[i][j]&&vis2[i][j];
	for (int i=1; i<n+m-2; ++i) {
		assert(cnt[i]);
		if (cnt[i]==1) {
			cout << 1;
			return 0;
		}
	}
	cout << 2;
	return 0;
}