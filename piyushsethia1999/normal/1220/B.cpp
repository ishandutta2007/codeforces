#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define int long long
#define se second
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int a[n][n];
	int s = 0;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) 
			cin >> a[i][j];
	for (int i = 1; i < n - 1; ++i) {
		a[i][i] = (a[i][0] * a[i][n - 1]) / a[0][n - 1];
	}
	a[0][0] = a[0][1] * a[n - 1][0] / a[1][n - 1];
	a[n - 1][n - 1] = a[n - 1][1] * a[n - 1][0] / a[0][1];
	for (int i = 0; i < n; ++i) {
		cout << sqrtl(a[i][i]) << " ";
	}
}