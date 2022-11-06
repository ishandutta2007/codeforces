#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	int a[501][501];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) cin >> a[i][j];
	}
	int u = -1, v = -1;
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < n; ++j) {
			int t[2] = {};
			for (int k = 0; k < m; ++k) {
				t[!(!(a[j][k] & (1 << i)))]++; 
			}
			if (t[0] && t[1]) {
				u = j;
				v = i;
			} 
		}
	}
	if (u != -1) {
		std::vector<int> v1(n, 0);
		int uu = 0;
		for (int i = 0; i < n; ++i) {
			if (u != i) {
				uu ^= a[i][v1[i]];
			} 
		}
		if (uu & (1 << v)) {
			for (int j = 0; j < m; ++j) {
				if (!(a[u][j] & (1 << v))) {
					v1[u] = j;
				} 
			}
		} else {
			for (int j = 0; j < m; ++j) {
				if ((a[u][j] & (1 << v))) {
					v1[u] = j;
				} 
			}
		}
		cout << "TAK\n";
		for (int i = 0; i < n; ++i) {
			cout << v1[i] + 1 << " ";
		}
	} else {
		std::vector<int> v1(n);
		int uu = 0;
		for (int i = 0; i < n; ++i) {
			v1[i] = 0;
			uu ^= a[i][v1[i]];
		}
		if (uu == 0) {
			cout << "NIE\n";
		} else {
			cout << "TAK\n";
			for (int i = 0; i < n; ++i) {
				cout << v1[i] + 1 << ' ';
			}
		}
	}
}