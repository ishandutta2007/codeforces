#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	ll ans=0;
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=m; ++j)
			ans+=(i==j?4*i-2:4*min(i, j)-1)-1;
	vector<vector<bool>> vis(n, vector<bool>(m));
	while(q--) {
		int a, b;
		cin >> a >> b, --a, --b;
		int cur=-1;
		for (ar<int, 2> inc : {ar<int, 2>{0, 1}, ar<int, 2>{1, 0}}) {
			ar<int, 2> dir=inc;
			int x=0;
			for (int i=a, j=b; !x||(i<n&&j<m&&!vis[i][j]); ++x, i+=dir[0], j+=dir[1], swap(dir[0], dir[1]));
			int y=0;
			dir={-inc[1], -inc[0]};
			for (int i=a, j=b; !y||(~i&&~j&&!vis[i][j]); ++y, i+=dir[0], j+=dir[1], swap(dir[0], dir[1]));
			cur+=x*y;
		}
		ans+=cur*(vis[a][b]?1:-1);
		vis[a][b]=!vis[a][b];
		cout << ans << "\n";
	}
	return 0;
}