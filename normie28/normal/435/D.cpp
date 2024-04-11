#include <bits/stdc++.h>
using namespace std;
 
int n, m;
int grid[405][405];
int h[405][405], v[405][405], d[405][405], b[405][405];
 
bool bad(int r1, int c1, int r2, int c2) {
	if (r1 < 0 || c1 < 0 || r1 >= n || c1 >= m) return true;
	if (r2 < 0 || c2 < 0 || r2 >= n || c2 >= m) return true;
	return false;
}
 
bool hh(int r1, int c1, int r2, int c2) {
	if (bad(r1, c1, r2, c2)) return false;
	int ret = h[r2][c2] - (c1 > 0 ? h[r1][c1 - 1] : 0);
	return ret == 0;
}
 
bool vv(int r1, int c1, int r2, int c2) {
	if (bad(r1, c1, r2, c2)) return false;
	int ret = v[r2][c2] - (r1 > 0 ? v[r1 - 1][c1] : 0);
	return ret == 0;
}
 
bool dd(int r1, int c1, int r2, int c2) {
	if (bad(r1, c1, r2, c2)) return false;
	int ret = d[r2][c2] - (r1 > 0 && c1 > 0 ? d[r1 - 1][c1 - 1] : 0);
	return ret == 0;
}
 
bool bb(int r1, int c1, int r2, int c2) {
	if (bad(r1, c1, r2, c2)) return false;
	int ret = b[r2][c2] - (r1 > 0 && c1 + 1 < m ? b[r1 - 1][c1 + 1] : 0);
	return ret == 0;
}
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) grid[i][j] = s[j] - '0';
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		h[i][j] = (j > 0 ? h[i][j - 1] : 0) + grid[i][j];
		v[i][j] = (i > 0 ? v[i - 1][j] : 0) + grid[i][j];
		d[i][j] = (i > 0 && j > 0 ? d[i - 1][j - 1] : 0) + grid[i][j];
		b[i][j] = (i > 0 && j + 1 < m ? b[i - 1][j + 1] : 0) + grid[i][j];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 1; k <= min(i, j); k++) {
		if (hh(i, j - k, i, j) && vv(i - k, j - k, i, j - k) && dd(i - k, j - k, i, j)) ans++;
		if (hh(i, j - k, i, j) && vv(i - k, j, i, j) && bb(i - k, j, i, j - k)) ans++;
		if (hh(i - k, j - k, i - k, j) && vv(i - k, j, i, j) && dd(i - k, j - k, i, j)) ans++;
		if (hh(i, j - k - k, i, j) && dd(i - k, j - k, i, j) && bb(i - k, j - k, i, j - k - k)) ans++;
		if (vv(i - k - k, j, i, j) && dd(i - k, j - k, i, j) && bb(i - k - k, j, i - k, j - k)) ans++;
	}
	for (int i = n - 1; i >= 0; i--) for (int j = m - 1; j >= 0; j--) for (int k = 1; k < min(n - i, m - j); k++) {
		if (hh(i, j, i, j + k) && vv(i, j, i + k, j) && bb(i, j + k, i + k, j)) ans++;
		if (hh(i, j, i, j + k + k) && dd(i, j, i + k, j + k) && bb(i, j + k + k, i + k, j + k)) ans++;
		if (vv(i, j, i + k + k, j) && dd(i, j, i + k, j + k) && bb(i + k, j + k, i + k + k, j)) ans++;
	}
	cout << ans << endl;
}