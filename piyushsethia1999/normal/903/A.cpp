#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int poss[201];
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int t; cin >> t;
	poss[0] = 1;
	for (int i = 0; i < 120; ++i) {
		if (poss[i]) {
			poss[i + 3] = 1;
			poss[i + 7] = 1;
		}
	}
	while (t--) {
		int x; cin >> x;
		cout << (poss[x] ? "YES\n" : "NO\n");
	}
}