#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[300][300];

void solve() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			cin >> a[i][j];
	if (a[0][0]>2||a[n-1][0]>2||a[0][m-1]>2||a[n-1][m-1]>2) {
		cout << "NO\n"; return;
	}
	for (int i=1; i<n-1; ++i)
		if (a[i][0]>3||a[i][m-1]>3) {
			cout << "NO\n"; return;
		}
	for (int i=1; i<m-1; ++i)
		if (a[0][i]>3||a[n-1][i]>3) {
			cout << "NO\n"; return;
		}
	for (int i=1; i<n-1; ++i)
		for (int j=1; j<m-1; ++j)
			if (a[i][j]>4) {
				cout << "NO\n"; return;
			}
	cout << "YES\n";
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			bool b=(i==0||i==n-1), b2=(j==0||j==m-1);
			if (b&&b2) cout << 2;
			else if (b^b2) cout << 3;
			else cout << 4;
			cout << ' ';
		}
		cout << '\n';
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

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/