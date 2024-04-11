#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int a[160000];

int flr(int x) {
	if (x < 0) {
		x--;
	} 
	return x / 2;
}

int cei(int x) {
	if (x > 0) {
		x++;
	}
	return x / 2;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int cn = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] & 1) {
			if (cn) {
				cout << flr(a[i]) << "\n";
			} else {
				cout << cei(a[i]) << "\n";
			}
			cn ^= 1;
		} else {
			cout << a[i] / 2 << "\n";
		}
	}
}