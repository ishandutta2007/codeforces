#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, p[500], a[500][500];

void dfs(int i, int j, int x, int& l) {
	assert(!a[i][j]);
	a[i][j]=x, --l;
	if (l&&i+1<n&&!a[i+1][j])
		dfs(i+1, j, x, l);
	if (l&&j&&!a[i][j-1])
		dfs(i, j-1, x, l);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> p[i];
	for (int i=n-1; ~i; --i) {
		dfs(i, i, p[i], p[i]);
		assert(!p[i]);
	}
	for (int i=0; i<n; ++i) {
		for (int j=0; j<=i; ++j)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	return 0;
}