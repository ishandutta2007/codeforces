#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define ab {++ans; continue;}

int n, m, K, ans=0;
char a[100][100][100];
inline bool ok(int i, int j, int k) {return i>=0&&i<n&&j>=0&&j<m&&k>=0&&k<K&&a[i][j][k]=='1';}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> K;
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			for (int k=0; k<K; ++k)
				cin >> a[i][j][k];
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			for (int k=0; k<K; ++k) {
				if (a[i][j][k]=='0') continue;
				if (ok(i-1, j, k)&&ok(i+1, j, k)) ab
				if (ok(i, j-1, k)&&ok(i, j+1, k)) ab
				if (ok(i, j, k-1)&&ok(i, j, k+1)) ab
				if (ok(i-1, j, k)&&ok(i, j+1, k)&&!(ok(i-1, j+1, k))) ab
				if (ok(i-1, j, k)&&ok(i, j, k+1)&&!(ok(i-1, j, k+1))) ab
				if (ok(i, j-1, k)&&ok(i+1, j, k)&&!(ok(i+1, j-1, k))) ab
				if (ok(i, j-1, k)&&ok(i, j, k+1)&&!(ok(i, j-1, k+1))) ab
				if (ok(i, j, k-1)&&ok(i+1, j, k)&&!(ok(i+1, j, k-1))) ab
				if (ok(i, j, k-1)&&ok(i, j+1, k)&&!(ok(i, j+1, k-1))) ab
			}
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/