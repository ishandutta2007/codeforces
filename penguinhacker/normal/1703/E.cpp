#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<string> g(n);
		for (auto& i : g)
			cin >> i;
		vector<vector<bool>> vis(n, vector<bool>(n));
		int ans=0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (vis[i][j])
					continue;
				map<char, int> mp;
				for (int rep=0; rep<4; ++rep) {
					if (!vis[i][j]) {
						++mp[g[i][j]];
						vis[i][j]=1;
					}
					int ni=n-1-j;
					j=i, i=ni;
				}
				int best=0, sum=0;
				for (auto y : mp) {
					sum+=y.second;
					best=max(best, y.second);
				}
				ans+=sum-best;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}