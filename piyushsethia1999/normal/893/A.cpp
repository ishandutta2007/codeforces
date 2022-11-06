#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int np = 3;
	for (int i = 0; i < n; ++i) {
		int c; cin >> c;
		if (c == np) {
			cout << "NO\n";
			return 0;
		} else {
			np = 6 - c - np;
		}
	}
	cout << "YES\n";
}