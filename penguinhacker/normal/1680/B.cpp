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
		int n, m;
		cin >> n >> m;
		int a=69696969, b=69696969;
		vector<string> g(n);
		for (int i=0; i<n; ++i) {
			cin >> g[i];
			for (int j=0; j<m; ++j) {
				if (g[i][j]=='R') {
					a=min(a, i);
					b=min(b, j);
				}
			}
		}
		cout << (g[a][b]=='R'?"YES":"NO") << "\n";
	}
	return 0;
}