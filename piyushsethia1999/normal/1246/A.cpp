#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }
 
int c(int x) {
	if (x < 0) return 20000000;
	int cn = 0;
	for (int i = 0; i < 34; ++i) {
		if (x & (1ll << i)) {
			cn++;
		}
	}
	return cn;
}
 
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n, p;
	cin >> n >> p;
	if (n == 0) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 1; i <= 300000; ++i) {
		if(c(n - i * p) <= i && i <= (n - i * p)) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}