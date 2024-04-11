#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll x, s;
	cin >> x >> s;

	if (x > s || (s - x) % 2 != 0) {
		cout << "-1\n";
	} else if (x == s) {
		if (x == 0) {
			cout << 0 << '\n';
		} else {
			cout << 1 << '\n' << x << '\n';
		}
	} else if (x == 0) {
		cout << 2 << '\n' << s / 2 << ' ' << s / 2 << '\n';
	} else {
		if ((((s - x) / 2) & x) == 0) {
			cout << 2 << '\n' << x + (s - x) / 2 << ' ' << (s - x) / 2 << '\n';
		} else {
			cout << 3 << '\n' << x << ' ' << (s - x) / 2 << ' ' << (s - x) / 2 << '\n';
		}
	}
	return 0;
}