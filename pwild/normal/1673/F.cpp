#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> a(n, vector<int>(n));
	for (int j = 1; j < n; j++) {
		int k = __builtin_ctz(j);
		a[0][j] = a[0][j-1] ^ (1 << (2*k));
	}
	for (int i = 1; i < n; i++) {
		int k = __builtin_ctz(i);
		for (int j = 0; j < n; j++) {
			a[i][j] = a[i-1][j] ^ (2 << (2*k));
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			cout << (a[i][j] ^ a[i][j+1]) << " \n"[j+2==n];
		}
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n; j++) {
			cout << (a[i][j] ^ a[i+1][j]) << " \n"[j+1==n];
		}
	}
	cout << flush;

	vector<pair<int,int>> pos(1024, {-1,-1});
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pos[a[i][j]] = {i,j};
		}
	}

	int y = 0;
	while (k--) {
		int x; cin >> x;
		y ^= x;
		auto [i,j] = pos[y];
		cout << i+1 << ' ' << j+1 << endl;
	}
}