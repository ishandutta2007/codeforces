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

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int occ[104] = {};
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		int a; cin >> a;
		occ[a] = 1;
	}
	int ii = 0;
	for (int i = 1; i < 101; ++i) {
		if (occ[i]) {
			ii++;
			for (int j = i; j < 101; j += i) {
				occ[j] = 0;
			}
		}
	}
	cout << ii;
}