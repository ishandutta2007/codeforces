#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	vector<vector<bool>> vis(n, vector<bool>(m));
	vector<ar<int, 3>> v;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j) {
			cin >> a[i][j];
			v.push_back({a[i][j], i, j});
		}
	sort(v.begin(), v.end());
	int cnt=0;
	vector<vector<int>> ans(n, vector<int>(m));
	for (ar<int, 3> x : v) {
		int i=x[1], j=x[2];
		if (vis[i][j])
			continue;
		vis[i][j]=1;
		ans[i][cnt]=x[0];
		for (int i1=0; i1<n; ++i1) {
			if (i1==i)
				continue;
			int best=-1;
			for (int j1=0; j1<m; ++j1)
				if (!vis[i1][j1]&&(best==-1||a[i1][j1]>a[i1][best]))
					best=j1;
			assert(best^-1);
			vis[i1][best]=1;
			ans[i1][cnt]=a[i1][best];
		}
		++cnt;
	}
	for (int i=0; i<n; ++i) {
		for (int j : ans[i])
			cout << j << " ";
		cout << "\n";
	}
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