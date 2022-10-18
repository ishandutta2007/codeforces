#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;

	vector<int> p(n);
	iota(begin(p), end(p), 0);

	vector<vector<int>> a(n, vector<int>(n));
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n; i++) {
			a[p[i]][p[n-1-i]] = k;
		}
		rotate(begin(p)+1, begin(p)+2, end(p));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " \n"[j+1==n];
		}
	}
}