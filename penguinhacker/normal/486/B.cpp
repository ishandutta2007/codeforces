#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[100][100], b[100][100];
int row[100], col[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	fill(row, row + n, 1);
	fill(col, col + m, 1);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		cin >> b[i][j];
		row[i] &= b[i][j];
		col[j] &= b[i][j];
	}
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		a[i][j] = row[i] && col[j];
	}
	fill(row, row + n, 0);
	fill(col, col + m, 0);
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		row[i] |= a[i][j];
		col[j] |= a[i][j];
	}
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
		if ((row[i] | col[j]) != b[i][j]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << a[i][j] << " ";
		cout << "\n";
	}
	return 0;
}