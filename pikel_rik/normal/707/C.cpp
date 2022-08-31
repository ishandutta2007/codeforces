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

	ll n;
	cin >> n;

	if (n < 3) {
		cout << "-1\n";
		return 0;
	}

	ll pw = 1;
	while (n % 2 == 0) {
		n /= 2;
		pw *= 2;
	}


	if (n == 1) {
		tuple<ll, ll, ll> base {3, 4, 5};
		while (get<1>(base) < n * pw) {
			get<0>(base) *= 2;
			get<1>(base) *= 2;
			get<2>(base) *= 2;
		}
		cout << get<0>(base) << ' ' << get<2>(base) << '\n';
		return 0;
	} else {
		tuple<ll, ll, ll> base;
		get<0>(base) = n;
		get<1>(base) = (n * n) / 2;
		get<2>(base) = (n * n + 1) / 2;

		while (get<0>(base) < n * pw) {
			get<0>(base) *= 2;
			get<1>(base) *= 2;
			get<2>(base) *= 2;
		}
		cout << get<1>(base) << ' ' << get<2>(base) << '\n';
	}
	return 0;
}