#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long
#define ld long double
int gcd(int a, int b) {
	return (!b ? a : gcd(b, a % b));
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int testcases; cin >> testcases;
	while (testcases --> 0) {
		string s, t; cin >> s >> t;
		string tt, ss;
		int n = s.size(), m = t.size();
		int d = n * m / gcd(n, m);
		while (tt.size() != d) tt += t;
		while (ss.size() != d) ss += s;
		cout << (ss == tt ? ss : "-1") << '\n';

	}
	return 0;
}