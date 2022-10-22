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
		vector<string> g(n);
		for (string& s : g)
			cin >> s;
		int r=-1, w=-1;
		bool ok=1;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (g[i][j]=='R') {
					int p=(i+j)%2;
					if (r^-1&&r^p) {
						ok=0;
						break;
					}
					r=p;
				}
				if (g[i][j]=='W') {
					int p=(i+j)%2;
					if (w^-1&&w^p) {
						ok=0;
						break;
					}
					w=p;
				}
			}
		}
		if (!ok||(w!=-1&&r!=-1&&w==r)) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		if (r==-1&&w==-1)
			r=0;
		if (r==-1)
			r=w^1;
		if (w==-1)
			w=r^1;
		for (int i=0; i<n; ++i)
			for (int j=0; j<m; ++j)
				if (g[i][j]=='.')
					g[i][j]=(i+j)%2==r?'R':'W';
		for (string& s : g)
			cout << s << "\n";
	}
	return 0;
}