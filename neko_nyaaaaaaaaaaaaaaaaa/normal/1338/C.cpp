#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<long long> pl = {0, 2, 3, 1};

void solve() {
	long long n; cin >> n; n--;
	long long trip_ind = n/3;

	long long bits_pos = 0;
	long long bits_pls = 1;

	while (trip_ind >= bits_pls) {
		trip_ind -= bits_pls;
		bits_pls <<= 2;
		bits_pos += 2;
	}

	// convert trip_ind to base 4
	long long a = trip_ind, b = 0, c = 0;
	a |= (1LL << (bits_pos));
	b |= (1LL << (bits_pos + 1));

	for (int i = 0; i < bits_pos; i += 2) {
		int gf = 0;
		if (a & (1LL << i)) gf++;
		if (a & (1LL << (i+1))) gf += 2;

		b |= (pl[gf] << i); 
	}
	c = a^b;

	if (n % 3 == 0) cout << a << '\n';
	else if (n % 3 == 1) cout << b << '\n';
	else cout << c << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}