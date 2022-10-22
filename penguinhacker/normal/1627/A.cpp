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
		int n, m, r, c;
		cin >> n >> m >> r >> c, --r, --c;
		vector<string> g(n);
		for (string& s : g)
			cin >> s;
		if (g[r][c]=='B') {
			cout << "0\n";
			continue;
		}
		bool ok=0;
		for (int i=0; i<m; ++i)
			ok|=g[r][i]=='B';
		for (int i=0; i<n; ++i)
			ok|=g[i][c]=='B';
		if (ok) {
			cout << "1\n";
			continue;
		}
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				ok|=g[i][j]=='B';
		cout << (ok?2:-1) << "\n";
	}
	return 0;
}