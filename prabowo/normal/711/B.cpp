#include <bits/stdc++.h>
using namespace std;

int n, x, y;
long long a[505][505], sum = 0;

int main () {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 0) x = i, y = j;
		}
	}
	
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	
	for (int i = 0; i < n; i++) sum += a[(x + 1) % n][i];
	long long ans = sum;
	
	for (int i = 0; i < n; i++) ans -= a[x][i];
	
	if (ans <= 0) {
		cout << -1 << endl;
		return 0;
	}
	
	a[x][y] = ans;
	long long sums = 0;
	
	for (int i = 0; i < n; i++) sums += a[i][i];
	if (sums != sum) {
		cout << -1 << endl;
		return 0;
	}
	
	sums = 0;
	for (int i = 0; i < n; i++) sums += a[i][n - i - 1];
	if (sums != sum) {
		cout << -1 << endl;
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		sums = 0;
		// vertical
		for (int j = 0; j < n; j++) sums += a[i][j];
		if (sums != sum) {
			cout << -1 << endl;
			return 0;
		}
		// horizontal
		sums = 0;
		for (int j = 0; j < n; j++) sums += a[j][i];
		if (sums != sum) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	cout << ans << endl;
	return 0;
}