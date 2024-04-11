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
	int d = 0; bool is = (n % 400 == 0 || (n % 100 != 0 && n % 4 == 0));
	do {
		if (n % 400 == 0 || (n % 100 != 0 && n % 4 == 0)) {
			d += 2;
		} else {
			d++;
		} 
		n++;
		d %= 7;
	} while(d != 0 || ((n % 400 == 0 || (n % 100 != 0 && n % 4 == 0)) != is));
	cout << n;
}