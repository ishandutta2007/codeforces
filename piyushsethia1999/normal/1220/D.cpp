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

int c(int a) {
	int i = 0;
	while (!(a & 1)) {
		i++;
		a >>= 1;
	}
	return i;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int a[n];
	int b[n];
	int cn[65] = {};
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = c(a[i]);
		cn[b[i]]++;
	}
	int ii = 0;
	for (int i = 0; i < 65; ++i) {
		if (cn[ii] < cn[i]) {
			ii = i;
		} 
	}
	cout << n - cn[ii] << "\n";
	for (int i = 0; i < n; ++i) {
		if (b[i] != ii) {
			cout << a[i] << " ";
		} 
	}
}