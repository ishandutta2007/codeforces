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
 
int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1;
		return 0;
	} 
	int nn = n;
	int cn = 0;
	int pp;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			cn++;
			pp = i;
			while (n % i == 0) n /= i; 
		}
	}
	if (n != 1) {
		cn++;
		pp = n;
	}
	if (cn > 1) {
		cout << 1;
	} else {
		cout << pp << '\n';
	}
}